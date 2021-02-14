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
	bg[9] = Iw2DCreateImageResource("bg9");

	frame = Iw2DCreateImageResource("frame");

	s3eMemorySetInt(S3E_MEMORY_HEAP,1);
	IwGetResManager()->LoadGroup("Gameplay.group");

	head = Iw2DCreateImageResource("head");
	body = Iw2DCreateImageResource("body");
	food = Iw2DCreateImageResource("food");

	IwGetResManager()->LoadGroup("Control.group");

	key = Iw2DCreateImageResource("key");
	menu = Iw2DCreateImageResource("menu");

	IwGetResManager()->LoadGroup("Iw2DStrings.group");

	if(Iw2DGetSurfaceHeight()<=480)
	{
		font = Iw2DCreateFontResource("Kuli_30_white");
	}
	else if(Iw2DGetSurfaceHeight()<=800)
	{
		font = Iw2DCreateFontResource("Kuli_38_white");
	}
	else
	{
		font = Iw2DCreateFontResource("Kuli_44_white");
	}
}

Resources::~Resources()
{
	for (int i = 0; i < 10; i++)
	{
		delete bg[i];
	}
	delete frame;

	delete head;
	delete body;
	delete food;

	delete key;
	delete menu;

	delete font;

	IwGetResManager()->DestroyGroup("Environment");
	IwGetResManager()->DestroyGroup("Gameplay");
	IwGetResManager()->DestroyGroup("Control");
	IwGetResManager()->DestroyGroup("Iw2DStrings");

	IwResManagerTerminate();
	IwSoundTerminate();
}

Resources *getresource = 0;