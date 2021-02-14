#include "game.h"

CGame::CGame()
{
	play_Page_ini();
}

CGame::~CGame()
{
	if(START!=NULL)
	{
		for(i=0;i<block;i++)
		{
			b_dir = START;
			START = START->next;
			delete b_dir;
		}
		delete START;
	}
}

void CGame::Update()
{
	play_Page_Update();
}


void CGame::Render()
{
    Iw2DSurfaceClear(0xff00ff00);
	Iw2DSetColour(0xffffffff);
	
	play_Page();

	Iw2DSurfaceShow();
}

void CGame::play_Page_ini()
{
	k_size.x = k_size.y = Iw2DGetSurfaceWidth()*0.1f;

	b_size.x = (float)((int)(Iw2DGetSurfaceWidth()*0.02f));
	b_size.y = (float)((int)(Iw2DGetSurfaceHeight()*0.90f));
	length = (float)((int)(Iw2DGetSurfaceWidth()*0.94f));
	breadth = b_size.y;
		
	g_size.x = (float)((int)(breadth*0.05f));
	g_size.y = (float)((int)(breadth*0.05f));

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
		
	f_Position.x = (float)(rand()%(int)(length/g_size.x));
	f_Position.y = (float)(rand()%(int)(breadth/g_size.y));
	f_dir = 1;

	f_Size = g_size;

	_score = 0;
	b_select = 0;
	c=0;
	block = 5;
	over = 0;

	for(i=0;i<block;i++)
	{
		if(i==0)
		{
			b_dir = END = START = new Direction;
			b_dir->dir = 2;
			b_dir->next = NULL;
		}
		else
		{
			b_dir = new Direction;
			b_dir->dir = 2;
			b_dir->next = NULL;
			END->next = b_dir;
			END = b_dir;
		}
	}
}

void CGame::play_Page_Update()
{
	if(s3eKeyboardGetState(s3eKeyBack) & S3E_KEY_STATE_PRESSED)
		{
			s3eDeviceRequestQuit();
		}

	if((s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN))
		{
			if((END->dir == 1 || END->dir == -1)  && over == 0)
			{
				if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f+Iw2DGetSurfaceWidth()*0.1f)
				{
					b_select = 1;
				}
				else if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f+Iw2DGetSurfaceWidth()*0.1f)
				{
					b_select = 2;
				}
			}
			else if((END->dir == 2 || END->dir == -2)  && over == 0)
			{
				if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2+Iw2DGetSurfaceWidth()*0.1f)
				{
					b_select = 3;
				}
				else if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f+2.0f*(Iw2DGetSurfaceWidth()*0.1f) && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+2.0f*(Iw2DGetSurfaceWidth()*0.1f)+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2+Iw2DGetSurfaceWidth()*0.1f)
				{
					b_select = 4;
				}
			}
			
			

			
		}

	if(c%15 == 0)
		{
			c++;
			if (b_select!=0)
			{
				switch(b_select)
				{
					case 1:
						END->dir = -2;
						break;
					case 2:
						END->dir = 2;
						break;
					case 3:
						END->dir = -1;
						break;
					case 4:
						END->dir = 1;
						break;
				}
				b_select = 0;
			}

			temp = move;
			for(i=1, b_dir = START; i<block-1; i++,b_dir=b_dir->next)
			{
				if(((int)a_move.x==(int)temp.x) & ((int)a_move.y == (int)temp.y))
				{
					over = 1;
					break;
				}

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
			}
			if(over == 0)
			{	
				switch(START->dir)
				{
					case 1:
						if(move.x<end.x-g_size.x)
							move.x+=g_size.x;
						else move.x = beg.x+b_size.x;
						break;
					case -1:
						if(move.x>beg.x+b_size.x)
							move.x-=g_size.x;
						else move.x = end.x-g_size.x;
						break;
					case 2:	
						if(move.y<end.y-g_size.y)
							move.y+=g_size.y;
						else move.y = beg.y+b_size.x;
						break;
					case -2:
						if(move.y>beg.y+b_size.x)
							move.y-=g_size.y;
						else move.y = end.y-g_size.y;;
						break;
				}
				for(i=0, b_dir = START;i<block-1;i++,b_dir=b_dir->next)
				{
					b_dir->dir = b_dir->next->dir;
				}
				if(((int)a_move.x==(int)(beg.x+b_size.x+f_Position.x*g_size.x)) & ((int)a_move.y == (int)(beg.y+b_size.x+f_Position.y*g_size.y)))
				{
					block++;
					_score+=10;
					flag = 0;
					do
					{
						f_Position.x = (float)(rand()%(int)(length/g_size.x));
						f_Position.y = (float)(rand()%(int)(breadth/g_size.y));
						temp = move;
						for(i=1, b_dir = START; i<block; i++,b_dir=b_dir->next)
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
					}while(flag==0);

					b_dir = new Direction;
					b_dir->dir = END->dir;
					b_dir->next = NULL;
					END->next = b_dir;
					END = b_dir;
				}
			}
			}
			else if(c==20)
					{
						c++;
						switch (f_dir)
						{
							case 1:
								f_Position.x ++;
								if(f_Position.x >= row)
									f_Position.x = 0;
								if(rand()%100 > 60)
								{
									f_dir = 2;
								}
								else if(rand()%100 > 80)
								{
									f_dir = -2;
								}
								break;
							case -1:
								f_Position.x --;
								if(f_Position.x < 0)
									f_Position.x = (float)row-1;
								if(rand()%100 > 60)
								{
									f_dir = 2;
								}
								else if(rand()%100 > 80)
								{
									f_dir = -2;
								}
								break;
							case 2:
								f_Position.y ++;
								if(f_Position.y >= col)
									f_Position.y = 0;
								if(rand()%100 > 60)
								{
									f_dir = 1;
								}
								else if(rand()%100 > 80)
								{
									f_dir = -1;
								}
								break;
							case -2:
								f_Position.y --;
								if(f_Position.y < 0)
									f_Position.y = (float)col-1;
								if(rand()%100 > 60)
								{
									f_dir = 1;
								}
								else if(rand()%100 > 80)
								{
									f_dir = -1;
								}
								break;
						}
					}
			else
		{
			if(c<30)
				c++;
			else
			{
				c=1;
			}
			
		}
}

void CGame::play_Page()
{
	

	Iw2DDrawImage(getresource->get_bg(0),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));

	Iw2DSetColour(0x77ffffff);
	
	if((s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN))
	{
	k_pos.x = Iw2DGetSurfaceWidth()*0.7f + k_size.x;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*1.5f;
	Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(512,0),CIwFVec2(128,128));

	k_pos.x = Iw2DGetSurfaceWidth()*0.7f + k_size.x + k_size.x*0.5f;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f + k_size.x*0.5f + k_size.y*0.5f;
	rot.SetRot(PI,k_pos);
	Iw2DSetTransformMatrix(rot);

	k_pos.x = Iw2DGetSurfaceWidth()*0.7f + k_size.x;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f + k_size.x*0.5f;
	Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(512,0),CIwFVec2(128,128));

	k_pos.x = Iw2DGetSurfaceWidth()*0.7f + k_size.x*0.5f;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*0.5f + k_size.y*0.5f;
	rot.SetRot(3*PI/2,k_pos);
	Iw2DSetTransformMatrix(rot);

	k_pos.x = Iw2DGetSurfaceWidth()*0.7f;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*0.5f;
	Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(512,0),CIwFVec2(128,128));
	
	k_pos.x = Iw2DGetSurfaceWidth()*0.7f + 2*k_size.x + k_size.x*0.5f;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*0.5f + k_size.y*0.5f;
	rot.SetRot(PI/2,k_pos);
	Iw2DSetTransformMatrix(rot);

	k_pos.x = Iw2DGetSurfaceWidth()*0.7f + 2*k_size.x;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*0.5f;
	Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(512,0),CIwFVec2(128,128));

	Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
	}

	Iw2DSetColour(0xffffffff);
	Iw2DSetFont(getresource->get_font());
	sprintf(print,"SCORE : %.0f",_score);
	Iw2DDrawString(print,CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_RIGHT,IW_2D_FONT_ALIGN_CENTRE);

	Iw2DDrawImage(getresource->get_frame(),CIwFVec2(beg.x+b_size.x,beg.y+b_size.x),CIwFVec2(length,breadth));

	Iw2DDrawImageRegion(getresource->get_food(),CIwFVec2(beg.x+b_size.x+f_Position.x*g_size.x,beg.y+b_size.x+f_Position.y*g_size.y),f_Size,CIwFVec2(0,0),CIwFVec2(30,30));

	a_move = move;
	Iw2DDrawImageRegion(getresource->get_body(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));

	for(i=1, b_dir = START; i<block; i++,b_dir=b_dir->next)
	{
		if(b_dir->dir==1)
		{
			a_move.x += g_size.x;
		}
		else if(b_dir->dir==-1)
		{
			a_move.x -= g_size.x;
		}
		else if(b_dir->dir==2)
		{
			a_move.y += g_size.y;
		}
		else
		{
			a_move.y -= g_size.y;
		}
			
		if(a_move.x>=end.x)
			a_move.x = beg.x+b_size.x;
		else if(a_move.x<beg.x+b_size.x)
			a_move.x = end.x-g_size.x;
		if(a_move.y>=end.y)
			a_move.y = beg.y+b_size.x;
		else if(a_move.y<beg.y+b_size.x)
			a_move.y = end.y-g_size.y;
					if(i==block-1)
		{
			switch (b_dir->dir)
			{
				case 1:
					a_move = a_move + g_size/2;
					rot.SetRot(PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_head(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
					break;
				case -1:
					a_move = a_move + g_size/2;
					rot.SetRot(3*PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_head(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
					break;
				case 2:
					a_move = a_move + g_size/2;
					rot.SetRot(PI,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_head(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
					break;
				case -2:
					Iw2DDrawImageRegion(getresource->get_head(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					break;
			}
		}
		else
		{
			Iw2DDrawImageRegion(getresource->get_body(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
		}
	}
}

CGame *newgame = 0;


/*
//CIwFVec2 beg, g_size, b_size, move, a_move, end, temp;
//
//float length, breadth, _score, h_score[3];

//int b_select, i, flag, block, c, over, sound, sound_stat, resume, track, level, plank;
//int row, col;

char test[100], print[100];

struct _save
{
	int l , t , s;
	float hs[3];
}*store;

typedef struct node
{
	int dir;
	struct node *next;
}Direction;

Direction *START, *END, *b_dir;

CGame::CGame()
{
	/*IwResManagerInit();
	IwGetResManager()->LoadGroup("Iw2DStrings.group");
	
	

	bg_1 = Iw2DCreateImage("bg.png");
	ubutton_1 = Iw2DCreateImage("up_1.png");
	dbutton_1 = Iw2DCreateImage("down_1.png");
	lbutton_1 = Iw2DCreateImage("left_1.png");
	rbutton_1 = Iw2DCreateImage("right_1.png");
	frame_1 = Iw2DCreateImage("frame_1.png");
	food_1 = Iw2DCreateImage("food_1.png");
	head_u_1 = Iw2DCreateImage("head_1_up.png");
	head_d_1 = Iw2DCreateImage("head_1_down.png");
	head_l_1 = Iw2DCreateImage("head_1_left.png");
	head_r_1 = Iw2DCreateImage("head_1_right.png");
	body_1 = Iw2DCreateImage("body_1.png");

	bg_2 = Iw2DCreateImage("bg1.png");
	ubutton_2 = Iw2DCreateImage("up_2.png");
	dbutton_2 = Iw2DCreateImage("down_2.png");
	lbutton_2 = Iw2DCreateImage("left_2.png");
	rbutton_2 = Iw2DCreateImage("right_2.png");
	frame_2 = Iw2DCreateImage("frame_2.png");
	food_2 = Iw2DCreateImage("food_2.png");
	head_u_2 = Iw2DCreateImage("head_2_up.png");
	head_d_2 = Iw2DCreateImage("head_2_down.png");
	head_l_2 = Iw2DCreateImage("head_2_left.png");
	head_r_2 = Iw2DCreateImage("head_2_right.png");
	body_2 = Iw2DCreateImage("body_2.png");

	bg_3 = Iw2DCreateImage("bg2.png");
	ubutton_3 = Iw2DCreateImage("up_3.png");
	dbutton_3 = Iw2DCreateImage("down_3.png");
	lbutton_3 = Iw2DCreateImage("left_3.png");
	rbutton_3 = Iw2DCreateImage("right_3.png");
	frame_3 = Iw2DCreateImage("frame_3.png");
	food_3 = Iw2DCreateImage("food_3.png");
	head_u_3 = Iw2DCreateImage("head_3_up.png");
	head_d_3 = Iw2DCreateImage("head_3_down.png");
	head_l_3 = Iw2DCreateImage("head_3_left.png");
	head_r_3 = Iw2DCreateImage("head_3_right.png");
	body_3 = Iw2DCreateImage("body_3.png");

	bg_4 = Iw2DCreateImage("bg3.png");
	ubutton_4 = Iw2DCreateImage("up_4.png");
	dbutton_4 = Iw2DCreateImage("down_4.png");
	lbutton_4 = Iw2DCreateImage("left_4.png");
	rbutton_4 = Iw2DCreateImage("right_4.png");
	frame_4 = Iw2DCreateImage("frame_4.png");
	food_4 = Iw2DCreateImage("food_4.png");
	head_u_4 = Iw2DCreateImage("head_4_up.png");
	head_d_4 = Iw2DCreateImage("head_4_down.png");
	head_l_4 = Iw2DCreateImage("head_4_left.png");
	head_r_4 = Iw2DCreateImage("head_4_right.png");
	body_4 = Iw2DCreateImage("body_4.png");

	bg_5 = Iw2DCreateImage("bg4.png");
	ubutton_5 = Iw2DCreateImage("up_5.png");
	dbutton_5 = Iw2DCreateImage("down_5.png");
	lbutton_5 = Iw2DCreateImage("left_5.png");
	rbutton_5 = Iw2DCreateImage("right_5.png");
	frame_5 = Iw2DCreateImage("frame_5.png");
	food_5 = Iw2DCreateImage("food_5.png");
	head_u_5 = Iw2DCreateImage("head_5_up.png");
	head_d_5 = Iw2DCreateImage("head_5_down.png");
	head_l_5 = Iw2DCreateImage("head_5_left.png");
	head_r_5 = Iw2DCreateImage("head_5_right.png");
	body_5 = Iw2DCreateImage("body_5.png");

	sound_on = Iw2DCreateImage("sound_on.png");
	sound_off = Iw2DCreateImage("sound_off.png");
	setting = Iw2DCreateImage("settings.png");
	
	gravel = Iw2DCreateImage("gravel.png");
	spirit = Iw2DCreateImage("spirit.png");
	marine = Iw2DCreateImage("marine.png");
	airborne = Iw2DCreateImage("airborne.png");
	intergalactic = Iw2DCreateImage("intergalactic.png");

	track1 = Iw2DCreateImage("track1.png");
	track2 = Iw2DCreateImage("track2.png");
	track3 = Iw2DCreateImage("track3.png");

	panel = Iw2DCreateImage("panel.png");

	play = Iw2DCreateImage("start.png");
	pause = Iw2DCreateImage("pause.png");
	_resume = Iw2DCreateImage("resume.png");
	new_game = Iw2DCreateImage("new_game.png");

	high_scores = Iw2DCreateImage("high_scores.png");
	

	store = new struct _save;
	if(s3eSecureStorageGet(store,sizeof(struct _save)) == S3E_RESULT_SUCCESS)
	{
		level = store->l;
		for(i=0;i<3;i++)
		{
			h_score[i] = store->hs[i];
		}
		track = store->t;
		sound = store->s;
	}
	else
	{
		level = 1;
		sound = 1;
		track = 1;
		h_score[0] = 100;
		h_score[1] = 100;
		h_score[2] = 100;
	}
	

	switch (level)
	{
		case 1:
			bg = bg_1;

			ubutton = ubutton_1;
			dbutton = dbutton_1;
			lbutton = lbutton_1;
			rbutton = rbutton_1;

			frame = frame_1;
			food = food_1;

			head_u = head_u_1;
			head_d = head_d_1;
			head_l = head_l_1;
			head_r = head_r_1;

			body = body_1;
			break;
		case 2:
			bg = bg_2;

			ubutton = ubutton_2;
			dbutton = dbutton_2;
			lbutton = lbutton_2;
			rbutton = rbutton_2;

			frame = frame_2;
			food = food_2;

			head_u = head_u_2;
			head_d = head_d_2;
			head_l = head_l_2;
			head_r = head_r_2;

			body = body_2;
			break;
		case 3:
			bg = bg_3;

			ubutton = ubutton_3;
			dbutton = dbutton_3;
			lbutton = lbutton_3;
			rbutton = rbutton_3;

			frame = frame_3;
			food = food_3;

			head_u = head_u_3;
			head_d = head_d_3;
			head_l = head_l_3;
			head_r = head_r_3;

			body = body_3;
			break;
		case 4:
			bg = bg_4;

			ubutton = ubutton_4;
			dbutton = dbutton_4;
			lbutton = lbutton_4;
			rbutton = rbutton_4;

			frame = frame_4;
			food = food_4;

			head_u = head_u_4;
			head_d = head_d_4;
			head_l = head_l_4;
			head_r = head_r_4;

			body = body_4;
			break;
		case 5:
			bg = bg_5;

			ubutton = ubutton_5;
			dbutton = dbutton_5;
			lbutton = lbutton_5;
			rbutton = rbutton_5;

			frame = frame_5;
			food = food_5;

			head_u = head_u_5;
			head_d = head_d_5;
			head_l = head_l_5;
			head_r = head_r_5;

			body = body_5;
			break;
	}

	s3eAudioPlay("bk_music.mp3",0);
	
	sound_stat = 0;
	_score = 0;
	
	b_size.x = (float)((int)(Iw2DGetSurfaceWidth()*0.42f*0.046f));
	b_size.y = (float)((int)(Iw2DGetSurfaceWidth()*0.42f));
	length = (float)((int)(Iw2DGetSurfaceWidth()*0.65f));
	breadth = b_size.y;
		
	g_size.x = (float)((int)(breadth*0.05f));
	g_size.y = (float)((int)(breadth*0.05f));

	row = (int)(length/g_size.x);
	col = (int)(breadth/g_size.y);

	length = row*g_size.x;
	breadth = col*g_size.y;
	
	beg.x = (int)(Iw2DGetSurfaceWidth()*0.03f)-b_size.x;
	beg.y = (int)(Iw2DGetSurfaceHeight()*0.15f)-b_size.x;
	move.x = (float)((int)(Iw2DGetSurfaceWidth()*0.03f));
	move.y = (float)((int)(Iw2DGetSurfaceHeight()*0.15f));

	end.x = move.x+row*g_size.x;
	end.y = move.y+col*g_size.y;
		
	f_Position.x = (float)(rand()%(int)(length/g_size.x));
	f_Position.y = (float)(rand()%(int)(breadth/g_size.y));

	f_Size = g_size;

	b_select = 0;
	c=0;
	block = 5;
	over = -1;

	for(i=0;i<block;i++)
	{
		if(i==0)
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


CGame::~CGame()
{
	/*
	delete font1;
	IwGetResManager()->DestroyGroup("Iw2DStrings");
	IwResManagerTerminate();

	delete bg_1;
	delete ubutton_1;
	delete dbutton_1;
	delete lbutton_1;
	delete rbutton_1;
	delete food_1;
	delete frame_1;
	delete head_u_1;
	delete head_d_1;
	delete head_l_1;
	delete head_r_1;
	delete body_1;

	delete bg_2;
	delete ubutton_2;
	delete dbutton_2;
	delete lbutton_2;
	delete rbutton_2;
	delete food_2;
	delete frame_2;
	delete head_u_2;
	delete head_d_2;
	delete head_l_2;
	delete head_r_2;
	delete body_2;

	delete bg_3;
	delete ubutton_3;
	delete dbutton_3;
	delete lbutton_3;
	delete rbutton_3;
	delete food_3;
	delete frame_3;
	delete head_u_3;
	delete head_d_3;
	delete head_l_3;
	delete head_r_3;
	delete body_3;

	delete bg_4;
	delete ubutton_4;
	delete dbutton_4;
	delete lbutton_4;
	delete rbutton_4;
	delete food_4;
	delete frame_4;
	delete head_u_4;
	delete head_d_4;
	delete head_l_4;
	delete head_r_4;
	delete body_4;

	delete bg_5;
	delete ubutton_5;
	delete dbutton_5;
	delete lbutton_5;
	delete rbutton_5;
	delete food_5;
	delete frame_5;
	delete head_u_5;
	delete head_d_5;
	delete head_l_5;
	delete head_r_5;
	delete body_5;

	delete sound_on;
	delete sound_off;
	delete setting;

	delete panel;
	delete high_scores;

	delete gravel;
	delete spirit;
	delete marine;
	delete airborne;
	delete intergalactic;

	delete track1;
	delete track2;
	delete track3;

	delete play;
	delete pause;
	delete _resume;
	delete new_game;
	
	delete store;

	if(START!=NULL)
	{
		for(i=0;i<block;i++)
		{
			b_dir = START;
			START = START->next;
			delete b_dir;
		}
		delete START;
	}
}




void CGame::mainPage()
{
	Iw2DDrawImage(bg,CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
	
	Iw2DDrawImage(ubutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
	Iw2DDrawImage(dbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
	Iw2DDrawImage(lbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
	Iw2DDrawImage(rbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+2.0f*(Iw2DGetSurfaceWidth()*0.1f),Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
	
	if(sound == 1)
	{
		Iw2DDrawImage(sound_on,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f,Iw2DGetSurfaceHeight()*0.85f),CIwFVec2(Iw2DGetSurfaceWidth()*0.08f,Iw2DGetSurfaceWidth()*0.08f));
	}
	else if(sound == 0)
	{
		Iw2DDrawImage(sound_off,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f,Iw2DGetSurfaceHeight()*0.85f),CIwFVec2(Iw2DGetSurfaceWidth()*0.08f,Iw2DGetSurfaceWidth()*0.08f));
	}

	Iw2DDrawImage(setting,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+2*(Iw2DGetSurfaceWidth()*0.1f),Iw2DGetSurfaceHeight()*0.85f),CIwFVec2(Iw2DGetSurfaceWidth()*0.08f,Iw2DGetSurfaceWidth()*0.08f));
	
	Iw2DDrawImage(frame,CIwFVec2(beg.x+b_size.x,beg.y+b_size.x),CIwFVec2(length,breadth));

	if(over==0)
	{	
		Iw2DDrawImage(pause,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+(Iw2DGetSurfaceWidth()*0.1f),Iw2DGetSurfaceHeight()*0.85f),CIwFVec2(Iw2DGetSurfaceWidth()*0.08f,Iw2DGetSurfaceWidth()*0.08f));
		Iw2DSetColour(0xffffffff);
		Iw2DDrawImage(food,CIwFVec2(beg.x+b_size.x+f_Position.x*g_size.x,beg.y+b_size.x+f_Position.y*g_size.y),f_Size);

		a_move = move;
		Iw2DDrawImage(body,a_move,g_size);
		for(i=1, b_dir = START; i<block; i++,b_dir=b_dir->next)
		{
			if(b_dir->dir==1)
			{
				a_move.x += g_size.x;
			}
			else if(b_dir->dir==-1)
			{
				a_move.x -= g_size.x;
			}
			else if(b_dir->dir==2)
			{
				a_move.y += g_size.y;
			}
			else
			{
				a_move.y -= g_size.y;
			}
				
			if(a_move.x>=end.x)
				a_move.x = beg.x+b_size.x;
			else if(a_move.x<beg.x+b_size.x)
				a_move.x = end.x-g_size.x;
			if(a_move.y>=end.y)
				a_move.y = beg.y+b_size.x;
			else if(a_move.y<beg.y+b_size.x)
				a_move.y = end.y-g_size.y;

			if(i==block-1)
			{
				switch (b_dir->dir)
				{
					case 1:
						Iw2DDrawImage(head_r,a_move,g_size);
						break;
					case -1:
						Iw2DDrawImage(head_l,a_move,g_size);
						break;
					case 2:
						Iw2DDrawImage(head_d,a_move,g_size);
						break;
					case -2:
						Iw2DDrawImage(head_u,a_move,g_size);
						break;
				}
			}
			else
			{
				Iw2DDrawImage(body,a_move,g_size);
			}
		}


		Iw2DSetColour(0xffffffff);
		Iw2DSetFont(font1);
		sprintf(print,"SCORE : %.0f",_score);
		Iw2DDrawString(print,CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_RIGHT,IW_2D_FONT_ALIGN_CENTRE);
		sprintf(print,"HIGHSCORE : %.0f",h_score[0]);
		Iw2DDrawString(print,CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
	}
	else if(over == -1)
	{
		Iw2DDrawImage(play,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.15f/2,(beg.y+breadth+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.15f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.15f,Iw2DGetSurfaceWidth()*0.15f));
	}
	else if(over == -2)
	{
		Iw2DDrawImage(_resume,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.3f/2,beg.y+6*b_size.x),CIwFVec2(Iw2DGetSurfaceWidth()*0.3f,Iw2DGetSurfaceWidth()*0.3f*0.3f));
		Iw2DDrawImage(new_game,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.4f/2,beg.y+13*b_size.x),CIwFVec2(Iw2DGetSurfaceWidth()*0.4f,Iw2DGetSurfaceWidth()*0.4f*0.31f));
	}
	else
	{
		Iw2DDrawImage(panel, beg, CIwFVec2(length+2*b_size.x,breadth+2*b_size.x));

		Iw2DDrawString("GaME OVER",CIwFVec2(beg.x,beg.y+5*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
		Iw2DDrawString("YOUR SCORE IS",CIwFVec2(beg.x,beg.y+10*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
		sprintf(print,"%.0f",_score);
		Iw2DDrawString(print,CIwFVec2(beg.x,beg.y+15*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
	}

	if(resume == 1)
	{
		Iw2DDrawImage(panel, beg, CIwFVec2(length+2*b_size.x,breadth+2*b_size.x));

		switch (track)
		{
			case 1: 
				Iw2DDrawImage(track1,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.3f/2,beg.y+2*b_size.x),CIwFVec2(Iw2DGetSurfaceWidth()*0.3f,Iw2DGetSurfaceWidth()*0.3f*0.27f));
				break;
			case 2: 
				Iw2DDrawImage(track2,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.3f/2,beg.y+2*b_size.x),CIwFVec2(Iw2DGetSurfaceWidth()*0.3f,Iw2DGetSurfaceWidth()*0.3f*0.27f));
				break;
			case 3: 
				Iw2DDrawImage(track3,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.3f/2,beg.y+2*b_size.x),CIwFVec2(Iw2DGetSurfaceWidth()*0.3f,Iw2DGetSurfaceWidth()*0.3f*0.27f));
				break;
		}
		switch (level)
		{
			case 1:
				Iw2DDrawImage(gravel,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.3f/2,beg.y+10*b_size.x),CIwFVec2(Iw2DGetSurfaceWidth()*0.3f,Iw2DGetSurfaceWidth()*0.3f*0.3f));
				break;
			case 2:
				Iw2DDrawImage(spirit,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.3f/2,beg.y+10*b_size.x),CIwFVec2(Iw2DGetSurfaceWidth()*0.3f,Iw2DGetSurfaceWidth()*0.3f*0.33f));
				break;
			case 3:
				Iw2DDrawImage(marine,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.35f/2,beg.y+10*b_size.x),CIwFVec2(Iw2DGetSurfaceWidth()*0.35f,Iw2DGetSurfaceWidth()*0.35f*0.27f));
				break;
			case 4:
				Iw2DDrawImage(airborne,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.4f/2,beg.y+10*b_size.x),CIwFVec2(Iw2DGetSurfaceWidth()*0.4f,Iw2DGetSurfaceWidth()*0.4f*0.22f));
				break;
			case 5:
				Iw2DDrawImage(intergalactic,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.6f/2,beg.y+10*b_size.x),CIwFVec2(Iw2DGetSurfaceWidth()*0.6f,Iw2DGetSurfaceWidth()*0.6f*0.15f));
				break;
		}
		Iw2DDrawImage(high_scores,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.45f/2,beg.y+18*b_size.x),CIwFVec2(Iw2DGetSurfaceWidth()*0.45f,Iw2DGetSurfaceWidth()*0.45f*0.18f));
	}
	else if(resume == 2)
	{
		Iw2DDrawImage(panel, beg, CIwFVec2(length+2*b_size.x,breadth+2*b_size.x));
		Iw2DDrawImage(high_scores,CIwFVec2((beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.45f/2,beg.y+3*b_size.x),CIwFVec2(Iw2DGetSurfaceWidth()*0.45f,Iw2DGetSurfaceWidth()*0.45f*0.18f));
		
		sprintf(print,"I-	%.0f",h_score[0]);
		Iw2DDrawString(print,CIwFVec2(beg.x,beg.y+8*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
		sprintf(print,"II-	%.0f",h_score[1]);
		Iw2DDrawString(print,CIwFVec2(beg.x,beg.y+13*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
		sprintf(print,"III-	%.0f",h_score[2]);
		Iw2DDrawString(print,CIwFVec2(beg.x,beg.y+18*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
	}
}

void CGame::mainPageUpdate()
{
	if(over == 1)
	{
		if(s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN)
		{
			if(s3ePointerGetX()>=0 && 
				s3ePointerGetX()<=Iw2DGetSurfaceWidth() &&
				s3ePointerGetY()>=0 &&
				s3ePointerGetY()<=Iw2DGetSurfaceHeight())
			{
				if(_score>h_score[0])
				{
					h_score[2] = h_score[1];
					h_score[1] = h_score[0];
					h_score[0] = _score;
				}
				else if(_score>h_score[1])
				{
					h_score[2] = h_score[1];
					h_score[1] = _score;
				}
				else if(_score>h_score[2])
				{
					h_score[2] = _score;
				}
				reset();
			}
		}
	}
	else if(resume == 1)
	{
		if(s3eKeyboardGetState(s3eKeyBack) & S3E_KEY_STATE_PRESSED)
		{
			resume = 0;
			s3eKeyboardClearState();
		}

		if(s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN)
		{
			if(plank == 0)
			{
				if(s3ePointerGetX()>=beg.x &&
					s3ePointerGetX()<=beg.x+length+2*b_size.x &&
					s3ePointerGetY()>=beg.y+2*b_size.x &&
					s3ePointerGetY()<=beg.y+2*b_size.x+Iw2DGetSurfaceWidth()*0.3f*0.27f)
				{
					track++;
					if(track==4)
					{
						track = 1;
						s3eAudioPlay("bk_music.mp3",0);
						if(sound == 0)
						{
							s3eAudioPause();
						}
					}
					if(track == 2)
					{
						s3eAudioPlay("bk_music1.mp3",0);
						if(sound == 0)
						{
							s3eAudioPause();
						}
					}
					else if(track == 3)
					{
						s3eAudioPlay("bk_music2.mp3",0);
						if(sound == 0)
						{
							s3eAudioPause();
						}
					}
					plank = c;
					
				}
				if(s3ePointerGetX()>=beg.x &&
					s3ePointerGetX()<=beg.x+length+2*b_size.x &&
					s3ePointerGetY()>=beg.y+10*b_size.x &&
					s3ePointerGetY()<=beg.y+10*b_size.x+Iw2DGetSurfaceWidth()*0.3f*0.3f)
				{
					level++;
					if(level==6)
					{
						level = 1;
					}
						
					switch (level)
					{
						case 1:
							bg = bg_1;

							ubutton = ubutton_1;
							dbutton = dbutton_1;
							lbutton = lbutton_1;
							rbutton = rbutton_1;
				
							frame = frame_1;
							food = food_1;
				
							head_u = head_u_1;
							head_d = head_d_1;
							head_l = head_l_1;
							head_r = head_r_1;
				
							body = body_1;
							break;
						case 2:
							bg = bg_2;
				
							ubutton = ubutton_2;
							dbutton = dbutton_2;
							lbutton = lbutton_2;
							rbutton = rbutton_2;
				
							frame = frame_2;
							food = food_2;
				
							head_u = head_u_2;
							head_d = head_d_2;
							head_l = head_l_2;
							head_r = head_r_2;
				
							body = body_2;
							break;
						case 3:
							bg = bg_3;
				
							ubutton = ubutton_3;
							dbutton = dbutton_3;
							lbutton = lbutton_3;
							rbutton = rbutton_3;
				
							frame = frame_3;
							food = food_3;
				
							head_u = head_u_3;
							head_d = head_d_3;
							head_l = head_l_3;
							head_r = head_r_3;
				
							body = body_3;
							break;
						case 4:
							bg = bg_4;
				
							ubutton = ubutton_4;
							dbutton = dbutton_4;
							lbutton = lbutton_4;
							rbutton = rbutton_4;
				
							frame = frame_4;
							food = food_4;
				
							head_u = head_u_4;
							head_d = head_d_4;
							head_l = head_l_4;
							head_r = head_r_4;

							body = body_4;
							break;
						case 5:
							bg = bg_5;

							ubutton = ubutton_5;
							dbutton = dbutton_5;
							lbutton = lbutton_5;
							rbutton = rbutton_5;

							frame = frame_5;
							food = food_5;

							head_u = head_u_5;
							head_d = head_d_5;
							head_l = head_l_5;
							head_r = head_r_5;
				
							body = body_5;
							break;
					}
					plank = (c+1)*10;
				}
				if(s3ePointerGetX()>=beg.x &&
					s3ePointerGetX()<=beg.x+length+2*b_size.x &&
					s3ePointerGetY()>=beg.y+18*b_size.x &&
					s3ePointerGetY()<=beg.y+18*b_size.x+Iw2DGetSurfaceWidth()*0.45f*0.18f)
				{
					resume = 2;
				}
			}
		}

		if(c==15)
		{
			c=1;
			if(plank==c)
			{
				plank = 0;
			}
			if(plank == (c+1)*10)
			{
				plank = 0;;
			}
		}
		else
		{
			c++;
			if(plank==c)
			{
				plank = 0;
			}
			if(plank == (c+1)*10)
			{
				plank = 0;;
			}
		}
	}
	else if(resume == 2)
	{
		if(s3eKeyboardGetState(s3eKeyBack) & S3E_KEY_STATE_PRESSED)
		{
			resume = 1;
			s3eKeyboardClearState();
		}
	}
	else if(resume == 0)
	{	
		if(s3eKeyboardGetState(s3eKeyBack) & S3E_KEY_STATE_PRESSED)
		{
			store->hs[0] = h_score[0];
			store->hs[1] = h_score[1];
			store->hs[2] = h_score[2];
			store->l = level;
			store->s = sound;
			store->t = track;

			s3eSecureStoragePut(store,sizeof(struct _save));
			s3eDeviceRequestQuit();
			s3eAudioStop();
		}

		if((s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN))
		{
			if((END->dir == 1 || END->dir == -1)  && over == 0)
			{
				if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f+Iw2DGetSurfaceWidth()*0.1f)
				{
					b_select = 1;
				}
				else if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f+Iw2DGetSurfaceWidth()*0.1f)
				{
					b_select = 2;
				}
			}
			else if((END->dir == 2 || END->dir == -2)  && over == 0)
			{
				if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2+Iw2DGetSurfaceWidth()*0.1f)
				{
					b_select = 3;
				}
				else if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f+2.0f*(Iw2DGetSurfaceWidth()*0.1f) && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+2.0f*(Iw2DGetSurfaceWidth()*0.1f)+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2+Iw2DGetSurfaceWidth()*0.1f)
				{
					b_select = 4;
				}
			}
			if(sound_stat == 0)
			{
				if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.08f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.85f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.85f+Iw2DGetSurfaceWidth()*0.08f)
				{
					if(sound == 1)
					{
						sound = 0;
						s3eAudioPause();
					}
					else
					{
						sound = 1;
						s3eAudioResume();
					}
					sound_stat = c;
					if(sound_stat-1 <= 1)
					{
						sound_stat = 3;
					}
				}
			}
			if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f+2*(Iw2DGetSurfaceWidth()*0.1f) &&
				s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+2*(Iw2DGetSurfaceWidth()*0.1f)+Iw2DGetSurfaceWidth()*0.08f &&
				s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.85f &&
				s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.85f+Iw2DGetSurfaceWidth()*0.08f)
			{
				resume = 1;
			}

			if(over == 0)
			{
				if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f+(Iw2DGetSurfaceWidth()*0.1f) &&
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+(Iw2DGetSurfaceWidth()*0.1f)+Iw2DGetSurfaceWidth()*0.08f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.85f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.85f+Iw2DGetSurfaceWidth()*0.08f)
				{
					over = -2;
				}
			}
			else if(over == -2)
			{
				if(s3ePointerGetX()>=(beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.3f/2 &&
					s3ePointerGetX()<=(beg.x+length+2*b_size.x)/2+Iw2DGetSurfaceWidth()*0.3f/2 &&
					s3ePointerGetY()>=beg.y+6*b_size.x &&
					s3ePointerGetY()<=beg.y+6*b_size.x+Iw2DGetSurfaceWidth()*0.3f*0.3f)
				{
					over = 0;
				}

				if(s3ePointerGetX()>=(beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.4f/2 &&
					s3ePointerGetX()<=(beg.x+length+2*b_size.x)/2+Iw2DGetSurfaceWidth()*0.4f/2 &&
					s3ePointerGetY()>=beg.y+13*b_size.x &&
					s3ePointerGetY()<=beg.y+13*b_size.x+Iw2DGetSurfaceWidth()*0.4f*0.31f)
				{
					reset();
				}
			}
			else if(over == -1)
			{
				if(s3ePointerGetX()>= (beg.x+length+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.15f/2 && 
					s3ePointerGetX()<= (beg.x+length+2*b_size.x)/2+Iw2DGetSurfaceWidth()*0.15f/2 && 
					s3ePointerGetY() >= (beg.y+breadth+2*b_size.x)/2-Iw2DGetSurfaceWidth()*0.15f/2 && 
					s3ePointerGetY()<= (beg.y+breadth+2*b_size.x)/2+Iw2DGetSurfaceWidth()*0.15f/2)
				{
					over = 0;
				}
			}
		}

		if(c==15)
		{
			c=1;
			if (b_select!=0)
			{
				switch(b_select)
				{
					case 1:
						END->dir = -2;
						break;
					case 2:
						END->dir = 2;
						break;
					case 3:
						END->dir = -1;
						break;
					case 4:
						END->dir = 1;
						break;
				}
				b_select = 0;
			}

			temp = move;
			for(i=1, b_dir = START; i<block-1; i++,b_dir=b_dir->next)
			{
				if(((int)a_move.x==(int)temp.x) & ((int)a_move.y == (int)temp.y))
				{
					over = 1;
					break;
				}

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
			}
			if(over == 0)
			{	
				switch(START->dir)
				{
					case 1:
						if(move.x<end.x-g_size.x)
							move.x+=g_size.x;
						else move.x = beg.x+b_size.x;
						break;
					case -1:
						if(move.x>beg.x+b_size.x)
							move.x-=g_size.x;
						else move.x = end.x-g_size.x;
						break;
					case 2:	
						if(move.y<end.y-g_size.y)
							move.y+=g_size.y;
						else move.y = beg.y+b_size.x;
						break;
					case -2:
						if(move.y>beg.y+b_size.x)
							move.y-=g_size.y;
						else move.y = end.y-g_size.y;;
						break;
				}
				for(i=0, b_dir = START;i<block-1;i++,b_dir=b_dir->next)
				{
					b_dir->dir = b_dir->next->dir;
				}
				if(((int)a_move.x==(int)(beg.x+b_size.x+f_Position.x*g_size.x)) & ((int)a_move.y == (int)(beg.y+b_size.x+f_Position.y*g_size.y)))
				{
					block++;
					_score+=10;
					flag = 0;
					do
					{
						f_Position.x = (float)(rand()%(int)(length/g_size.x));
						f_Position.y = (float)(rand()%(int)(breadth/g_size.y));
						temp = move;
						for(i=1, b_dir = START; i<block; i++,b_dir=b_dir->next)
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
					}while(flag==0);

					b_dir = new Direction;
					b_dir->dir = END->dir;
					b_dir->next = NULL;
					END->next = b_dir;
					END = b_dir;
				}
			}
		}
		else
		{
			if(c<15)
				c++;
			if(sound_stat-1 == c)
			{
					sound_stat = 0;
			}
		}
	}
}

void CGame::reset()
{
	move.x = (float)((int)(Iw2DGetSurfaceWidth()*0.03f));
	move.y = (float)((int)(Iw2DGetSurfaceHeight()*0.15f));

	f_Position.x = (float)(rand()%(int)(length/g_size.x));
	f_Position.y = (float)(rand()%(int)(breadth/g_size.y));

	b_select = 0;
	c=0;
	over = 0;
	_score = 0;
	
	for(i=0;i<block;i++)
	{
		b_dir = START;
		START = START->next;
		delete b_dir;
	}
	delete START;
	
	block = 5;

	for(i=0;i<block;i++)
	{
		if(i==0)
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
*/