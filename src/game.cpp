#include "game.h"

CGame::CGame()
{

	_store = new struct save;

	if(s3eSecureStorageGet(_store,sizeof(struct save)) == S3E_RESULT_SUCCESS)
	{
		control_select = _store->c;
		sound = _store->s;
		music = _store->m;
		vibration = _store->v;
		maze_select = _store->maze;
		resume_campiagn = _store->r_ca;
		resume_classic = _store->r_cl;
		highscore_ca = _store->h_ca;
		level_cl = _store->l_cl;
	}
	else
	{
		control_select = 1;
		sound = 1;
		music = 1;
		vibration = 1;
		maze_select = 0;
		resume_campiagn = 0;
		resume_classic = 0;
		highscore_ca = 10000;
		level_cl = 1;
	}

	page = 1;
	tutorial_show = 1;

	main_page_delay = 0;
	menu_trans = 0;

	slide_start_time = 0;
	isslide = false;

	for (int i = 0; i < 4; i++)
	{
		m_tem[i] = 0;
	}

	switch (music)
	{
		//case -1:
		case 1:
			s3eAudioPlay("Sound/bk_music_1.mp3",0);
			break;
		//case -2:
		case 2:
			s3eAudioPlay("Sound/bk_music_2.mp3",0);
			break;
		//case -3:
		case 3:
			s3eAudioPlay("Sound/bk_music_3.mp3",0);
			break;
	}
	/*if(music < 0)
	{
		s3eAudioSetInt(S3E_AUDIO_VOLUME,0);
	}
	else
	{
		s3eAudioSetInt(S3E_AUDIO_VOLUME,S3E_AUDIO_MAX_VOLUME);
	}*/

	g_speed = (int)(Iw2DGetSurfaceHeight()*0.05f);

	initialize();

	wall_rotate = 0;
	wall_max = 0;
	wall_init();

	food_init();
}

CGame::~CGame()
{
	if(START!=NULL)
	{
		for(var=0;var<block;var++)
		{
			b_dir = START;
			START = START->next;
			delete b_dir;
		}
		delete START;
	}

	_store->c = control_select;
	_store->s = sound;
	_store->m = music;
	_store->v = vibration;
	_store->maze = maze_select;
	_store->r_ca = resume_campiagn;
	_store->r_cl = resume_classic;
	_store->h_ca = highscore_ca;
	_store->l_cl = level_cl;
	
	s3eSecureStoragePut(_store,sizeof(struct save));
	s3eAudioStop();
	delete _store;
}

void CGame::Update()
{
	if(s3eDeviceGetInt(S3E_DEVICE_OS)==S3E_OS_ID_WP8 && music > 1)
	{
		switch (m_tem[0])
		{
			case 0:
				m_tem[1] = s3eAudioGetInt(S3E_AUDIO_POSITION);
				break;
			case 10:
				m_tem[2] = s3eAudioGetInt(S3E_AUDIO_POSITION);
				break;
			case 15:
				m_tem[3] = s3eAudioGetInt(S3E_AUDIO_POSITION);
				break;
		}
		m_tem[0]++;
		if(m_tem[0]==16 && m_tem[1]==m_tem[2] && m_tem[2]==m_tem[3])
		{
			s3eAudioPause();
			s3eAudioResume();
		}
		if (m_tem[0]==16)
		{
			m_tem[0]=0;
		}
		if(s3eAudioGetInt(S3E_AUDIO_DURATION)-s3eAudioGetInt(S3E_AUDIO_POSITION) <= 1000)
		{
			s3eAudioSetInt(S3E_AUDIO_POSITION,0);
		}
	}

	switch (page)
	{
		case 2:
			play_Page_Update();
			break;
		case -1:
			tutorial_update();
			break;
		default:
			if(menu_trans == 0 && main_page_delay == 0)
			{
				mainPageUpdate();
			}
			else if (main_page_delay != 0)
			{
				main_page_delay--;
			}
			break;
	}
}


void CGame::Render()
{
    Iw2DSurfaceClear(0xff00ff00);
	Iw2DSetColour(0xffffffff);
	
	switch (page)
	{
		case 2:
			play_Page();
			break;
		case -1:
			tutorial();
			break;
		default:
			if(menu_trans == 0)
			{
				mainPage();
			}
			else
			{
				menu_trans_draw();
			}
			break;
	}

	Iw2DSurfaceShow();
}

void CGame::initialize()
{
	k_size.x = k_size.y = Iw2DGetSurfaceWidth()*0.10f;
	k_show = 0;

	menu_button_size.y = Iw2DGetSurfaceHeight()*0.133f;
	menu_button_size.x = menu_button_size.y * 3.38f;

	control_button_size.x = control_button_size.y = Iw2DGetSurfaceWidth()*0.12f;

	b_size.x = (float)((int)(Iw2DGetSurfaceWidth()*0.02f));
	b_size.y = (float)((int)(Iw2DGetSurfaceHeight()*0.90f));
	length = (float)((int)(Iw2DGetSurfaceWidth()*0.94f));
	breadth = b_size.y;
		
	g_size.x = (float)((int)(breadth*0.0525f));
	g_size.y = (float)((int)(breadth*0.0525f));

	row = (int)(length/g_size.x);
	col = (int)(breadth/g_size.y);

	length = row*g_size.x;
	breadth = col*g_size.y;
	
	beg.x = (int)(Iw2DGetSurfaceWidth()*0.03f)-b_size.x;
	beg.y = (int)(Iw2DGetSurfaceHeight()*0.05f)-b_size.x;
	move.x = (float)((int)(Iw2DGetSurfaceWidth()*0.03f));
	move.y = (float)((int)(Iw2DGetSurfaceHeight()*0.05f));

	end.x = move.x+row*g_size.x;
	end.y = move.y+col*g_size.y;

	move.x = (float)((int)(Iw2DGetSurfaceWidth()*0.03f)) + g_size.x;
	move.y = (float)((int)(Iw2DGetSurfaceHeight()*0.05f)) + g_size.y;
	
	f_dir = 1;
	f_step = 0;
	f_Size = g_size;

	_score = 0;
	b_select = 0;
	c=0;
	block = 4;
	over = 0;

	for(var=0;var<block;var++)
	{
		if(var==0)
		{
			b_dir = END = START = new Direction;
			b_dir->dir = 1;
			b_dir->next = NULL;
		}
		else
		{
			b_dir = new Direction;
			b_dir->dir = 1;
			b_dir->next = NULL;
			END->next = b_dir;
			END = b_dir;
		}
	}
}

//--------------------------------------------------------------------------------------------------------
//-------------------------GamePlay Reset---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

void CGame::reset()
{
	move.x = (float)((int)(Iw2DGetSurfaceWidth()*0.03f)) + g_size.x;
	move.y = (float)((int)(Iw2DGetSurfaceHeight()*0.05f)) + g_size.y;
	a_move = CIwFVec2(0,0);

	food_init();

	b_select = 0;
	c=0;
	over = 0;
	_score = 0;
	
	for(var=0;var<block;var++)
	{
		b_dir = START;
		START = START->next;
		delete b_dir;
	}
	delete START;
	
	block = 4;

	for(var=0;var<block;var++)
	{
		if(var==0)
		{
			b_dir = END = START = new Direction;
			b_dir->dir = 1;
			b_dir->next = NULL;
		}
		else
		{
			b_dir = new Direction;
			b_dir->dir = 1;
			b_dir->next = NULL;
			END->next = b_dir;
			END = b_dir;
		}
	}
}

void CGame::wall_init()
{
	switch (maze_select)
	{
		case 0:
			break;
		case 1:
			for (int i = 0; i < row; i++)
			{
				w_position[i].x = (float)i;
				wall_max++;
				w_position[row+i].x = (float)i;
				wall_max++;
				w_position[i].y = 0;
				w_position[row+i].y = (float)(col-1);
			}
			for (int i = 1; i < col-1; i++)
			{
				w_position[wall_max].x = 0;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 1; i < col-1; i++)
			{
				w_position[wall_max].x = (float)(row-1);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			break;
		case 2:
			for (int i = 0; i < row/2-1; i++)
			{
				w_position[i].x = (float)i;
				w_position[i].y = 0;
				wall_max++;
			}
			for (int i = 0; i < row/2-1; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col-1);
				wall_max++;
			}
			for (int i = row/2+2; i < row; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = 0;
				wall_max++;
			}
			for (int i = row/2+2; i < row; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col-1);
				wall_max++;
			}
			for (int i = 1; i < col/2-1; i++)
			{
				w_position[wall_max].x = 0;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 1; i < col/2-1; i++)
			{
				w_position[wall_max].x = (float)(row-1);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = col/2+2; i < col-1; i++)
			{
				w_position[wall_max].x = 0;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = col/2+2; i < col-1; i++)
			{
				w_position[wall_max].x = (float)(row-1);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			break;
		case 3:
			for (int i = 5; i < row/2-1; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = 5;
				wall_max++;
			}
			for (int i = 5; i < row/2-1; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col-6);
				wall_max++;
			}
			for (int i = row/2+2; i < row-5; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = 5;
				wall_max++;
			}
			for (int i = row/2+2; i < row-5; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col-6);
				wall_max++;
			}
			for (int i = 5; i < col/2-1; i++)
			{
				w_position[wall_max].x = 5;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = col/2+2; i < col-6; i++)
			{
				w_position[wall_max].x = 5;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 5; i < col/2-1; i++)
			{
				w_position[wall_max].x = (float)(row-6);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = col/2+2; i < col-6; i++)
			{
				w_position[wall_max].x = (float)(row-6);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 5; i < row-5; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = 0;
				wall_max++;
			}
			for (int i = 5; i < row-5; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col-1);
				wall_max++;
			}
			for (int i = 5; i < col-5; i++)
			{
				w_position[wall_max].x = 0;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 5; i < col-5; i++)
			{
				w_position[wall_max].x = (float)(row-1);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			break;
		case 4:
			for (int i = 0; i < row; i++)
			{
				w_position[i].x = (float)i;
				wall_max++;
				w_position[row+i].x = (float)i;
				wall_max++;
				w_position[i].y = 0;
				w_position[row+i].y = (float)(col-1);
			}
			for (int i = 1; i < col/2-1; i++)
			{
				w_position[wall_max].x = 0;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 1; i < col/2-1; i++)
			{
				w_position[wall_max].x = (float)(row-1);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = col/2+2; i < col-1; i++)
			{
				w_position[wall_max].x = 0;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = col/2+2; i < col-1; i++)
			{
				w_position[wall_max].x = (float)(row-1);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 5; i < col-5; i++)
			{
				w_position[wall_max].x = 5;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 5; i < col-5; i++)
			{
				w_position[wall_max].x = (float)(row-6);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 5; i < row/2-1; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col/2);
				wall_max++;
			}
			for (int i = row/2+1; i < row-5; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col/2);
				wall_max++;
			}
			break;
		case 5:
			for (int i = 0; i < row/2-1; i++)
			{
				w_position[i].x = (float)i;
				w_position[i].y = 0;
				wall_max++;
			}
			for (int i = 0; i < row/2-1; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col-1);
				wall_max++;
			}
			for (int i = row/2+2; i < row; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = 0;
				wall_max++;
			}
			for (int i = row/2+2; i < row; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col-1);
				wall_max++;
			}
			for (int i = 1; i < col/2-1; i++)
			{
				w_position[wall_max].x = 0;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 1; i < col/2-1; i++)
			{
				w_position[wall_max].x = (float)(row-1);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = col/2+2; i < col-1; i++)
			{
				w_position[wall_max].x = 0;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = col/2+2; i < col-1; i++)
			{
				w_position[wall_max].x = (float)(row-1);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 5; i < row-5; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = 5;
				wall_max++;
			}
			for (int i = 5; i < row-5; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col-6);
				wall_max++;
			}
			for (int i = 5; i < col-5; i++)
			{
				w_position[wall_max].x = (float)(row/2);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			break;
		case 6:
			for (int i = 0; i < row/2; i++)
			{
				w_position[i].x = (float)i;
				w_position[i].y = 0;
				wall_max++;
			}
			for (int i = row/2+1; i < row; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col-1);
				wall_max++;
			}
			for (int i = 1; i < col/2; i++)
			{
				w_position[wall_max].x = 0;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = col/2+1; i < col-1; i++)
			{
				w_position[wall_max].x = (float)(row-1);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 5; i <row/2 ; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col-6);
				wall_max++;
			}
			for (int i = row/2+1; i < row-5; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = 5;
				wall_max++;
			}
			for (int i = col/2+1; i < col-6; i++)
			{
				w_position[wall_max].x = 5;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 5; i < col/2; i++)
			{
				w_position[wall_max].x = (float)(row-6);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			break;
		case 7:
			for (int i = 0; i < row; i++)
			{
				w_position[i].x = (float)i;
				wall_max++;
				w_position[row+i].x = (float)i;
				wall_max++;
				w_position[i].y = 0;
				w_position[row+i].y = (float)(col-1);
			}
			for (int i = 1; i < col/2-1; i++)
			{
				w_position[wall_max].x = (float)(row-1);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = col/2+1; i < col-1; i++)
			{
				w_position[wall_max].x = 0;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 0; i < row/2-5; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col/2+1);
				wall_max++;
			}
			for (int i = row/2+6; i < row; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col/2-1);
				wall_max++;
			}
			break;
		case 8:
			for (int i = 0; i < row-5; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = 0;
				wall_max++;
			}
			for (int i = 1; i < col; i++)
			{
				w_position[wall_max].x = 0;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 0; i < col-5; i++)
			{
				w_position[wall_max].x = (float)(row-1);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 5; i < row-1; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col-6);
				wall_max++;
			}
			for (int i = 5; i < col-5; i++)
			{
				w_position[wall_max].x = 5;
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 1; i < col/2; i++)
			{
				w_position[wall_max].x = (float)(row-6);
				w_position[wall_max].y = (float)i;
				wall_max++;
			}
			for (int i = 5; i < row/2+5; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = 5;
				wall_max++;
			}
			for (int i = row/2-5; i < row-5; i++)
			{
				w_position[wall_max].x = (float)i;
				w_position[wall_max].y = (float)(col/2);
				wall_max++;
			}
			break;
	}
}

void CGame::food_init()
{
	flag = 0;
					do
					{
						f_Position.x = (float)(rand()%(int)(length/g_size.x));
						f_Position.y = (float)(rand()%(int)(breadth/g_size.y));
						temp = move;
						for(var=1, b_dir = START; var<block; var++,b_dir=b_dir->next)
						{
							if(b_dir->dir==1)
							{
								temp.x += g_size.x;
							}
							else if(b_dir->dir==-1)
							{
								temp.x -= g_size.x;
							}
							else if(b_dir->dir==2)
							{
								temp.y += g_size.y;
							}
							else
							{
								temp.y -= g_size.y;
							}
						
							if(temp.x>=end.x)
								temp.x = beg.x+b_size.x;
							else if(temp.x<beg.x+b_size.x)
								temp.x = end.x-g_size.x;
							if(temp.y>=end.y)
								temp.y = beg.y+b_size.x;
							else if(temp.y<beg.y+b_size.x)
								temp.y = end.y-g_size.y;

							if(((int)temp.x==(int)(beg.x+b_size.x+f_Position.x*g_size.x)) & ((int)temp.y == (int)(beg.y+b_size.x+f_Position.y*g_size.y)))
							{
								flag = 0;
								break;
							}
							else
							{
								flag = 1;
							}
						}
						for (int i = 0; i < wall_max; i++)
						{
							if(((int)(beg.x+b_size.x+w_position[i].x*g_size.x)==(int)(beg.x+b_size.x+f_Position.x*g_size.x)) & ((int)(beg.x+b_size.x+w_position[i].y*g_size.x) == (int)(beg.y+b_size.x+f_Position.y*g_size.y)))
							{
								flag = 0;
								break;
							}
							else
							{
								flag = 1;
							}
						}
					}while(flag==0);
}

CGame *newgame = 0;