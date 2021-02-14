#include "game.h"

//--------------------------------------------------------------------------------------------------------
//-------------------------Tutorial Page Updation Control 1---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

void CGame::tutorial_update()
{
	if (s3eKeyboardGetState(s3eKeyBack) & S3E_KEY_STATE_PRESSED)
	{
		page = 1;
		s3eKeyboardClearState();
	}
	if((s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN))
	{
		if(tutorial_check == 6)
		{
			page = 2;
			tutorial_show = 0;
		}
		else if(k_show == 0 && over == 0)
		{
			if(tutorial_check == 0)
			{
				tutorial_check = 1;
			}
			else
			{
				tutorial_check = -(tutorial_check);
			}
			k_show = 1;
			k_point.x = (float)s3ePointerGetX();
			k_point.y = (float)s3ePointerGetY();
			k_drag = k_point;
		}
		else if((END->dir == 1 || END->dir == -1) && k_show != 0)
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
				k_drag.y<=k_point.y - k_size.x*0.5f && tutorial_check == 3)
			{
				b_select = 1;
				tutorial_check = 4;
			}
			else if(k_drag.x>=k_point.x - k_size.x*0.5f && 
				k_drag.x<=k_point.x + k_size.x*0.5f &&
				k_drag.y>=k_point.y + k_size.x*0.5f &&
				k_drag.y<=k_point.y + k_size.x*1.5f && tutorial_check == 1)
			{
				b_select = 2;
				tutorial_check = 2;
			}
		}
		else if((END->dir == 2 || END->dir == -2) && k_show != 0)
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
				k_drag.y<=k_point.y + k_size.x*0.5f && tutorial_check == 4)
			{
				b_select = 3;
				tutorial_check = 5;
			}
			else if(k_drag.x>=k_point.x + k_size.x*0.5f && 
				k_drag.x<=k_point.x + k_size.x*1.5f &&
				k_drag.y>=k_point.y - k_size.x*0.5f &&
				k_drag.y<=k_point.y + k_size.x*0.5f && tutorial_check == 2)
			{
				b_select = 4;
				tutorial_check = 3;
			}
		}	
	}
	else if((s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_RELEASED))
	{
		k_show = 0;
		if(tutorial_check == 5)
		{
			tutorial_check = 6;
		}
		else if (tutorial_check > 0 && tutorial_check != 6)
		{
			tutorial_check = -(tutorial_check);
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
//-------------------------Tutorial Page Draw Control 1---------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

void CGame::tutorial()
{
	Iw2DDrawImage(getresource->get_bg(0),CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
	Iw2DDrawImage(getresource->get_frame(),CIwFVec2(beg.x+b_size.x,beg.y+b_size.x),CIwFVec2(length,breadth));

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

	a_move = move;
	Iw2DDrawImageRegion(getresource->get_body(),a_move,g_size,CIwFVec2(0,0),CIwFVec2(30,30));
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

	switch (tutorial_check)
	{
		case 1:
			sprintf(print,"Drag Toward Down Arrow");
			break;
		case 2:
			sprintf(print,"Drag Toward Right Arrow");
			break;
		case 3:
			sprintf(print,"Drag Toward Up Arrow");
			break;
		case 4:
			sprintf(print,"Drag Toward Left Arrow");
			break;
		case 5:
			sprintf(print,"Release");
			break;
		case 6:
			sprintf(print,"Ready to Roll, Tap to Start");
			break;
		default:
			sprintf(print,"Touch and Hold Anywhere");
			break;
	}
	Iw2DDrawString(print,CIwFVec2(0,Iw2DGetSurfaceHeight()*0.70f),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)getresource->get_font()->GetHeight()),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
}