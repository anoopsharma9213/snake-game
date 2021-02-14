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

	CIw2DImage *bg[10];
	CIw2DImage *frame;

	CIw2DImage *head;
	CIw2DImage *body;
	CIw2DImage *food;

	CIw2DImage *key;
	CIw2DImage *menu;
	
	CIw2DFont *font;

public:
	
	CIw2DImage *get_bg(int a)		{return bg[a];}
	CIw2DImage *get_frame()		{return frame;}

	CIw2DImage *get_head()		{return head;}
	CIw2DImage *get_body()		{return body;}
	CIw2DImage *get_food()		{return food;}

	CIw2DImage *get_key()		{return key;}
	CIw2DImage *get_menu()		{return menu;}

	CIw2DFont *get_font()		{return font;}

	Resources();
	~Resources();
};

extern Resources *getresource;

#endif