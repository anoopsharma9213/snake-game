#include "s3e.h"
#include "Iw2D.h"
#include "game.h"
#include "IwResManager.h"
#include "s3eAudio.h"

CIw2DFont *font, *font1, *font2;

CIw2DImage *bg, *ubutton, *dbutton, *lbutton, *rbutton, *sound_on, *sound_off, *score, *bound1, *bound2, *bound3, *bound4, *food, *panel;
CIw2DImage *ubutton_p, *dbutton_p, *lbutton_p, *rbutton_p, *setting;

CIwFVec2 beg, g_size, b_size, move, a_move, end, temp;
float length, breadth, _score, h_score;

int b_select, i, flag, block, c, over, sound, sound_stat, resume, track, level, plank;
int row, col;

char test[100], print[100];

typedef struct node
{
	int dir;
	struct node *next;
}Direction;

Direction *START, *END, *b_dir;

CGame::CGame()
{
	IwResManagerInit();
	IwGetResManager()->LoadGroup("Iw2DStrings.group");
	font = Iw2DCreateFontResource("Kuli_30_black");
	font1 = Iw2DCreateFontResource("Kuli_26_white");
	font2 = Iw2DCreateFontResource("Kuli_26_black");

	bg = Iw2DCreateImage("bg.png");

	ubutton = Iw2DCreateImage("up.png");
	dbutton = Iw2DCreateImage("down.png");
	lbutton = Iw2DCreateImage("left.png");
	rbutton = Iw2DCreateImage("right.png");
	ubutton_p = Iw2DCreateImage("up_p.png");
	dbutton_p = Iw2DCreateImage("down_p.png");
	lbutton_p = Iw2DCreateImage("left_p.png");
	rbutton_p = Iw2DCreateImage("right_p.png");

	sound_on = Iw2DCreateImage("sound_on.png");
	sound_off = Iw2DCreateImage("sound_off.png");
	score = Iw2DCreateImage("score.png");
	setting = Iw2DCreateImage("settings.png");
	panel = Iw2DCreateImage("panel.png");

	bound1 = Iw2DCreateImage("bound1.png");
	bound2 = Iw2DCreateImage("bound2.png");
	bound3 = Iw2DCreateImage("bound3.png");
	bound4 = Iw2DCreateImage("bound4.png");

	food = Iw2DCreateImage("food.png");

	s3eAudioPlay("bk_music.mp3",0);
	sound = 1;
	sound_stat = 0;
	track = 1;

	level = 1;
	_score = 0;
	h_score = 100;

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
	over = 0;

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
	delete font;
	delete font1;
	delete font2;
	IwGetResManager()->DestroyGroup("Iw2DStrings");
	IwResManagerTerminate();

	delete bg;

	delete ubutton;
	delete dbutton;
	delete lbutton;
	delete rbutton;
	delete ubutton_p;
	delete dbutton_p;
	delete lbutton_p;
	delete rbutton_p;
	
	delete sound_on;
	delete sound_off;
	delete score;
	delete setting;
	delete panel;

	delete bound1;
	delete bound2;
	delete bound3;
	delete bound4;

	delete food;
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
    // game logic goes here
	mainPageUpdate();

}


void CGame::Render()
{
    // game render goes here

    //// for example, clear to black (the order of components is ABGR)
    Iw2DSurfaceClear(0xff000000);
	Iw2DSetColour(0xffffffff);

	mainPage();

    //// draw a red square
    //Iw2DSetColour(0xff0000ff);

    //// note conversion to pixel coordinates
    //Iw2DFillRect(CIwFVec2((iwsfixed)m_Position.x, (iwsfixed)m_Position.y) - m_Size/IW_FIXED(2), m_Size);

    // show the surface
    Iw2DSurfaceShow();
}

void CGame::mainPage()
{
	Iw2DDrawImage(bg,CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),(float)Iw2DGetSurfaceHeight()));
	
	switch(b_select)
	{
		case 1:
			Iw2DDrawImage(ubutton_p,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(dbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(lbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(rbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+2.0f*(Iw2DGetSurfaceWidth()*0.1f),Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			break;
		case 2:
			Iw2DDrawImage(ubutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(dbutton_p,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(lbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(rbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+2.0f*(Iw2DGetSurfaceWidth()*0.1f),Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			break;
		case 3:
			Iw2DDrawImage(ubutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(dbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(lbutton_p,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(rbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+2.0f*(Iw2DGetSurfaceWidth()*0.1f),Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			break;
		case 4:
			Iw2DDrawImage(ubutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(dbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(lbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(rbutton_p,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+2.0f*(Iw2DGetSurfaceWidth()*0.1f),Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			break;
		case 0:
			Iw2DDrawImage(ubutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f*1.5f),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(dbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceHeight()*0.5f+Iw2DGetSurfaceWidth()*0.1f*0.5f),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(lbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			Iw2DDrawImage(rbutton,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+2.0f*(Iw2DGetSurfaceWidth()*0.1f),Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.1f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.1f,Iw2DGetSurfaceWidth()*0.1f));
			break;
	}

	if(sound == 1)
	{
		Iw2DDrawImage(sound_on,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f,Iw2DGetSurfaceHeight()*0.85f),CIwFVec2(Iw2DGetSurfaceWidth()*0.08f,Iw2DGetSurfaceWidth()*0.08f));
	}
	else if(sound == 0)
	{
		Iw2DDrawImage(sound_off,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f,Iw2DGetSurfaceHeight()*0.85f),CIwFVec2(Iw2DGetSurfaceWidth()*0.08f,Iw2DGetSurfaceWidth()*0.08f));
		//Iw2DDrawImage(sound_off,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+Iw2DGetSurfaceWidth()*0.1f*1.5f-Iw2DGetSurfaceWidth()*0.08f/2,Iw2DGetSurfaceHeight()*0.85f),CIwFVec2(Iw2DGetSurfaceWidth()*0.08f,Iw2DGetSurfaceWidth()*0.08f));
	}
	Iw2DDrawImage(setting,CIwFVec2(Iw2DGetSurfaceWidth()*0.7f+2*(Iw2DGetSurfaceWidth()*0.1f),Iw2DGetSurfaceHeight()*0.85f),CIwFVec2(Iw2DGetSurfaceWidth()*0.08f,Iw2DGetSurfaceWidth()*0.08f));
	
	Iw2DDrawImage(bound1,beg,CIwFVec2(b_size.x,breadth+2*b_size.x));
	Iw2DDrawImage(bound4,CIwFVec2(beg.x+b_size.x+length,beg.y),CIwFVec2(b_size.x,breadth+2*b_size.x));
	Iw2DDrawImage(bound2,beg,CIwFVec2(length+2*b_size.x,b_size.x));
	Iw2DDrawImage(bound3,CIwFVec2(beg.x,beg.y+breadth+b_size.x),CIwFVec2(length+2*b_size.x,b_size.x));

	if(over==0)
	{	
		Iw2DSetColour(0xffffffff);
		Iw2DDrawImage(food,CIwFVec2(beg.x+b_size.x+f_Position.x*g_size.x,beg.y+b_size.x+f_Position.y*g_size.y),f_Size);

		Iw2DSetColour(0xff0000ff);
		a_move = move;
		Iw2DFillRect(a_move,g_size);
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
			Iw2DFillRect(a_move,g_size);
		}

		Iw2DSetColour(0xffffffff);
		Iw2DSetFont(font1);
		sprintf(print,"SCORE : %0.0f",_score);
		Iw2DDrawString(print,CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_RIGHT,IW_2D_FONT_ALIGN_CENTRE);
		sprintf(print,"HIGHSCORE : %0.0f",h_score);
		Iw2DDrawString(print,CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
	}
	else
	{
		Iw2DDrawImage(panel,CIwFVec2(Iw2DGetSurfaceWidth()*0.5f-Iw2DGetSurfaceWidth()*0.4f/2,Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.4f/2),CIwFVec2(Iw2DGetSurfaceWidth()*0.4f,Iw2DGetSurfaceWidth()*0.4f));
	}

	if(resume == 1)
	{
		Iw2DSetFont(font);
		Iw2DDrawImage(panel, beg, CIwFVec2(length+2*b_size.x,breadth+2*b_size.x));
		switch (track)
		{
			case 1: 
				Iw2DDrawString("track 1",CIwFVec2(beg.x,beg.y+5*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				break;
			case 2: 
				Iw2DDrawString("track 2",CIwFVec2(beg.x,beg.y+5*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				break;
			case 3: 
				Iw2DDrawString("track 3",CIwFVec2(beg.x,beg.y+5*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				break;
		}
		switch (level)
		{
			case 1:
				Iw2DDrawString("gravel",CIwFVec2(beg.x,beg.y+10*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				break;
			case 2:
				Iw2DDrawString("spirit",CIwFVec2(beg.x,beg.y+10*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				break;
			case 3:
				Iw2DDrawString("marine",CIwFVec2(beg.x,beg.y+10*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				break;
			case 4:
				Iw2DDrawString("airborne",CIwFVec2(beg.x,beg.y+10*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				break;
			case 5:
				Iw2DDrawString("intergalactic",CIwFVec2(beg.x,beg.y+10*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				break;
		}
		Iw2DDrawString("high scores",CIwFVec2(beg.x,beg.y+15*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
	}
	else if(resume == 2)
	{
		Iw2DSetFont(font);
		Iw2DDrawImage(panel, beg, CIwFVec2(length+2*b_size.x,breadth+2*b_size.x));
		Iw2DDrawString("high scores",CIwFVec2(beg.x,beg.y+3*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
		Iw2DSetFont(font2);
		Iw2DDrawString("100",CIwFVec2(beg.x,beg.y+8*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
		Iw2DDrawString("100",CIwFVec2(beg.x,beg.y+13*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
		Iw2DDrawString("100",CIwFVec2(beg.x,beg.y+18*b_size.x),CIwFVec2(length+2*b_size.x,Iw2DGetSurfaceHeight()*0.1f),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
	}
	/*sprintf(test,"%.2f",Iw2DGetSurfaceHeight()*0.1f);
	Iw2DDrawString(test,CIwFVec2(0,0),CIwFVec2((float)Iw2DGetSurfaceWidth(),100),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);*/
}

void CGame::mainPageUpdate()
{
	if(over == 1)
	{
		if(s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN)
		{
			if(s3ePointerGetX()>=Iw2DGetSurfaceWidth()*0.5f-Iw2DGetSurfaceWidth()*0.4f/2 && 
				s3ePointerGetX()<=Iw2DGetSurfaceWidth()*0.5f-Iw2DGetSurfaceWidth()*0.4f/2+Iw2DGetSurfaceWidth()*0.4f &&
				s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.4f/2 &&
				s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.5f-Iw2DGetSurfaceWidth()*0.4f/2+Iw2DGetSurfaceWidth()*0.4f)
			{
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
					s3ePointerGetY()>=beg.y+5*b_size.x &&
					s3ePointerGetY()<=beg.y+5*b_size.x+Iw2DGetSurfaceHeight()*0.1f)
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
					s3ePointerGetY()<=beg.y+10*b_size.x+Iw2DGetSurfaceHeight()*0.1f)
				{
					level++;
					if(level==6)
					{
						level = 1;
					}
					switch(level)
					{
						case 1: 
							delete bg;
							bg = Iw2DCreateImage("bg.png");
							break;
						case 2: 
							delete bg;
							bg = Iw2DCreateImage("bg1.png");
							break;
						case 3: 
							delete bg;
							bg = Iw2DCreateImage("bg2.png");
							break;
						case 4: 
							delete bg;
							bg = Iw2DCreateImage("bg3.png");
							break;
						case 5: 
							delete bg;
							bg = Iw2DCreateImage("bg4.png");
							break;
					}
					plank = (c+1)*10;
				}
				if(s3ePointerGetX()>=beg.x &&
					s3ePointerGetX()<=beg.x+length+2*b_size.x &&
					s3ePointerGetY()>=beg.y+15*b_size.x &&
					s3ePointerGetY()<=beg.y+15*b_size.x+Iw2DGetSurfaceHeight()*0.1f)
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
			s3eDeviceRequestQuit();
			s3eAudioStop();
		}

		if(s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN)
		{
			if(END->dir == 1 || END->dir == -1)
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
			else if(END->dir == 2 || END->dir == -2)
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
				s3ePointerGetY()<=Iw2DGetSurfaceWidth()*0.7f+2*(Iw2DGetSurfaceWidth()*0.1f)+Iw2DGetSurfaceWidth()*0.08f &&
				s3ePointerGetY()>=Iw2DGetSurfaceHeight()*0.85f &&
				s3ePointerGetY()<=Iw2DGetSurfaceHeight()*0.85f+Iw2DGetSurfaceWidth()*0.08f)
			{
				resume = 1;
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