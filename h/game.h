#if !defined(__GAME_H__)
#define __GAME_H__


#include "resource.h"

class CGame
{

private:
	char print[50];
	struct save
	{
		int s, m, v, c, maze_ca, maze_cl, r_ca, r_cl;
		int h_ca, l_cl;
		CIwFVec2 ca_move, ca_f_pos;
		int ca_f_dir, ca_block , ca_block_dir[100];
		/*float star,score,cstar;
		int m, sc, mw;
		int sc_l[6], pt[4], a[10];*/
	}*_store;

	typedef struct node
	{
		int dir;
		struct node *next;
	}Direction;

	/*struct save_loc_ca
	{
		

	}*_store_ca;

	struct save_loc_cl
	{
		CIwFVec2 cl_move, cl_f_pos;
		int cl_f_dir, cl_block, cl_block_dir[100];
	}*_store_cl;*/
	
	//-----------------Interface------------------------
	int page;

	//-----------------------GamePlay----------------

	Direction *START, *END, *b_dir;
	CIwFVec2 beg, g_size, b_size, move, a_move, end, temp;
	float length, breadth, _score, h_score[3];
	int row, col;
    CIwFVec2 f_Position, f_Size, f_temp;
	int f_dir, f_step;
	CIwFVec2 w_position[500];
	int wall_max, wall_rotate;
	
	int b_select, var, flag, block, c, over;//, sound_stat, track, level, plank;
	
	int resume_campiagn, resume_classic, g_speed;
	int highscore_ca, level_cl, mode;
	
	//---------------------Control----------------
	CIwFVec2 k_pos, k_size, k_point, k_drag;
	int k_show, control_select, main_page_delay, menu_trans, trans_dir;
	float trans_pos;
	CIwFMat2D rot;
	CIwFVec2 menu_button_size, control_button_size, control_button_pos;
	int maze_count, maze_select_ca;
	int maze_select, slide_select_curr, slide_select_next;
	bool isslide;
	int slide_start_time, slide_stop_start;
	float slide_transition, slide_transition_curr;
	CIwFVec2 slide_start_point, slide_stop_point, slide_transition_position, slide_transition_position_curr;

	//--------------------Audio------------------------
	int music, sound, vibration;
	int m_tem[4];

	//----------------------Tutorial--------------
	int tutorial_check, tutorial_show;

	

public:

	void Update();
	void Render();

	void initialize();

	//-----------------Menu Page------------------------------
	void mainPage();
	void mainPageUpdate();

	void menu_trans_draw();
	//void menu_trans_update();

	//--------------------Gameplay Page-----------------------------
	void play_Page();
	void play_Page_Update();

	void wall_init(int);
	void food_init();

	//---------------------Tutorial----------------------------
	void tutorial();
	void tutorial_update();

    CGame();
    ~CGame();

	//---------------------------------Extra-------------------------------

	void reset();
	void set(int);
};

extern CGame *newgame;

#endif