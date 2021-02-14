#if !defined(__GAME_H__)
#define __GAME_H__


#include "resource.h"

class CGame
{

private:
	char print[50];
	struct save
	{
		float star,score,cstar;
		int m, sc, mw;
		int sc_l[6], pt[4], a[10];
	}*_store;
	
	//-----------------------GamePlay----------------
	typedef struct node
	{
		int dir;
		struct node *next;
	}Direction;

	Direction *START, *END, *b_dir;

	CIwFVec2 beg, g_size, b_size, move, a_move, end, temp;
	float length, breadth, _score, h_score[3];
    CIwFVec2 f_Position;
    CIwFVec2 f_Size;
	int f_dir;

	int b_select, i, flag, block, c, over, sound, sound_stat, resume, track, level, plank;
	int row, col;
	//---------------------Control----------------
	CIwFVec2 k_pos, k_size;

	CIwFMat2D rot;

public:

	void Update();
	void Render();

	void play_Page_ini();
	void play_Page();
	void play_Page_Update();

    CGame();
    ~CGame();

	//---------------------------------Extra-------------------------------

	void mainPage();

	void mainPageUpdate();

	void reset();
};

extern CGame *newgame;

#endif