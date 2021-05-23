#include<DxLib.h>
#include<vector>
#include<assert.h>
#include<sstream>
#include<iostream>
#include<iomanip>
#include"mouseEffect.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	DxLib::SetWindowText(L"1916046_ãgâiê^");
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	mouseEffect::Instance().Init();
	
	int graphH[6] = {};
	for (int num = 0; num < 6; num++) {
		//wchar_t path[80];
		//wsprintf(path, "Individual Sprites/adventurer-run2-%02d.png", num);
		//graphH[num] = path;

		std::wostringstream oss;
		oss << L"Individual Sprites/adventurer-run2-";
		oss << std::setw(2);
		oss << std::setfill(L'0');
		oss << num << ".png";
		graphH[num] = LoadGraph(oss.str().c_str());
		assert(graphH[num] != -1);
	}
	unsigned int frame = 0;
	while (ProcessMessage()!=-1)
	{
		ClsDrawScreen();
		DrawRotaGraph(100, 100, 1.0, 0.0, graphH[frame / 10], false);
		mouseEffect::Instance().Run();
		ScreenFlip();
		frame=(frame+1)%60;
	}
}