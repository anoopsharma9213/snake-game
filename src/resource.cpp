#include "resource.h"

Resources::Resources()
{
	IwSoundInit();
	IwResManagerInit();

	#ifdef IW_BUILD_RESOURCES
		IwGetResManager()->AddHandler(new CIwResHandlerWAV);
	#endif

	s3eMemorySetInt(S3E_MEMORY_HEAP,0);
	IwGetResManager()->LoadGroup("Environment.group");
	
	bg[0] = Iw2DCreateImageResource("bg0");
	bg[1] = Iw2DCreateImageResource("bg1");
	bg[2] = Iw2DCreateImageResource("bg2");
	bg[3] = Iw2DCreateImageResource("bg3");
	bg[4] = Iw2DCreateImageResource("bg4");
	bg[5] = Iw2DCreateImageResource("bg5");
	bg[6] = Iw2DCreateImageResource("bg6");
	bg[7] = Iw2DCreateImageResource("bg7");
	bg[8] = Iw2DCreateImageResource("bg8");
	
	menu_bg = Iw2DCreateImageResource("menu_bg");
	control_bg = Iw2DCreateImageResource("control_bg");
	select_bg = Iw2DCreateImageResource("select_bg");
	about = Iw2DCreateImageResource("about");

	frame = Iw2DCreateImageResource("frame");

	s3eMemorySetInt(S3E_MEMORY_HEAP,1);
	IwGetResManager()->LoadGroup("Gameplay.group");

	head = Iw2DCreateImageResource("head");
	body = Iw2DCreateImageResource("body");
	tail = Iw2DCreateImageResource("tail");
	tongue = Iw2DCreateImageResource("tongue");
	turn = Iw2DCreateImageResource("turn");
	food = Iw2DCreateImageResource("food");
	wall = Iw2DCreateImageResource("wall");

	IwGetResManager()->LoadGroup("Control.group");

	key = Iw2DCreateImageResource("key");
	controls = Iw2DCreateImageResource("controls");
	menu_buttons = Iw2DCreateImageResource("menu_buttons");
	level = Iw2DCreateImageResource("level");
	star = Iw2DCreateImageResource("star");
	fb_button = Iw2DCreateImageResource("fb_button");
	rate_button = Iw2DCreateImageResource("rate_button");

	IwGetResManager()->LoadGroup("Iw2DStrings.group");

	if(Iw2DGetSurfaceHeight()<=480)
	{
		font = Iw2DCreateFontResource("segoe_20_white");
	}
	else if(Iw2DGetSurfaceHeight()<=800)
	{
		font = Iw2DCreateFontResource("segoe_32_white");
	}
	else
	{
		font = Iw2DCreateFontResource("segoe_40_white");
	}
}

Resources::~Resources()
{
	for (int i = 0; i < 9; i++)
	{
		delete bg[i];
	}
	delete menu_bg;
	delete control_bg;
	delete select_bg;
	delete about;
	delete frame;

	delete head;
	delete body;
	delete tail;
	delete tongue;
	delete turn;
	delete food;
	delete wall;

	delete key;
	delete controls;
	delete menu_buttons;
	delete level;
	delete star;
	delete fb_button;
	delete rate_button;

	delete font;

	IwGetResManager()->DestroyGroup("Environment");
	IwGetResManager()->DestroyGroup("Gameplay");
	IwGetResManager()->DestroyGroup("Control");
	IwGetResManager()->DestroyGroup("Iw2DStrings");

	IwResManagerTerminate();
	IwSoundTerminate();
}

Resources *getresource = 0;