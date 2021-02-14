#if !defined(__RESOURCE_H__)
#define __RESOURCE_H__

#include "Iw2D.h"
#include "s3e.h"
#include "IwResManager.h"
#include "s3eWindowsPhoneAd.h"
#include "s3eOSExec.h"
#include "IwSound.h"

class Resources
{
private:

	CIw2DImage *bg[9];
	CIw2DImage *menu_bg;
	CIw2DImage *control_bg;
	CIw2DImage *select_bg;
	CIw2DImage *about;
	CIw2DImage *frame;

	CIw2DImage *head;
	CIw2DImage *body;
	CIw2DImage *tail;
	CIw2DImage *tongue;
	CIw2DImage *turn;
	CIw2DImage *food;
	CIw2DImage *wall;

	CIw2DImage *key;
	CIw2DImage *controls;
	CIw2DImage *menu_buttons;
	CIw2DImage *level;
	CIw2DImage *star;
	CIw2DImage *fb_button;
	CIw2DImage *rate_button;
	
	CIw2DFont *font;

public:
	
	CIw2DImage *get_bg(int a)			{return bg[a];}
	CIw2DImage *get_menu_bg()			{return menu_bg;}
	CIw2DImage *get_control_bg()		{return control_bg;}
	CIw2DImage *get_select_bg()			{return select_bg;}
	CIw2DImage *get_about()				{return about;}
	CIw2DImage *get_frame()				{return frame;}

	CIw2DImage *get_head()				{return head;}
	CIw2DImage *get_body()				{return body;}
	CIw2DImage *get_tail()				{return tail;}
	CIw2DImage *get_tongue()			{return tongue;}
	CIw2DImage *get_turn()				{return turn;}
	CIw2DImage *get_food()				{return food;}
	CIw2DImage *get_wall()				{return wall;}

	CIw2DImage *get_key()				{return key;}
	CIw2DImage *get_controls()			{return controls;}
	CIw2DImage *get_menu_buttons()		{return menu_buttons;}
	CIw2DImage *get_level()				{return level;}
	CIw2DImage *get_star()				{return star;}
	CIw2DImage *get_fb_button()			{return fb_button;}
	CIw2DImage *get_rate_button()		{return rate_button;}

	CIw2DFont *get_font()				{return font;}

	Resources();
	~Resources();
};

extern Resources *getresource;

#endif