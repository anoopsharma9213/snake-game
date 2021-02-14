#include "game.h"

//--------------------------------------------------------------------------------------------------------
//-------------------------GamePlay Page Updation Control 1---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

void CGame::play_Page_Update()
{
	if((s3eKeyboardGetState(s3eKeyBack) | s3eKeyboardGetState(s3eKeyEsc)) & S3E_KEY_STATE_PRESSED)
	{
		if(over == 1)
		{
			reset();
		}
		else
		{
			page = 1;
		}
		s3eKeyboardClearState();
	}

	switch (control_select)
	{
		case 2:
			if((END->dir == 1 || END->dir == -1))
			{
				if((s3eKeyboardGetState(s3eKeyUp) | s3eKeyboardGetState(s3eKey2)) & S3E_KEY_STATE_PRESSED)
				{
					b_select = 1;
					s3eKeyboardClearState();
				}
				else if((s3eKeyboardGetState(s3eKeyDown) | s3eKeyboardGetState(s3eKey8)) & S3E_KEY_STATE_PRESSED)
				{
					b_select = 2;
					s3eKeyboardClearState();
				}
			}
			else if((END->dir == 2 || END->dir == -2))
			{
				if((s3eKeyboardGetState(s3eKeyLeft) | s3eKeyboardGetState(s3eKey4)) & S3E_KEY_STATE_PRESSED)
				{
					b_select = 3;
					s3eKeyboardClearState();
				}
				else if((s3eKeyboardGetState(s3eKeyRight) | s3eKeyboardGetState(s3eKey6)) & S3E_KEY_STATE_PRESSED)
				{
					b_select = 4;
					s3eKeyboardClearState();
				}
			}

			if((s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN))
		{
			if(k_show == 0 && over == 0)
			{
				k_show = 1;
				k_point.x = (float)s3ePointerGetX();
				k_point.y = (float)s3ePointerGetY();
				k_drag = k_point;
			}
			else if((END->dir == 1 || END->dir == -1)  && over == 0 && k_show != 0)
			{
				if( (((k_point.x - s3ePointerGetX())*(k_point.x - s3ePointerGetX()))+((k_point.y - s3ePointerGetY())*(k_point.y - s3ePointerGetY()))) <= ((k_size.x*1.5f) * (k_size.x*1.5f)) )
				{
					k_drag.x = (float)s3ePointerGetX();
					k_drag.y = (float)s3ePointerGetY();
				}
				else
				{
					k_drag.x = (k_point.x + (((k_size.x*1.5f)*(s3ePointerGetX()-k_point.x))/((float)sqrt((double)( ((k_point.x - s3ePointerGetX())*(k_point.x - s3ePointerGetX()))+((k_point.y - s3ePointerGetY())*(k_point.y - s3ePointerGetY())) )))));
					k_drag.y = (k_point.y + (((k_size.x*1.5f)*(s3ePointerGetY()-k_point.y))/((float)sqrt((double)( ((k_point.x - s3ePointerGetX())*(k_point.x - s3ePointerGetX()))+((k_point.y - s3ePointerGetY())*(k_point.y - s3ePointerGetY())) )))));
				}

				if(k_drag.x>=k_point.x - k_size.x*0.5f && 
					k_drag.x<=k_point.x + k_size.x*0.5f &&
					k_drag.y>=k_point.y - k_size.x*1.5f &&
					k_drag.y<=k_point.y - k_size.x*0.5f)
				{
					b_select = 1;
				}
				else if(k_drag.x>=k_point.x - k_size.x*0.5f && 
					k_drag.x<=k_point.x + k_size.x*0.5f &&
					k_drag.y>=k_point.y + k_size.x*0.5f &&
					k_drag.y<=k_point.y + k_size.x*1.5f)
				{
					b_select = 2;
				}
			}
			else if((END->dir == 2 || END->dir == -2)  && over == 0 && k_show != 0)
			{
				if( (((k_point.x - s3ePointerGetX())*(k_point.x - s3ePointerGetX()))+((k_point.y - s3ePointerGetY())*(k_point.y - s3ePointerGetY()))) <= ((k_size.x*1.5f) * (k_size.x*1.5f)) )
				{
					k_drag.x = (float)s3ePointerGetX();
					k_drag.y = (float)s3ePointerGetY();
				}
				else
				{
					k_drag.x = (k_point.x + (((k_size.x*1.5f)*(s3ePointerGetX()-k_point.x))/((float)sqrt((double)( ((k_point.x - s3ePointerGetX())*(k_point.x - s3ePointerGetX()))+((k_point.y - s3ePointerGetY())*(k_point.y - s3ePointerGetY())) )))));
					k_drag.y = (k_point.y + (((k_size.x*1.5f)*(s3ePointerGetY()-k_point.y))/((float)sqrt((double)( ((k_point.x - s3ePointerGetX())*(k_point.x - s3ePointerGetX()))+((k_point.y - s3ePointerGetY())*(k_point.y - s3ePointerGetY())) )))));
				}

				if(k_drag.x>=k_point.x - k_size.x*1.5f && 
					k_drag.x<=k_point.x - k_size.x*0.5f &&
					k_drag.y>=k_point.y - k_size.x*0.5f &&
					k_drag.y<=k_point.y + k_size.x*0.5f)
				{
					b_select = 3;
				}
				else if(k_drag.x>=k_point.x + k_size.x*0.5f && 
					k_drag.x<=k_point.x + k_size.x*1.5f &&
					k_drag.y>=k_point.y - k_size.x*0.5f &&
					k_drag.y<=k_point.y + k_size.x*0.5f)
				{
					b_select = 4;
				}
			}	
		}
	else if((s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_RELEASED))
	{
		k_show = 0;
	}
			break;
		case 3:
			if((s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN))
		{
			if((END->dir == 1 || END->dir == -1)  && over == 0)
			{
				if((s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f+Iw2DGetSurfaceWidth()*0.1f) ||
					(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.1f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.1f+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f+Iw2DGetSurfaceWidth()*0.1f))
				{
					b_select = 1;
				}
				else if((s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f+Iw2DGetSurfaceWidth()*0.1f) ||
					(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.1f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.1f+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f+Iw2DGetSurfaceWidth()*0.1f))
				{
					b_select = 2;
				}
			}
			else if((END->dir == 2 || END->dir == -2)  && over == 0)
			{
				if((s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2+Iw2DGetSurfaceWidth()*0.1f) ||
					(s3ePointerGetX()>=0 && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2+Iw2DGetSurfaceWidth()*0.1f))
				{
					b_select = 3;
				}
				else if((s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.7f+2.0f*(Iw2DGetSurfaceWidth()*0.1f) && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.7f+2.0f*(Iw2DGetSurfaceWidth()*0.1f)+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2+Iw2DGetSurfaceWidth()*0.1f) ||
					(s3ePointerGetX()>=2.0f*(Iw2DGetSurfaceWidth()*0.1f) && 
					s3ePointerGetX()<=2.0f*(Iw2DGetSurfaceWidth()*0.1f)+Iw2DGetSurfaceWidth()*0.1f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2+Iw2DGetSurfaceWidth()*0.1f))
				{
					b_select = 4;
				}
			}
			
			

			
		}
			break;
		case 1:
			if((s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_RELEASED))
		{
			if((END->dir == 1 || END->dir == -1)  && over == 0)
			{
				if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.25f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.75f &&
					s3ePointerGetY()>=0 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.50f)
				{
					b_select = 1;
				}
				else if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.25f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.75f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.50f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight())
				{
					b_select = 2;
				}
			}
			else if((END->dir == 2 || END->dir == -2)  && over == 0)
			{
				if(s3ePointerGetX()>=0 && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.25f &&
					s3ePointerGetY()>=0 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight())
				{
					b_select = 3;
				}
				else if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.75f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth() &&
					s3ePointerGetY()>=0 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight())
				{
					b_select = 4;
				}
			}

			
		}if((s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_RELEASED))
		{
			if((END->dir == 1 || END->dir == -1)  && over == 0)
			{
				if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.25f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.75f &&
					s3ePointerGetY()>=0 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.50f)
				{
					b_select = 1;
				}
				else if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.25f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.75f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.50f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight())
				{
					b_select = 2;
				}
			}
			else if((END->dir == 2 || END->dir == -2)  && over == 0)
			{
				if(s3ePointerGetX()>=0 && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.25f &&
					s3ePointerGetY()>=0 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight())
				{
					b_select = 3;
				}
				else if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.75f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth() &&
					s3ePointerGetY()>=0 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight())
				{
					b_select = 4;
				}
			}

			
		}
			break;
	}

	

	if(c%15 == 0 && over == 0)
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
			for(var=1, b_dir = START; var<block-1; var++,b_dir=b_dir->next)
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
			for (int i = 0; i < wall_max; i++)
				{
					if(((int)a_move.x==(int)(beg.x+b_size.x+w_position[i].x*g_size.x)) & ((int)a_move.y == (int)(beg.y+b_size.x+w_position[i].y*g_size.y)))
					{
						over = 1;
						if(s3eVibraGetInt(S3E_VIBRA_AVAILABLE) == 1)
						{
							s3eVibraVibrate(255,500);
						}
						break;
					}
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
				for(var=0, b_dir = START;var<block-1;var++,b_dir=b_dir->next)
				{
					b_dir->dir = b_dir->next->dir;
				}
				if(((int)a_move.x==(int)(beg.x+b_size.x+f_Position.x*g_size.x)) & ((int)a_move.y == (int)(beg.y+b_size.x+f_Position.y*g_size.y)))
				{
					block++;
					_score+=10;
					food_init();

					b_dir = new Direction;
					b_dir->dir = END->dir;
					b_dir->next = NULL;
					END->next = b_dir;
					END = b_dir;
				}
			}
			}
			else if(c == 20)
					{
						c++;
						switch (f_dir)
						{
							case 1:
								if(maze_select != 0)
								{
									for (int i = 0; i < wall_max; i++)
									{
										if(((int)(beg.x+b_size.x+w_position[i].x*g_size.x)==(int)(beg.x+b_size.x+f_Position.x*g_size.x + g_size.x)) & ((int)(beg.x+b_size.x+w_position[i].y*g_size.x) == (int)(beg.y+b_size.x+f_Position.y*g_size.y)))
										{
											if(rand()%100 > 50)
											{
												f_dir = 2;
											}
											else
											{
												f_dir = -2;
											}
										}
									}
								}
								break;
							case -1:
								if(maze_select != 0)
								{
									for (int i = 0; i < wall_max; i++)
									{
										if(((int)(beg.x+b_size.x+w_position[i].x*g_size.x)==(int)(beg.x+b_size.x+f_Position.x*g_size.x - g_size.x)) & ((int)(beg.x+b_size.x+w_position[i].y*g_size.x) == (int)(beg.y+b_size.x+f_Position.y*g_size.y)))
										{
											if(rand()%100 > 50)
											{
												f_dir = 2;
											}
											else
											{
												f_dir = -2;
											}
										}
									}
								}
								break;
							case 2:
								if(maze_select != 0)
								{
									for (int i = 0; i < wall_max; i++)
									{
										if(((int)(beg.x+b_size.x+w_position[i].x*g_size.x)==(int)(beg.x+b_size.x+f_Position.x*g_size.x)) & ((int)(beg.x+b_size.x+w_position[i].y*g_size.x) == (int)(beg.y+b_size.x+f_Position.y*g_size.y + g_size.y)))
										{
											if(rand()%100 > 50)
											{
												f_dir = 1;
											}
											else
											{
												f_dir = -1;
											}
										}
									}
								}
								break;
							case -2:
								if(maze_select != 0)
								{
									for (int i = 0; i < wall_max; i++)
									{
										if(((int)(beg.x+b_size.x+w_position[i].x*g_size.x)==(int)(beg.x+b_size.x+f_Position.x*g_size.x)) & ((int)(beg.x+b_size.x+w_position[i].y*g_size.x) == (int)(beg.y+b_size.x+f_Position.y*g_size.y - g_size.y)))
										{
											if(rand()%100 > 50)
											{
												f_dir = 1;
											}
											else
											{
												f_dir = -1;
											}
										}
									}
								}
								break;
						}

						switch (f_dir)
						{
							case 1:
								f_Position.x ++;
								if(f_Position.x >= row)
									f_Position.x = 0;
								/*if(maze_select != 0)
								{
									for (int i = 0; i < wall_max; i++)
									{
										if(((int)(beg.x+b_size.x+w_position[i].x*g_size.x)==(int)(beg.x+b_size.x+f_Position.x*g_size.x + g_size.x)) & ((int)(beg.x+b_size.x+w_position[i].y*g_size.x) == (int)(beg.y+b_size.x+f_Position.y*g_size.y)))
										{
											if(rand()%100 > 50)
											{
												f_dir = 2;
											}
											else
											{
												f_dir = -2;
											}
										}
									}
								}
								*/
								if(f_step > 10)
								{
									if(rand()%100 > 60)
									{
										f_dir = 2;
									}
									else if(rand()%100 > 80)
									{
										f_dir = -2;
									}
									f_step = 0;
								}
								break;
							case -1:
								f_Position.x --;
								if(f_Position.x < 0)
									f_Position.x = (float)row-1;
								/*if(maze_select != 0)
								{
									for (int i = 0; i < wall_max; i++)
									{
										if(((int)(beg.x+b_size.x+w_position[i].x*g_size.x)==(int)(beg.x+b_size.x+f_Position.x*g_size.x - g_size.x)) & ((int)(beg.x+b_size.x+w_position[i].y*g_size.x) == (int)(beg.y+b_size.x+f_Position.y*g_size.y)))
										{
											if(rand()%100 > 50)
											{
												f_dir = 2;
											}
											else
											{
												f_dir = -2;
											}
										}
									}
								}*/
								if(f_step > 10)
								{
									if(rand()%100 > 60)
									{
										f_dir = 2;
									}
									else if(rand()%100 > 80)
									{
										f_dir = -2;
									}
									f_step = 0;
								}
								break;
							case 2:
								f_Position.y ++;
								if(f_Position.y >= col)
									f_Position.y = 0;
								/*if(maze_select != 0)
								{
									for (int i = 0; i < wall_max; i++)
									{
										if(((int)(beg.x+b_size.x+w_position[i].x*g_size.x)==(int)(beg.x+b_size.x+f_Position.x*g_size.x)) & ((int)(beg.x+b_size.x+w_position[i].y*g_size.x) == (int)(beg.y+b_size.x+f_Position.y*g_size.y + g_size.y)))
										{
											if(rand()%100 > 50)
											{
												f_dir = 1;
											}
											else
											{
												f_dir = -1;
											}
										}
									}
								}*/
								if(f_step > 10)
								{
									if(rand()%100 > 60)
									{
										f_dir = 1;
									}
									else if(rand()%100 > 80)
									{
										f_dir = -1;
									}
									f_step = 0;
								}
								break;
							case -2:
								f_Position.y --;
								if(f_Position.y < 0)
									f_Position.y = (float)col-1;
								/*if(maze_select != 0)
								{
									for (int i = 0; i < wall_max; i++)
									{
										if(((int)(beg.x+b_size.x+w_position[i].x*g_size.x)==(int)(beg.x+b_size.x+f_Position.x*g_size.x)) & ((int)(beg.x+b_size.x+w_position[i].y*g_size.x) == (int)(beg.y+b_size.x+f_Position.y*g_size.y - g_size.y)))
										{
											if(rand()%100 > 50)
											{
												f_dir = 1;
											}
											else
											{
												f_dir = -1;
											}
										}
									}
								}*/
								if(f_step > 10)
								{
									if(rand()%100 > 60)
									{
										f_dir = 1;
									}
									else if(rand()%100 > 80)
									{
										f_dir = -1;
									}
									f_step = 0;
								}
								break;
						}
						f_step++;
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

//--------------------------------------------------------------------------------------------------------
//-------------------------GamePlay Page Draw Control 1---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

void CGame::play_Page()
{
	

	Iw2DDrawImage(getresource->get_bg(maze_select),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
	Iw2DSetColour(0x77000000);
	Iw2DDrawImage(getresource->get_frame(),CIwFVec2(beg.x+b_size.x,beg.y+b_size.x),CIwFVec2(length,breadth));
	Iw2DSetColour(0xffffffff);

	switch (control_select)
	{
		case 2:
			if(k_show == 1)
	{
		Iw2DSetColour(0x77ffffff);
		k_pos.x = k_point.x - k_size.x*0.5f;
		k_pos.y = k_point.y - k_size.x*1.5f;
		Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(384,0),CIwFVec2(128,128));

		k_pos.x = k_point.x - k_size.x*0.5f + k_size.x*0.5f;
		k_pos.y = k_point.y + k_size.x*0.5f + k_size.y*0.5f;
		rot.SetRot(PI,k_pos);
		Iw2DSetTransformMatrix(rot);

		k_pos.x = k_point.x - k_size.x*0.5f;
		k_pos.y = k_point.y + k_size.x*0.5f;
		Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(384,0),CIwFVec2(128,128));
	
		k_pos.x = k_point.x - k_size.x*1.5f + k_size.x*0.5f;
		k_pos.y = k_point.y - k_size.x*0.5f + k_size.y*0.5f;
		rot.SetRot(3*PI/2,k_pos);
		Iw2DSetTransformMatrix(rot);
	
		k_pos.x = k_point.x - k_size.x*1.5f;
		k_pos.y = k_point.y - k_size.x*0.5f;
		Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(384,0),CIwFVec2(128,128));
	
		k_pos.x = k_point.x + k_size.x*0.5f + k_size.x*0.5f;
		k_pos.y = k_point.y - k_size.x*0.5f + k_size.y*0.5f;
		rot.SetRot(PI/2,k_pos);
		Iw2DSetTransformMatrix(rot);
	
		k_pos.x = k_point.x + k_size.x*0.5f;
		k_pos.y = k_point.y - k_size.x*0.5f;
		Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(384,0),CIwFVec2(128,128));
	
		Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
		Iw2DSetColour(0xffff0000);
		Iw2DDrawArc(k_point,k_size*1.5f,0,2*PI);
		Iw2DFillArc(k_drag,k_size*0.5f,0,2*PI);
		Iw2DSetColour(0xffffffff);
	}
			break;
		case 3:
			Iw2DSetColour(0x44ffffff);
	k_pos.x = Iw2DGetSurfaceWidth()*0.7f + k_size.x;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*1.5f;
	Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(512,0),CIwFVec2(128,128));
	k_pos.x = k_size.x;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*1.5f;
	Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(512,0),CIwFVec2(128,128));

	k_pos.x = Iw2DGetSurfaceWidth()*0.7f + k_size.x + k_size.x*0.5f;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f + k_size.x*0.5f + k_size.y*0.5f;
	rot.SetRot(PI,k_pos);
	Iw2DSetTransformMatrix(rot);

	k_pos.x = Iw2DGetSurfaceWidth()*0.7f + k_size.x;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f + k_size.x*0.5f;
	Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(512,0),CIwFVec2(128,128));

	k_pos.x = k_size.x + k_size.x*0.5f;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f + k_size.x*0.5f + k_size.y*0.5f;
	rot.SetRot(PI,k_pos);
	Iw2DSetTransformMatrix(rot);

	k_pos.x = k_size.x;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f + k_size.x*0.5f;
	Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(512,0),CIwFVec2(128,128));

	k_pos.x = Iw2DGetSurfaceWidth()*0.7f + k_size.x*0.5f;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*0.5f + k_size.y*0.5f;
	rot.SetRot(3*PI/2,k_pos);
	Iw2DSetTransformMatrix(rot);

	k_pos.x = Iw2DGetSurfaceWidth()*0.7f;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*0.5f;
	Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(512,0),CIwFVec2(128,128));

	k_pos.x = k_size.x*0.5f;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*0.5f + k_size.y*0.5f;
	rot.SetRot(3*PI/2,k_pos);
	Iw2DSetTransformMatrix(rot);

	k_pos.x = 0;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*0.5f;
	Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(512,0),CIwFVec2(128,128));
	
	k_pos.x = Iw2DGetSurfaceWidth()*0.7f + 2*k_size.x + k_size.x*0.5f;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*0.5f + k_size.y*0.5f;
	rot.SetRot(PI/2,k_pos);
	Iw2DSetTransformMatrix(rot);

	k_pos.x = Iw2DGetSurfaceWidth()*0.7f + 2*k_size.x;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*0.5f;
	Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(512,0),CIwFVec2(128,128));

	k_pos.x = 2*k_size.x + k_size.x*0.5f;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*0.5f + k_size.y*0.5f;
	rot.SetRot(PI/2,k_pos);
	Iw2DSetTransformMatrix(rot);

	k_pos.x = 2*k_size.x;
	k_pos.y = Iw2DGetSurfaceHeight()*0.5f - k_size.x*0.5f;
	Iw2DDrawImageRegion(getresource->get_key(),k_pos,k_size,CIwFVec2(512,0),CIwFVec2(128,128));

	Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
			break;
		case 1:
			Iw2DSetColour(0x77ffffff);
	if((s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN))
		{
			if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.25f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.75f &&
					s3ePointerGetY()>=0 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.50f)
				{
					Iw2DFillRect(CIwFVec2(Iw2DGetSurfaceWidth()*0.25f,0),CIwFVec2(Iw2DGetSurfaceWidth()*0.50f,Iw2DGetSurfaceHeight()*0.50f));
				}
				else if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.25f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.75f &&
					s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.50f &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight())
				{
					Iw2DFillRect(CIwFVec2(Iw2DGetSurfaceWidth()*0.25f,Iw2DGetSurfaceHeight()*0.50f),CIwFVec2(Iw2DGetSurfaceWidth()*0.50f,Iw2DGetSurfaceHeight()*0.50f));
				}
			else if(s3ePointerGetX()>=0 && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.25f &&
					s3ePointerGetY()>=0 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight())
				{
					Iw2DFillRect(CIwFVec2(0,0),CIwFVec2(Iw2DGetSurfaceWidth()*0.25f,(float)Iw2DGetSurfaceHeight()));
				}
				else if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.75f && 
					s3ePointerGetX()<=Iw2DGetSurfaceWidth() &&
					s3ePointerGetY()>=0 &&
					s3ePointerGetY()<=Iw2DGetSurfaceHeight())
				{
					Iw2DFillRect(CIwFVec2(Iw2DGetSurfaceWidth()*0.75f,0),CIwFVec2(Iw2DGetSurfaceWidth()*0.25f,(float)Iw2DGetSurfaceHeight()));
				}

			
		}
			break;
	}
	 
	Iw2DSetColour(0xffffffff);
	Iw2DSetFont(getresource->get_font());
	//sprintf(print,"SCORE : %.0f %.0f",f_Position.x,f_Position.y);
	sprintf(print,"Score : %.0f",_score);
	Iw2DDrawString(print,CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)(getresource->get_font()->GetHeight())),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);

	
	for (int i = 0; i < wall_max; i++)
	{
		f_temp = CIwFVec2(beg.x+b_size.x+w_position[i].x*g_size.x,beg.y+b_size.x+w_position[i].y*g_size.y) + g_size/2;
		rot.SetRot(PI*wall_rotate/4,f_temp);
		Iw2DSetTransformMatrix(rot);
		f_temp = CIwFVec2(beg.x+b_size.x+w_position[i].x*g_size.x,beg.y+b_size.x+w_position[i].y*g_size.y);
		Iw2DDrawImage(getresource->get_wall(),CIwFVec2(beg.x+b_size.x+w_position[i].x*g_size.x,beg.y+b_size.x+w_position[i].y*g_size.y),g_size);
		Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
	}

	//wall_rotate++;
	if (wall_rotate == 8)
	{
		wall_rotate = 0;
	}

	//Iw2DDrawImageRegion(getresource->get_food(),CIwFVec2(beg.x+b_size.x+f_Position.x*g_size.x,beg.y+b_size.x+f_Position.y*g_size.y),f_Size,CIwFVec2(0,0),CIwFVec2(30,30));
	switch (f_dir)
	{
		case 1:
			f_temp = CIwFVec2(beg.x+b_size.x+f_Position.x*g_size.x,beg.y+b_size.x+f_Position.y*g_size.y) + f_Size/2;
			rot.SetRot(PI/2,f_temp);
			Iw2DSetTransformMatrix(rot);
			f_temp.x = beg.x+b_size.x+f_Position.x*g_size.x;
			f_temp.y = beg.y+b_size.x+f_Position.y*g_size.y;
			Iw2DDrawImage(getresource->get_food(),CIwFVec2(beg.x+b_size.x+f_Position.x*g_size.x,beg.y+b_size.x+f_Position.y*g_size.y),f_Size);
			Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
			break;
		case -1:
			f_temp = CIwFVec2(beg.x+b_size.x+f_Position.x*g_size.x,beg.y+b_size.x+f_Position.y*g_size.y) + f_Size/2;
			rot.SetRot(3*PI/2,f_temp);
			Iw2DSetTransformMatrix(rot);
			f_temp.x = beg.x+b_size.x+f_Position.x*g_size.x;
			f_temp.y = beg.y+b_size.x+f_Position.y*g_size.y;
			Iw2DDrawImage(getresource->get_food(),CIwFVec2(beg.x+b_size.x+f_Position.x*g_size.x,beg.y+b_size.x+f_Position.y*g_size.y),f_Size);
			Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
			break;
		case 2:
			f_temp = CIwFVec2(beg.x+b_size.x+f_Position.x*g_size.x,beg.y+b_size.x+f_Position.y*g_size.y) + f_Size/2;
			rot.SetRot(PI,f_temp);
			Iw2DSetTransformMatrix(rot);
			f_temp.x = beg.x+b_size.x+f_Position.x*g_size.x;
			f_temp.y = beg.y+b_size.x+f_Position.y*g_size.y;
			Iw2DDrawImage(getresource->get_food(),CIwFVec2(beg.x+b_size.x+f_Position.x*g_size.x,beg.y+b_size.x+f_Position.y*g_size.y),f_Size);
			Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
			break;
		case -2:
			Iw2DDrawImage(getresource->get_food(),CIwFVec2(beg.x+b_size.x+f_Position.x*g_size.x,beg.y+b_size.x+f_Position.y*g_size.y),f_Size);
			break;
	}

	a_move = move;
	//Iw2DDrawImageRegion(getresource->get_body(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
	switch (START->dir)
			{
				case 1:
					a_move = a_move + g_size/2;
					rot.SetRot(PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_tail(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
					break;
				case -1:
					a_move = a_move + g_size/2;
					rot.SetRot(3*PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_tail(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
					break;
				case 2:
					a_move = a_move + g_size/2;
					rot.SetRot(PI,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_tail(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
					break;
				case -2:
					Iw2DDrawImageRegion(getresource->get_tail(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					break;
			}

	for(var=1, b_dir = START; var<block; var++,b_dir=b_dir->next)
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
		if(var==block-1)
		{
			switch (b_dir->dir)
			{
				case 1:
					a_move = a_move + g_size/2;
					rot.SetRot(PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_head(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					
					a_move.x = a_move.x+g_size.x;
					a_move = a_move + g_size/2;
					rot.SetRot(PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_tongue(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
					a_move.x = a_move.x-g_size.x;
					break;
				case -1:
					a_move = a_move + g_size/2;
					rot.SetRot(3*PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_head(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					
					a_move.x = a_move.x-g_size.x;
					a_move = a_move + g_size/2;
					rot.SetRot(3*PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_tongue(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
					a_move.x = a_move.x+g_size.x;
					break;
				case 2:
					a_move = a_move + g_size/2;
					rot.SetRot(PI,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_head(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					
					a_move.y = a_move.y+g_size.y;
					a_move = a_move + g_size/2;
					rot.SetRot(PI,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_tongue(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
					a_move.y = a_move.y-g_size.y;
					break;
				case -2:
					Iw2DDrawImageRegion(getresource->get_head(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					a_move.y = a_move.y-g_size.y;
					Iw2DDrawImageRegion(getresource->get_tongue(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					a_move.y = a_move.y+g_size.y;
					break;
			}
		}
		else if (b_dir->dir != b_dir->next->dir)
		{
			if(b_dir->dir == 1)
			{
				if (b_dir->next->dir == -2)
				{
					a_move = a_move + g_size/2;
					rot.SetRot(3*PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_turn(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
				}
				else
				{
					a_move = a_move + g_size/2;
					rot.SetRot(PI,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_turn(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
				}
			}
			else if (b_dir->dir == -1)
			{
				if (b_dir->next->dir == -2)
				{
					Iw2DDrawImageRegion(getresource->get_turn(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
				}
				else
				{
					a_move = a_move + g_size/2;
					rot.SetRot(PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_turn(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
				}
			}
			else if (b_dir->dir == 2)
			{
				if (b_dir->next->dir == -1)
				{
					a_move = a_move + g_size/2;
					rot.SetRot(3*PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_turn(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
				}
				else
				{
					Iw2DDrawImageRegion(getresource->get_turn(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
				}
			}
			else if (b_dir->dir == -2)
			{
				if (b_dir->next->dir == -1)
				{
					a_move = a_move + g_size/2;
					rot.SetRot(PI,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_turn(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
				}
				else
				{
					a_move = a_move + g_size/2;
					rot.SetRot(PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_turn(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
				}
			}
		}
		else
		{
			switch (b_dir->dir)
			{
				case 1:
					a_move = a_move + g_size/2;
					rot.SetRot(PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_body(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
					break;
				case -1:
					a_move = a_move + g_size/2;
					rot.SetRot(3*PI/2,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_body(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
					break;
				case 2:
					a_move = a_move + g_size/2;
					rot.SetRot(PI,a_move);
					Iw2DSetTransformMatrix(rot);
					a_move = a_move - g_size/2;
					Iw2DDrawImageRegion(getresource->get_body(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					Iw2DSetTransformMatrix(CIwFMat2D::g_Identity);
					break;
				case -2:
					Iw2DDrawImageRegion(getresource->get_body(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
					break;
			}
		}
	}
}