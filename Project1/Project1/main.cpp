#include<DxLib.h>

int main() {
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	while (ProcessMessage()!=-1)
	{
		ClsDrawScreen();
		ScreenFlip();
	}
}