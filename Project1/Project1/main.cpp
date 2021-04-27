#include<DxLib.h>
#include<vector>
#include"mouseEffect.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	mouseEffect::Instance().Init();
	while (ProcessMessage()!=-1)
	{
		ClsDrawScreen();
		mouseEffect::Instance().Run();
		ScreenFlip();
	}
}