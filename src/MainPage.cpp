#include "game.h"

//--------------------------------------------------------------------------------------------------------
//-------------------------Main Page Updation-------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

void CGame::mainPageUpdate()
{
	if((s3eKeyboardGetState(s3eKeyBack) | s3eKeyboardGetState(s3eKeyEsc)) & S3E_KEY_STATE_PRESSED)
	{
		if (page == 1)
		{
			s3eDeviceRequestQuit();
		}
		else
		{
			menu_trans = -1;
			trans_dir = -1;
			if(page == 1124 || page == 12 || page == 13)
			{
				trans_pos = 0;
			}
			else
			{
				trans_pos = Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2;
			}
		}
		s3eKeyboardClearState();
	}
	/*if(s3eKeyboardGetState(s3eKeyA) & S3E_KEY_STATE_PRESSED)
	{
		page = 2;
		control_select = 1;
		s3eKeyboardClearState();
	}*/
	if(s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_RELEASED)
	{
		trans_pos = Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2;
		switch (page)
		{
			case 1:
				if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.25f+menu_button_size.y/2)
				{
					page = 11;
					menu_trans = 1;
					trans_dir = -1;
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.50f+menu_button_size.y/2)
				{
					page = 12;
					trans_pos = (float)Iw2DGetSurfaceWidth();
					menu_trans = 1;
					trans_dir = -1;
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.75f+menu_button_size.y/2)
				{
					page = 13;
					trans_pos = (float)Iw2DGetSurfaceWidth();
					menu_trans = 1;
					trans_dir = -1;
				}
				break;
			case 11:
				if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*1/3+menu_button_size.y/2)
				{
					page = 111;
					menu_trans = 1;
					trans_dir = -1;
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*2/3+menu_button_size.y/2)
				{
					page = 112;
					menu_trans = 1;
					trans_dir = -1;
				}
				break;
			case 12:
				if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.40f && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.40f+control_button_size.x &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.19f+control_button_size.x/2)
				{
					control_select = 1;
					main_page_delay = 20;
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.60f && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.60f+control_button_size.x &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.19f+control_button_size.x/2)
				{
					control_select = 2;
					main_page_delay = 20;
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+control_button_size.x &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.19f+control_button_size.x/2)
				{
					control_select = 3;
					main_page_delay = 20;
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.40f && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.40f+control_button_size.x &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.50f+control_button_size.x/2)
				{
					if(music > 0)
					{
						music = 1;
						s3eAudioPlay("Sound/bk_music_1.mp3",0);
						main_page_delay = 20;
					}
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.60f && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.60f+control_button_size.x &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.50f+control_button_size.x/2)
				{
					if(music > 0)
					{
						music = 2;
						s3eAudioPlay("Sound/bk_music_2.mp3",0);
						main_page_delay = 20;
					}
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+control_button_size.x &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.50f+control_button_size.x/2)
				{
					if(music > 0)
					{
						music = 3;
						s3eAudioPlay("Sound/bk_music_3.mp3",0);
						main_page_delay = 20;
					}
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.40f && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.40f+control_button_size.x &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.83f+control_button_size.x/2)
				{
					if(music < 0)
					{
						music = -music;
						switch (music)
						{		
							case 1:
								s3eAudioPlay("Sound/bk_music_1.mp3",0);
								break;
							case 2:
								s3eAudioPlay("Sound/bk_music_2.mp3",0);
								break;					
							case 3:
								s3eAudioPlay("Sound/bk_music_3.mp3",0);
								break;
						}
					}
					else
					{
						music = -music;
						s3eAudioStop();
					}
					main_page_delay = 20;
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.60f && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.60f+control_button_size.x &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.83f+control_button_size.x/2)
				{
					if(sound == 0)
					{
						sound = 1;
					}
					else
					{
						sound = 0;
					}
					main_page_delay = 20;
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+control_button_size.x &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.83f+control_button_size.x/2)
				{
					if(vibration == 0)
					{
						vibration = 1;
					}
					else
					{
						vibration = 0;
					}
					main_page_delay = 20;
				}
				
				break;
			case 13:
				
				break;
			case 111:
				if(resume_campiagn == 1)
				{
					if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.25f+menu_button_size.y/2)
					{
						page = 1;
						main_page_delay = 20;
					}
					else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.50f+menu_button_size.y/2)
					{
						page = 2;
						main_page_delay = 20;
					}
					/*else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.75f+menu_button_size.y/2)
					{
						page = 1;
						main_page_delay = 20;
					}*/
				}
				else
				{
					if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*1/3+menu_button_size.y/2)
					{
						page = 2;
						main_page_delay = 20;
					}
					/*else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*2/3+menu_button_size.y/2)
					{
						page = 1;
						main_page_delay = 20;
					}*/
				}
				break;
			case 112:
				if(resume_classic == 1)
				{
					if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*1/5+menu_button_size.y/2)
					{
						page = 1;
						main_page_delay = 20;
					}
					else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*2/5+menu_button_size.y/2)
					{
						page = 2;
						main_page_delay = 20;
					}
					else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*3/5+menu_button_size.y/2)
					{
						page = 1123;
						trans_pos = menu_button_size.y/2;
						menu_trans = 1;
						trans_dir = -1;
						level_cl++;
						if(level_cl == 4)
						{
							level_cl = 1;
						}
					}
					else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*4/5+menu_button_size.y/2)
					{
						page = 1124;
						menu_trans = 1;
						trans_dir = -1;
					}
				}
				else
				{
					if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.25f+menu_button_size.y/2)
					{
						page = 2;
						main_page_delay = 20;
					}
					else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.50f+menu_button_size.y/2)
					{
						page = 1123;
						trans_pos = menu_button_size.y/2;
						menu_trans = 1;
						trans_dir = -1;
						level_cl++;
						if(level_cl == 4)
						{
							level_cl = 1;
						}
					}
					else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.75f+menu_button_size.y/2)
					{
						page = 1124;
						trans_pos = (float)Iw2DGetSurfaceWidth();
						slide_select_curr = maze_select;
						menu_trans = 1;
						trans_dir = -1;
					}
				}
				break;
			case 1111:
				break;
			case 1112:
				break;
			case 1113:
				break;
			case 1121:
				break;
			case 1122:
				break;
			case 1123:
				break;
			case 1124:
				if (isslide == false)
				{
					slide_stop_point = CIwFVec2((float)s3ePointerGetX(),(float)s3ePointerGetY());
					float a = (float)sqrt( ( (slide_stop_point.x - slide_start_point.x) * (slide_stop_point.x - slide_start_point.x) ) + ( (slide_stop_point.y - slide_start_point.y) * (slide_stop_point.y - slide_start_point.y) ) );
					float b = (slide_stop_point.y - slide_start_point.y)/(slide_stop_point.x - slide_start_point.x);
	
					if( ( a >= Iw2DGetSurfaceWidth()*0.05f) && ((slide_stop_point.x - slide_start_point.x) != 0) && (b >= tan(-PI/6) && b <= tan(PI/6))||(b >= tan(5*PI/6) && b <= tan(7*PI/6)))
					{
						slide_start_time = 0;
						if(slide_start_point.x < slide_stop_point.x)
						{
							if(slide_select_curr > 0)
							{
								isslide = true;
								slide_select_next = slide_select_curr-1;
								slide_transition = Iw2DGetSurfaceWidth()*0.30f;
								slide_transition_curr = Iw2DGetSurfaceWidth()*0.60f;

								slide_transition_position = CIwFVec2(-Iw2DGetSurfaceWidth()*0.15f,Iw2DGetSurfaceHeight()*0.35f);
								slide_transition_position_curr = CIwFVec2(Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f);
							}
						}
						else
						{
							if(slide_select_curr < 8)
							{
								isslide = true;
								slide_select_next = slide_select_curr+1;
								slide_transition = Iw2DGetSurfaceWidth()*0.30f;
								slide_transition_curr = Iw2DGetSurfaceWidth()*0.60f;

								slide_transition_position = CIwFVec2(Iw2DGetSurfaceWidth()*0.85f,Iw2DGetSurfaceHeight()*0.35f);
								slide_transition_position_curr = CIwFVec2(Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f);
							}
						}
					}
					else if (s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.20f && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.20f && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.80f)
					{
						maze_select = slide_select_curr;
						wall_max = 0;
						wall_init();
					}
				}
				break;
		}
	}
	else if(s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN)
	{
		if(page == 1124 && slide_start_time == 0)
		{
			slide_start_time = (int)s3eTimerGetMs();
			slide_start_point = CIwFVec2((float)s3ePointerGetX(),(float)s3ePointerGetY());
		}
	}
}

//--------------------------------------------------------------------------------------------------------
//---------------------Main Page Draw---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

void CGame::mainPage()
{
	Iw2DDrawImage(getresource->get_menu_bg(),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
	Iw2DDrawImage(getresource->get_fb_button(),CIwFVec2(Iw2DGetSurfaceWidth()*0.05f,0),CIwFVec2(Iw2DGetSurfaceWidth()*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
	Iw2DDrawImage(getresource->get_rate_button(),CIwFVec2(2.5f*(Iw2DGetSurfaceWidth()*0.05f),0),CIwFVec2(Iw2DGetSurfaceWidth()*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));

	switch (page)
	{
		case 1:
			Iw2DSetColour(0xaaffffff);
			Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
			Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
			Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
			Iw2DSetColour(0xffffffff);
			break;
		case 11:
			Iw2DSetColour(0xaaffffff);
			Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
			Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
			Iw2DSetColour(0xffffffff);
			break;
		case 12:

			//Iw2DSetColour(0xff40cea1);
			//Iw2DSetColour(0xff0000ff);
			
			
			Iw2DDrawImage(getresource->get_control_bg(),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
			
			switch (control_select)
			{
				case 1:
					Iw2DSetColour(0xff0077ff);
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
					Iw2DSetColour(0xffffffff);
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
					break;
				case 2:
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
					Iw2DSetColour(0xff0077ff);
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
					Iw2DSetColour(0xffffffff);
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
					break;
				case 3:
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
					Iw2DSetColour(0xff0077ff);
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
					Iw2DSetColour(0xffffffff);
					break;
			}

			switch (music)
			{
				case 1:
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
					Iw2DSetColour(0xff0077ff);
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
					Iw2DSetColour(0xffffffff);
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
					break;
				case 2:
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
					Iw2DSetColour(0xff0077ff);
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
					Iw2DSetColour(0xffffffff);
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
					break;
				case 3:
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
					Iw2DSetColour(0xff0077ff);
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
					Iw2DSetColour(0xffffffff);
					break;
				default:
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(150,150),CIwFVec2(150,150));
					Iw2DSetColour(0xff777777);
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
					Iw2DSetColour(0xffffffff);
					break;
			}
			
			if (sound == 1)
			{
				Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(600,0),CIwFVec2(150,150));
			}
			else
			{
				Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(600,150),CIwFVec2(150,150));
			}
			if (vibration == 1)
			{
				Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(300,150),CIwFVec2(150,150));
			}
			else
			{
				Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(450,150),CIwFVec2(150,150));
			}

			/*if (music == 1)
			{
				Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(600,0),CIwFVec2(150,150));
			}
			else
			{
				Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
			}*/
			/*Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.05f,Iw2DGetSurfaceHeight()*0.30f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,384),CIwFVec2(325,96));
			Iw2DDrawImageRegion(getresource->get_body(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.30f-Iw2DGetSurfaceWidth()*0.06f),CIwFVec2(Iw2DGetSurfaceWidth()*0.12f,Iw2DGetSurfaceWidth()*0.12f),CIwFVec2(0,0),CIwFVec2(30,30));
			Iw2DDrawImageRegion(getresource->get_body(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.30f-Iw2DGetSurfaceWidth()*0.06f),CIwFVec2(Iw2DGetSurfaceWidth()*0.12f,Iw2DGetSurfaceWidth()*0.12f),CIwFVec2(0,0),CIwFVec2(30,30));
			Iw2DDrawImageRegion(getresource->get_body(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.30f-Iw2DGetSurfaceWidth()*0.06f),CIwFVec2(Iw2DGetSurfaceWidth()*0.12f,Iw2DGetSurfaceWidth()*0.12f),CIwFVec2(0,0),CIwFVec2(30,30));

			Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.05f,Iw2DGetSurfaceHeight()*0.70f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
			Iw2DDrawImageRegion(getresource->get_body(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.70f-Iw2DGetSurfaceWidth()*0.06f),CIwFVec2(Iw2DGetSurfaceWidth()*0.12f,Iw2DGetSurfaceWidth()*0.12f),CIwFVec2(0,0),CIwFVec2(30,30));
			Iw2DDrawImageRegion(getresource->get_body(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.70f-Iw2DGetSurfaceWidth()*0.06f),CIwFVec2(Iw2DGetSurfaceWidth()*0.12f,Iw2DGetSurfaceWidth()*0.12f),CIwFVec2(0,0),CIwFVec2(30,30));
			Iw2DDrawImageRegion(getresource->get_body(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.70f-Iw2DGetSurfaceWidth()*0.06f),CIwFVec2(Iw2DGetSurfaceWidth()*0.12f,Iw2DGetSurfaceWidth()*0.12f),CIwFVec2(0,0),CIwFVec2(30,30));
			*/

			break;
		case 13:
			Iw2DDrawImage(getresource->get_about(),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
			break;
		case 111:
			Iw2DSetColour(0xaaffffff);
			if(resume_campiagn == 1)
			{
				Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
				Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
				//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,384),CIwFVec2(325,96));
				Iw2DSetColour(0xff000000);
				sprintf(print,"HIGHSCORE\n%d",highscore_ca);
				Iw2DDrawString(print,CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.75f-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
			}
			else
			{
				Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
				//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,384),CIwFVec2(325,96));
				Iw2DSetColour(0xff000000);
				sprintf(print,"HIGHSCORE\n%d",highscore_ca);
				Iw2DDrawString(print,CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*2/3-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
			}
			Iw2DSetColour(0xffffffff);
			break;
		case 112:
			Iw2DSetColour(0xaaffffff);
			if(resume_classic == 1)
			{
				Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
				Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
				//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
				Iw2DSetColour(0xffffffff);
				Iw2DDrawString("LEVEL",CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*3/5-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x/2,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				Iw2DSetColour(0xaaffffff);
				switch (level_cl)
				{
					case 1:
						Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));
						break;
					case 2:
						Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(100,0),CIwFVec2(100,100));
						break;
					case 3:
						Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(200,0),CIwFVec2(100,100));
						break;
				}
				Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
			}
			else
			{
				Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
				
				/*Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
				Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));*/
				
				Iw2DSetColour(0xffffffff);
				Iw2DDrawString("LEVEL",CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.50f-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x/2,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				Iw2DSetColour(0xaaffffff);
				switch (level_cl)
				{
					case 1:
						Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));
						break;
					case 2:
						Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(100,0),CIwFVec2(100,100));
						break;
					case 3:
						Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(200,0),CIwFVec2(100,100));
						break;
				}

				Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
			}
			Iw2DSetColour(0xffffffff);
			break;
		case 1124:

			Iw2DDrawImage(getresource->get_select_bg(),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
			if(isslide == 0)
			{
				switch (slide_select_curr)
				{
					case 0:
	
						Iw2DDrawImage(getresource->get_bg(0),CIwFVec2(Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
						Iw2DDrawImage(getresource->get_bg(1),CIwFVec2(Iw2DGetSurfaceWidth()*0.85f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
	
						break;
					case 8:
	
						Iw2DDrawImage(getresource->get_bg(7),CIwFVec2(-Iw2DGetSurfaceWidth()*0.15f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
						Iw2DDrawImage(getresource->get_bg(8),CIwFVec2(Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
	
						break;
					default:
	
						Iw2DDrawImage(getresource->get_bg(slide_select_curr-1),CIwFVec2(-Iw2DGetSurfaceWidth()*0.15f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
						Iw2DDrawImage(getresource->get_bg(slide_select_curr),CIwFVec2(Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
						Iw2DDrawImage(getresource->get_bg(slide_select_curr+1),CIwFVec2(Iw2DGetSurfaceWidth()*0.85f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
	
						break;
				}
			}
			else if(slide_select_next < slide_select_curr)
			{
				if(slide_transition < Iw2DGetSurfaceWidth()*0.60f - g_speed)
				{
					slide_transition += g_speed;
					slide_transition_curr -= g_speed;
					slide_transition_position.x += g_speed*1.17f;
					slide_transition_position.y -= g_speed*0.5f*((float)Iw2DGetSurfaceHeight()/(float)Iw2DGetSurfaceWidth());
					slide_transition_position_curr.x += g_speed*2.17f;
					slide_transition_position_curr.y += g_speed*0.5f*((float)Iw2DGetSurfaceHeight()/(float)Iw2DGetSurfaceWidth());
				}
				else
				{
					isslide = false;
					slide_select_curr = slide_select_next;
				}
				Iw2DDrawImage(getresource->get_bg(slide_select_next),slide_transition_position,CIwFVec2(slide_transition,slide_transition*((float)Iw2DGetSurfaceHeight()/(float)Iw2DGetSurfaceWidth())));
				Iw2DDrawImage(getresource->get_bg(slide_select_next+1),slide_transition_position_curr,CIwFVec2(slide_transition_curr,slide_transition_curr*((float)Iw2DGetSurfaceHeight()/(float)Iw2DGetSurfaceWidth())));
				if(slide_select_next+2 <= 8 && Iw2DGetSurfaceWidth()*0.55f+slide_transition <= Iw2DGetSurfaceWidth())
				{
					Iw2DDrawImage(getresource->get_bg(slide_select_next+2),CIwFVec2(Iw2DGetSurfaceWidth()*0.55f+slide_transition,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
				}
				if(slide_select_next-1 >= 0)
				{
					Iw2DDrawImage(getresource->get_bg(slide_select_next-1),CIwFVec2(-Iw2DGetSurfaceWidth()*0.75f + slide_transition,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
				}
			}
			else if(slide_select_next > slide_select_curr)
			{
				if(slide_transition < Iw2DGetSurfaceWidth()*0.60f - g_speed)
				{
					slide_transition += g_speed;
					slide_transition_curr -= g_speed;
					slide_transition_position.x -= g_speed*2.17f;
					slide_transition_position.y -= g_speed*0.5f*((float)Iw2DGetSurfaceHeight()/(float)Iw2DGetSurfaceWidth());
					slide_transition_position_curr.x -= g_speed*1.17f;
					slide_transition_position_curr.y += g_speed*0.5f*((float)Iw2DGetSurfaceHeight()/(float)Iw2DGetSurfaceWidth());
				}
				else
				{
					isslide = false;
					slide_select_curr = slide_select_next;
				}
				Iw2DDrawImage(getresource->get_bg(slide_select_next),slide_transition_position,CIwFVec2(slide_transition,slide_transition*((float)Iw2DGetSurfaceHeight()/(float)Iw2DGetSurfaceWidth())));
				Iw2DDrawImage(getresource->get_bg(slide_select_next-1),slide_transition_position_curr,CIwFVec2(slide_transition_curr,slide_transition_curr*((float)Iw2DGetSurfaceHeight()/(float)Iw2DGetSurfaceWidth())));
				if(slide_select_next-2 >= 0 && Iw2DGetSurfaceWidth()*0.15f-slide_transition >= -Iw2DGetSurfaceWidth()*0.30f)
				{
					Iw2DDrawImage(getresource->get_bg(slide_select_next-2),CIwFVec2(Iw2DGetSurfaceWidth()*0.15f-slide_transition,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
				}
				if(slide_select_next+1 <= 8)
				{
					Iw2DDrawImage(getresource->get_bg(slide_select_next+1),CIwFVec2(Iw2DGetSurfaceWidth()*1.45f - slide_transition,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
				}
			}
			break;
	}

	if(s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN)
	{
		switch (page)
		{
			case 1:
				if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.25f+menu_button_size.y/2)
				{
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.50f+menu_button_size.y/2)
				{
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.75f+menu_button_size.y/2)
				{
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
				}
				break;
			case 11:
				if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*1/3+menu_button_size.y/2)
				{
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
				}
				else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
					s3ePointerGetY() >= Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*2/3+menu_button_size.y/2)
				{
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				break;
			case 12:
				break;
			case 13:
				break;
			case 111:
				if(resume_campiagn == 1)
				{
					if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.25f+menu_button_size.y/2)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
					}
					else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.50f+menu_button_size.y/2)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
					}
					/*else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.75f+menu_button_size.y/2)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,384),CIwFVec2(325,96));
					}*/
				}
				else
				{
					if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*1/3+menu_button_size.y/2)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
					}
					/*else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*2/3+menu_button_size.y/2)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,384),CIwFVec2(325,96));
					}*/
				}
				break;
			case 112:
				if(resume_classic == 1)
				{
					if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*1/5+menu_button_size.y/2)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
					}
					else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*2/5+menu_button_size.y/2)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
					}
					else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*3/5+menu_button_size.y/2)
					{
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));
								break;
							case 2:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(100,0),CIwFVec2(100,100));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(200,0),CIwFVec2(100,100));
								break;
						}
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
					}
					else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*4/5+menu_button_size.y/2)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
				}
				else
				{
					if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.25f+menu_button_size.y/2)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
					}
					else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.50f+menu_button_size.y/2)
					{
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));
								break;
							case 2:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(100,0),CIwFVec2(100,100));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(200,0),CIwFVec2(100,100));
								break;
						}
					}
					else if(s3ePointerGetX() >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2 && s3ePointerGetX() <= Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x/2 &&
						s3ePointerGetY() >= Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2 && s3ePointerGetY() <= Iw2DGetSurfaceHeight()*0.75f+menu_button_size.y/2)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
				}
				break;
		}
	}
}


//--------------------------------------------------------------------------------------------------------
//---------------------Menu Transition Draw---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

void CGame::menu_trans_draw()
{
	Iw2DDrawImage(getresource->get_menu_bg(),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
	Iw2DDrawImage(getresource->get_fb_button(),CIwFVec2(Iw2DGetSurfaceWidth()*0.05f,0),CIwFVec2(Iw2DGetSurfaceWidth()*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
	Iw2DDrawImage(getresource->get_rate_button(),CIwFVec2(2.5f*(Iw2DGetSurfaceWidth()*0.05f),0),CIwFVec2(Iw2DGetSurfaceWidth()*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));

	if(menu_trans == 1)
	{
		switch (page)
		{
			case 11:
				
				Iw2DSetColour(0xaaffffff);
				if(trans_dir == -1)
				{
					trans_pos -= g_speed;
					if (trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 1;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
				}
				else if(trans_dir == 1)
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth())
					{
						trans_dir = -2;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
				}
				else if (trans_dir == -2)
				{
					trans_pos -= g_speed;
					if(trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 2;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				else
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2)
					{
						trans_pos = Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2;
						menu_trans = 0;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				Iw2DSetColour(0xffffffff);
	
				break;
			case 12:
				Iw2DDrawImage(getresource->get_control_bg(),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
			
				switch (control_select)
				{
					case 1:
						Iw2DSetColour(0xff0077ff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
						break;
					case 2:
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
						Iw2DSetColour(0xff0077ff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
						break;
					case 3:
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
						Iw2DSetColour(0xff0077ff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						break;
				}
	
				switch (music)
				{
					case 1:
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
						Iw2DSetColour(0xff0077ff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						break;
					case 2:
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DSetColour(0xff0077ff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						break;
					case 3:
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DSetColour(0xff0077ff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						break;
					default:
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(150,150),CIwFVec2(150,150));
						Iw2DSetColour(0xff777777);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						break;
				}
				
				if (sound == 1)
				{
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(600,0),CIwFVec2(150,150));
				}
				else
				{
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(600,150),CIwFVec2(150,150));
				}
				if (vibration == 1)
				{
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(300,150),CIwFVec2(150,150));
				}
				else
				{
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(450,150),CIwFVec2(150,150));
				}

				if(trans_dir == -1)
				{
					trans_pos -= g_speed;
					if (trans_pos <= -Iw2DGetSurfaceWidth()*0.05f)
					{
						trans_pos = 0;
						menu_trans = 0;
					}
					Iw2DDrawImage(getresource->get_menu_bg(),CIwFVec2(0,0),CIwFVec2(trans_pos,(float)Iw2DGetSurfaceHeight()));
					Iw2DDrawImage(getresource->get_fb_button(),CIwFVec2(trans_pos*0.05f,0),CIwFVec2(trans_pos*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
					Iw2DDrawImage(getresource->get_rate_button(),CIwFVec2(2.5f*(trans_pos*0.05f),0),CIwFVec2(trans_pos*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(0,96),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
				}

				/* 
				if(trans_dir == -1)
				{
					trans_pos -= g_speed;
					if (trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 1;
					}
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
				}
				else if(trans_dir == 1)
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth())
					{
						trans_dir = -2;
					}
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
				}
				else if (trans_dir == -2)
				{
					trans_pos -= g_speed;
					if(trans_pos <= 0)
					{
						trans_pos = 0;
						menu_trans = 0;
					}

					Iw2DDrawImage(getresource->get_control_bg(),CIwFVec2(trans_pos,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
			
					switch (control_select)
					{
						case 1:
							Iw2DSetColour(0xff0077ff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
							break;
						case 2:
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
							Iw2DSetColour(0xff0077ff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
							break;
						case 3:
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
							Iw2DSetColour(0xff0077ff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							break;
					}

					switch (music)
					{
						case 1:
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
							Iw2DSetColour(0xff0077ff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							break;
						case 2:
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DSetColour(0xff0077ff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							break;
						case 3:
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DSetColour(0xff0077ff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							break;
						default:
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(150,150),CIwFVec2(150,150));
							Iw2DSetColour(0xff777777);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							break;
					}
			
					if (sound == 1)
					{
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(600,0),CIwFVec2(150,150));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(600,150),CIwFVec2(150,150));
					}
					if (vibration == 1)
					{
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(300,150),CIwFVec2(150,150));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(450,150),CIwFVec2(150,150));
					}
				}*/

				break;
			case 13:
				Iw2DDrawImage(getresource->get_about(),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));

				if(trans_dir == -1)
				{
					trans_pos -= g_speed;
					if (trans_pos <= -Iw2DGetSurfaceWidth()*0.05f)
					{
						trans_pos = 0;
						menu_trans = 0;
					}
					Iw2DDrawImage(getresource->get_menu_bg(),CIwFVec2(0,0),CIwFVec2(trans_pos,(float)Iw2DGetSurfaceHeight()));
					Iw2DDrawImage(getresource->get_fb_button(),CIwFVec2(trans_pos*0.05f,0),CIwFVec2(trans_pos*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
					Iw2DDrawImage(getresource->get_rate_button(),CIwFVec2(2.5f*(trans_pos*0.05f),0),CIwFVec2(trans_pos*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(0,96),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
				}

				/*if(trans_dir == -1)
				{
					trans_pos -= g_speed;
					if (trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 1;
					}
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
				}
				else if(trans_dir == 1)
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth())
					{
						trans_dir = -2;
					}
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
				}
				else if (trans_dir == -2)
				{
					trans_pos -= g_speed;
					if(trans_pos <= 0)
					{
						trans_pos = 0;
						menu_trans = 0;
					}
					Iw2DDrawImage(getresource->get_select_bg(),CIwFVec2(trans_pos,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
				}*/
				break;
	
			case 111:
	
				Iw2DSetColour(0xaaffffff);
				if(trans_dir == -1)
				{
					trans_pos -= g_speed;
					if (trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 1;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				else if(trans_dir == 1)
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth())
					{
						trans_dir = -2;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				else if (trans_dir == -2)
				{
					trans_pos -= g_speed;
					if(trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 2;
					}
					if(resume_campiagn == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DSetColour(0xff000000);
						sprintf(print,"HIGHSCORE\n%d",highscore_ca);
						Iw2DDrawString(print,CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.75f-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,384),CIwFVec2(325,96));
						Iw2DSetColour(0xff000000);
						sprintf(print,"HIGHSCORE\n%d",highscore_ca);
						Iw2DDrawString(print,CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
					}
				}
				else
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2)
					{
						trans_pos = Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2;
						menu_trans = 0;
					}
					if(resume_campiagn == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,384),CIwFVec2(325,96));
						Iw2DSetColour(0xff000000);
						sprintf(print,"HIGHSCORE\n%d",highscore_ca);
						Iw2DDrawString(print,CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.75f-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,384),CIwFVec2(325,96));
						Iw2DSetColour(0xff000000);
						sprintf(print,"HIGHSCORE\n%d",highscore_ca);
						Iw2DDrawString(print,CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
					}
				}
				Iw2DSetColour(0xffffffff);
	
				break;
			case 112:

				Iw2DSetColour(0xaaffffff);
				if(trans_dir == -1)
				{
					trans_pos -= g_speed;
					if (trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 1;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				else if(trans_dir == 1)
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth())
					{
						trans_dir = -2;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				else if (trans_dir == -2)
				{
					trans_pos -= g_speed;
					if(trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 2;
					}
					if(resume_classic == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.15f,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawString("LEVEL",CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*3/5-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x/2,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
						Iw2DSetColour(0xaaffffff);
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));
								break;
							case 2:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(100,0),CIwFVec2(100,100));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(200,0),CIwFVec2(100,100));
							break;
						}
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawString("LEVEL",CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x/2,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
						Iw2DSetColour(0xaaffffff);
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));
								break;
							case 2:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(100,0),CIwFVec2(100,100));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(200,0),CIwFVec2(100,100));
								break;
						}
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
				}
				else
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2)
					{
						trans_pos = Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2;
						menu_trans = 0;
					}
					if(resume_classic == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawString("LEVEL",CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*3/5-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x/2,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
						Iw2DSetColour(0xaaffffff);
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));
								break;
							case 2:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(100,0),CIwFVec2(100,100));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(200,0),CIwFVec2(100,100));
							break;
						}
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawString("LEVEL",CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.50f-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x/2,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
						Iw2DSetColour(0xaaffffff);
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));
								break;
							case 2:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(100,0),CIwFVec2(100,100));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(200,0),CIwFVec2(100,100));
								break;
						}
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
				}
				Iw2DSetColour(0xffffffff);
				break;
			case 1123:
				Iw2DSetColour(0xaaffffff);
				if(resume_classic == 1)
				{
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
					//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
					Iw2DDrawString("LEVEL",CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*3/5-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x/2,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
				}
				else
				{
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
					
					/*Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));*/
					
					Iw2DSetColour(0xffffffff);
					Iw2DDrawString("LEVEL",CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.50f-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x/2,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
				}

				if(trans_dir == -1)
				{
					trans_pos -= g_speed*0.2f;
					if (trans_pos <= 0)
					{
						trans_dir = 1;
					}
					if(resume_classic == 1)
					{
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(200,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(0,50),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5),CIwFVec2(menu_button_size.y,trans_pos),CIwFVec2(200,50),CIwFVec2(100,50));
								break;
							case 2:	
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(0,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(100,50),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5),CIwFVec2(menu_button_size.y,trans_pos),CIwFVec2(0,50),CIwFVec2(100,50));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(100,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(200,50),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5),CIwFVec2(menu_button_size.y,trans_pos),CIwFVec2(100,50),CIwFVec2(100,50));
								break;
						}
					}
					else
					{
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(200,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(0,50),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f),CIwFVec2(menu_button_size.y,trans_pos),CIwFVec2(200,50),CIwFVec2(100,50));
								break;
							case 2:	
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(0,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(100,50),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f),CIwFVec2(menu_button_size.y,trans_pos),CIwFVec2(0,50),CIwFVec2(100,50));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(100,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(200,50),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f),CIwFVec2(menu_button_size.y,trans_pos),CIwFVec2(100,50),CIwFVec2(100,50));
								break;
						}
					}
				}
				else if(trans_dir == 1)
				{
					trans_pos += g_speed*0.2f;
					if (trans_pos >= menu_button_size.y/2)
					{
						trans_pos = menu_button_size.y/2;
						page = 112;
						menu_trans = 0;
					}
					if(resume_classic == 1)
					{
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(200,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-trans_pos),CIwFVec2(menu_button_size.y,trans_pos),CIwFVec2(0,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(0,50),CIwFVec2(100,50));
								break;
							case 2:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(0,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-trans_pos),CIwFVec2(menu_button_size.y,trans_pos),CIwFVec2(100,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(100,50),CIwFVec2(100,50));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(100,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-trans_pos),CIwFVec2(menu_button_size.y,trans_pos),CIwFVec2(200,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(200,50),CIwFVec2(100,50));
								break;
						}
					}
					else
					{
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(200,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-trans_pos),CIwFVec2(menu_button_size.y,trans_pos),CIwFVec2(0,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(0,50),CIwFVec2(100,50));
								break;
							case 2:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(0,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-trans_pos),CIwFVec2(menu_button_size.y,trans_pos),CIwFVec2(100,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(100,50),CIwFVec2(100,50));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(100,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-trans_pos),CIwFVec2(menu_button_size.y,trans_pos),CIwFVec2(200,0),CIwFVec2(100,50));
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f+menu_button_size.x*0.25f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f),CIwFVec2(menu_button_size.y,menu_button_size.y/2),CIwFVec2(200,50),CIwFVec2(100,50));
								break;
						}
					}
				}
				Iw2DSetColour(0xffffffff);
				break;

			case 1124:

				Iw2DDrawImage(getresource->get_select_bg(),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
				switch (slide_select_curr)
				{
					case 0:
	
						Iw2DDrawImage(getresource->get_bg(0),CIwFVec2(Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
						Iw2DDrawImage(getresource->get_bg(1),CIwFVec2(Iw2DGetSurfaceWidth()*0.85f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
	
						break;
					case 8:
	
						Iw2DDrawImage(getresource->get_bg(7),CIwFVec2(-Iw2DGetSurfaceWidth()*0.15f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
						Iw2DDrawImage(getresource->get_bg(8),CIwFVec2(Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
	
						break;
					default:
	
						Iw2DDrawImage(getresource->get_bg(slide_select_curr-1),CIwFVec2(-Iw2DGetSurfaceWidth()*0.15f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
						Iw2DDrawImage(getresource->get_bg(slide_select_curr),CIwFVec2(Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
						Iw2DDrawImage(getresource->get_bg(slide_select_curr+1),CIwFVec2(Iw2DGetSurfaceWidth()*0.85f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
	
						break;
				}
			
				if(trans_dir == -1)
				{
					trans_pos -= g_speed;
					if (trans_pos <= -Iw2DGetSurfaceWidth()*0.05f)
					{
						trans_pos = 0;
						menu_trans = 0;
					}
					Iw2DDrawImage(getresource->get_menu_bg(),CIwFVec2(0,0),CIwFVec2(trans_pos,(float)Iw2DGetSurfaceHeight()));
					Iw2DDrawImage(getresource->get_fb_button(),CIwFVec2(trans_pos*0.05f,0),CIwFVec2(trans_pos*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
					Iw2DDrawImage(getresource->get_rate_button(),CIwFVec2(2.5f*(trans_pos*0.05f),0),CIwFVec2(trans_pos*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
					
					Iw2DSetColour(0xaaffffff);
					if(resume_classic == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,288),CIwFVec2(325,96));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,288),CIwFVec2(325,96));
					}
					Iw2DSetColour(0xffffffff);
				}
				/*if(trans_dir == -1)
				{
					trans_pos -= g_speed;
					if (trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 1;
					}
					Iw2DSetColour(0xaaffffff);
					if(resume_classic == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.15f,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
				}
				else if(trans_dir == 1)
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth())
					{
						trans_pos = Iw2DGetSurfaceWidth()+Iw2DGetSurfaceWidth()*0.15f;
						trans_dir = -2;
					}
					Iw2DSetColour(0xaaffffff);
					if(resume_classic == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.15f,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
				}
				else if (trans_dir == -2)
				{
					trans_pos -= g_speed;
					if(trans_pos <= 0)
					{
						trans_pos = 0;
						menu_trans = 0;
					}
					
					Iw2DDrawImage(getresource->get_select_bg(),CIwFVec2(trans_pos,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
					switch (slide_select_curr)
					{
						case 0:
		
							Iw2DDrawImage(getresource->get_bg(0),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
							Iw2DDrawImage(getresource->get_bg(1),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.85f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
		
							break;
						case 8:
		
							Iw2DDrawImage(getresource->get_bg(7),CIwFVec2(trans_pos - Iw2DGetSurfaceWidth()*0.15f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
							Iw2DDrawImage(getresource->get_bg(8),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
		
							break;
						default:
		
							Iw2DDrawImage(getresource->get_bg(slide_select_curr-1),CIwFVec2(trans_pos - Iw2DGetSurfaceWidth()*0.15f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
							Iw2DDrawImage(getresource->get_bg(slide_select_curr),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
							Iw2DDrawImage(getresource->get_bg(slide_select_curr+1),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.85f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
		
							break;
					}
				}
				Iw2DSetColour(0xffffffff);
				*/
				break;
		}
	}
	else if (menu_trans == -1)
	{
		switch (page)
		{
			case 11:
				
				Iw2DSetColour(0xaaffffff);
				if(trans_dir == -1)
				{
					trans_pos -= g_speed;
					if (trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 1;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				else if(trans_dir == 1)
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth())
					{
						trans_dir = -2;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				else if (trans_dir == -2)
				{
					trans_pos -= g_speed;
					if(trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 2;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
				}
				else
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2)
					{
						trans_pos = Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2;
						page = 1;
						menu_trans = 0;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
				}
				Iw2DSetColour(0xffffffff);
	
				break;
			case 12:

				Iw2DDrawImage(getresource->get_control_bg(),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
			
				switch (control_select)
				{
					case 1:
						Iw2DSetColour(0xff0077ff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
						break;
					case 2:
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
						Iw2DSetColour(0xff0077ff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
						break;
					case 3:
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
						Iw2DSetColour(0xff0077ff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						break;
				}
	
				switch (music)
				{
					case 1:
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
						Iw2DSetColour(0xff0077ff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						break;
					case 2:
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DSetColour(0xff0077ff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						break;
					case 3:
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DSetColour(0xff0077ff);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						break;
					default:
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(150,150),CIwFVec2(150,150));
						Iw2DSetColour(0xff777777);
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
						Iw2DSetColour(0xffffffff);
						break;
				}
				
				if (sound == 1)
				{
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(600,0),CIwFVec2(150,150));
				}
				else
				{
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(600,150),CIwFVec2(150,150));
				}
				if (vibration == 1)
				{
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(300,150),CIwFVec2(150,150));
				}
				else
				{
					Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(450,150),CIwFVec2(150,150));
				}

				if(trans_dir == -1)
				{
					trans_pos += g_speed*1.5f;
					if(trans_pos >= Iw2DGetSurfaceWidth())
					{
						page = 1;
						menu_trans = 0;
					}
					Iw2DDrawImage(getresource->get_menu_bg(),CIwFVec2(0,0),CIwFVec2(trans_pos,(float)Iw2DGetSurfaceHeight()));
					Iw2DDrawImage(getresource->get_fb_button(),CIwFVec2(trans_pos*0.05f,0),CIwFVec2(trans_pos*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
					Iw2DDrawImage(getresource->get_rate_button(),CIwFVec2(2.5f*(trans_pos*0.05f),0),CIwFVec2(trans_pos*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(0,96),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
				}

				/*if(trans_dir == -1)
				{
					trans_pos += g_speed;
					if(trans_pos >= Iw2DGetSurfaceWidth())
					{
						trans_dir = -2;	
					}

					Iw2DDrawImage(getresource->get_control_bg(),CIwFVec2(trans_pos,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
			
					switch (control_select)
					{
						case 1:
							Iw2DSetColour(0xff0077ff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
							break;
						case 2:
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
							Iw2DSetColour(0xff0077ff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
							break;
						case 3:
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(0,0),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(150,0),CIwFVec2(150,150));
							Iw2DSetColour(0xff0077ff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.19f-control_button_size.x/2),control_button_size,CIwFVec2(300,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							break;
					}

					switch (music)
					{
						case 1:
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
							Iw2DSetColour(0xff0077ff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							break;
						case 2:
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DSetColour(0xff0077ff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							break;
						case 3:
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(0,150),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DSetColour(0xff0077ff);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							break;
						default:
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(150,150),CIwFVec2(150,150));
							Iw2DSetColour(0xff777777);
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.40f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.50f-control_button_size.x/2),control_button_size,CIwFVec2(450,0),CIwFVec2(150,150));
							Iw2DSetColour(0xffffffff);
							break;
					}
			
					if (sound == 1)
					{
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(600,0),CIwFVec2(150,150));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(600,150),CIwFVec2(150,150));
					}
					if (vibration == 1)
					{
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(300,150),CIwFVec2(150,150));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_controls(),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.80f,Iw2DGetSurfaceHeight()*0.83f-control_button_size.x/2),control_button_size,CIwFVec2(450,150),CIwFVec2(150,150));
					}
				}
				else if(trans_dir == -2)
				{
					trans_pos -= g_speed;
					if (trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 2;
					}
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
				}
				else if(trans_dir == 2)
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2)
					{
						trans_pos = Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2;
						page = 1;
						menu_trans = 0;
					}
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
				}*/

				break;
			case 13:

				Iw2DDrawImage(getresource->get_about(),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));

				if(trans_dir == -1)
				{
					trans_pos += g_speed*1.5f;
					if(trans_pos >= Iw2DGetSurfaceWidth())
					{
						page = 1;
						menu_trans = 0;
					}
					Iw2DDrawImage(getresource->get_menu_bg(),CIwFVec2(0,0),CIwFVec2(trans_pos,(float)Iw2DGetSurfaceHeight()));
					Iw2DDrawImage(getresource->get_fb_button(),CIwFVec2(trans_pos*0.05f,0),CIwFVec2(trans_pos*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
					Iw2DDrawImage(getresource->get_rate_button(),CIwFVec2(2.5f*(trans_pos*0.05f),0),CIwFVec2(trans_pos*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(0,96),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
				}
				/*if(trans_dir == -1)
				{
					trans_pos += g_speed;
					if(trans_pos >= Iw2DGetSurfaceWidth())
					{
						trans_dir = -2;	
					}

					Iw2DDrawImage(getresource->get_select_bg(),CIwFVec2(trans_pos,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
				}
				else if(trans_dir == -2)
				{
					trans_pos -= g_speed;
					if (trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 2;
					}
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
				}
				else if(trans_dir == 2)
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2)
					{
						trans_pos = Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2;
						page = 1;
						menu_trans = 0;
					}
					Iw2DSetColour(0xaaffffff);
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,0),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,96),CIwFVec2(325,96));
					Iw2DSetColour(0xffffffff);
				}*/
				break;
	
			case 111:
	
				Iw2DSetColour(0xaaffffff);
				if(trans_dir == -1)
				{
					trans_pos -= g_speed;
					if (trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 1;
					}
					if(resume_campiagn == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,384),CIwFVec2(325,96));
						Iw2DSetColour(0xff000000);
						sprintf(print,"HIGHSCORE\n%d",highscore_ca);
						Iw2DDrawString(print,CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.75f-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,384),CIwFVec2(325,96));
						Iw2DSetColour(0xff000000);
						sprintf(print,"HIGHSCORE\n%d",highscore_ca);
						Iw2DDrawString(print,CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
					}
				}
				else if(trans_dir == 1)
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth())
					{
						trans_dir = -2;
					}
					if(resume_campiagn == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,384),CIwFVec2(325,96));
						Iw2DSetColour(0xff000000);
						sprintf(print,"HIGHSCORE\n%d",highscore_ca);
						Iw2DDrawString(print,CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.75f-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,384),CIwFVec2(325,96));
						Iw2DSetColour(0xff000000);
						sprintf(print,"HIGHSCORE\n%d",highscore_ca);
						Iw2DDrawString(print,CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
					}
				}
				else if (trans_dir == -2)
				{
					trans_pos -= g_speed;
					if(trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 2;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				else
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2)
					{
						trans_pos = Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2;
						page = 11;
						menu_trans = 0;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				Iw2DSetColour(0xffffffff);
	
				break;
			case 112:

				Iw2DSetColour(0xaaffffff);
				if(trans_dir == -1)
				{
					trans_pos -= g_speed;
					if (trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 1;
					}
					
					if(resume_classic == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.15f,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawString("LEVEL",CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*3/5-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x/2,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
						Iw2DSetColour(0xaaffffff);
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));
								break;
							case 2:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(100,0),CIwFVec2(100,100));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(200,0),CIwFVec2(100,100));
							break;
						}
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawString("LEVEL",CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x/2,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
						Iw2DSetColour(0xaaffffff);
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));
								break;
							case 2:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(100,0),CIwFVec2(100,100));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(200,0),CIwFVec2(100,100));
								break;
						}
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
				}
				else if(trans_dir == 1)
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth())
					{
						trans_dir = -2;
					}
					
					if(resume_classic == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.15f,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawString("LEVEL",CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*3/5-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x/2,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
						Iw2DSetColour(0xaaffffff);
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));
								break;
							case 2:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(100,0),CIwFVec2(100,100));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(200,0),CIwFVec2(100,100));
							break;
						}
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						//Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DSetColour(0xffffffff);
						Iw2DDrawString("LEVEL",CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-((float)getresource->get_font()->GetHeight())/2),CIwFVec2(menu_button_size.x/2,(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
						Iw2DSetColour(0xaaffffff);
						switch (level_cl)
						{
							case 1:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(0,0),CIwFVec2(100,100));
								break;
							case 2:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(100,0),CIwFVec2(100,100));
								break;
							case 3:
								Iw2DDrawImageRegion(getresource->get_level(),CIwFVec2(trans_pos*1.05f+menu_button_size.x*0.75f-menu_button_size.y/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(menu_button_size.y,menu_button_size.y),CIwFVec2(200,0),CIwFVec2(100,100));
								break;
						}
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
				}
				else if (trans_dir == -2)
				{
					trans_pos -= g_speed;
					if(trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 2;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				else
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2)
					{
						trans_pos = Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2;
						page = 11;
						menu_trans = 0;
					}
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/3-menu_button_size.y/2),menu_button_size,CIwFVec2(0,192),CIwFVec2(325,96));
					Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*2/3-menu_button_size.y/2),menu_button_size,CIwFVec2(325,96),CIwFVec2(325,96));
				}
				Iw2DSetColour(0xffffffff);
	
				break;
			case 1124:

				Iw2DDrawImage(getresource->get_select_bg(),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
				switch (slide_select_curr)
				{
					case 0:
	
						Iw2DDrawImage(getresource->get_bg(0),CIwFVec2(Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
						Iw2DDrawImage(getresource->get_bg(1),CIwFVec2(Iw2DGetSurfaceWidth()*0.85f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
	
						break;
					case 8:
	
						Iw2DDrawImage(getresource->get_bg(7),CIwFVec2(-Iw2DGetSurfaceWidth()*0.15f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
						Iw2DDrawImage(getresource->get_bg(8),CIwFVec2(Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
	
						break;
					default:
	
						Iw2DDrawImage(getresource->get_bg(slide_select_curr-1),CIwFVec2(-Iw2DGetSurfaceWidth()*0.15f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
						Iw2DDrawImage(getresource->get_bg(slide_select_curr),CIwFVec2(Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
						Iw2DDrawImage(getresource->get_bg(slide_select_curr+1),CIwFVec2(Iw2DGetSurfaceWidth()*0.85f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
	
						break;
				}

				if(trans_dir == -1)
				{
					trans_pos += g_speed*1.5f;
					if(trans_pos >= Iw2DGetSurfaceWidth())
					{
						page = 112;
						menu_trans = 0;
					}
					Iw2DDrawImage(getresource->get_menu_bg(),CIwFVec2(0,0),CIwFVec2(trans_pos,(float)Iw2DGetSurfaceHeight()));
					Iw2DDrawImage(getresource->get_fb_button(),CIwFVec2(trans_pos*0.05f,0),CIwFVec2(trans_pos*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
					Iw2DDrawImage(getresource->get_rate_button(),CIwFVec2(2.5f*(trans_pos*0.05f),0),CIwFVec2(trans_pos*0.05f,Iw2DGetSurfaceWidth()*0.05f*1.32f));
					
					Iw2DSetColour(0xaaffffff);
					if(resume_classic == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,288),CIwFVec2(325,96));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*0.80f-(trans_pos*0.253f)/2,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),CIwFVec2(trans_pos*0.253f,menu_button_size.y),CIwFVec2(325,288),CIwFVec2(325,96));
					}
					Iw2DSetColour(0xffffffff);
				}

				/*if(trans_dir == -1)
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth()+Iw2DGetSurfaceWidth()*0.15f)
					{
						trans_dir = -2;
					}
					Iw2DDrawImage(getresource->get_select_bg(),CIwFVec2(trans_pos,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
					switch (slide_select_curr)
					{
						case 0:
		
							Iw2DDrawImage(getresource->get_bg(0),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
							Iw2DDrawImage(getresource->get_bg(1),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.85f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
		
							break;
						case 8:
		
							Iw2DDrawImage(getresource->get_bg(7),CIwFVec2(trans_pos - Iw2DGetSurfaceWidth()*0.15f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
							Iw2DDrawImage(getresource->get_bg(8),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
		
							break;
						default:
		
							Iw2DDrawImage(getresource->get_bg(slide_select_curr-1),CIwFVec2(trans_pos - Iw2DGetSurfaceWidth()*0.15f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
							Iw2DDrawImage(getresource->get_bg(slide_select_curr),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.20f,Iw2DGetSurfaceHeight()*0.20f),CIwFVec2(Iw2DGetSurfaceWidth()*0.60f,Iw2DGetSurfaceHeight()*0.60f));
							Iw2DDrawImage(getresource->get_bg(slide_select_curr+1),CIwFVec2(trans_pos + Iw2DGetSurfaceWidth()*0.85f,Iw2DGetSurfaceHeight()*0.35f),CIwFVec2(Iw2DGetSurfaceWidth()*0.30f,Iw2DGetSurfaceHeight()*0.30f));
		
							break;
					}
				}
				else if (trans_dir == -2)
				{
					trans_pos -= g_speed;
					if(trans_pos <= Iw2DGetSurfaceWidth()*0.65f)
					{
						trans_dir = 2;
					}
					Iw2DSetColour(0xaaffffff);
					if(resume_classic == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.15f,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
				}
				else
				{
					trans_pos += g_speed;
					if (trans_pos >= Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2)
					{
						trans_pos = Iw2DGetSurfaceWidth()*0.80f-menu_button_size.x/2;
						page = 112;
						menu_trans = 0;
					}
					Iw2DSetColour(0xaaffffff);
					if(resume_classic == 1)
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*1/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,384),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*2/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*3/5-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.15f,Iw2DGetSurfaceHeight()*4/5-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
					else
					{
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos,Iw2DGetSurfaceHeight()*0.25f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,192),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.05f,Iw2DGetSurfaceHeight()*0.50f-menu_button_size.y/2),menu_button_size,CIwFVec2(0,288),CIwFVec2(325,96));
						Iw2DDrawImageRegion(getresource->get_menu_buttons(),CIwFVec2(trans_pos*1.1f,Iw2DGetSurfaceHeight()*0.75f-menu_button_size.y/2),menu_button_size,CIwFVec2(325,288),CIwFVec2(325,96));
					}
				}
				Iw2DSetColour(0xffffffff);*/
	
				break;
		}
	}
}