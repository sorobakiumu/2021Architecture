#include <DxLib.h>
#include <random>
#include "mouseEffect.h"

const int vecMax = 30;

Vector2 oldPos[vecMax];


bool mouseEffect::MouseClickEffect(int fram, Vector2 pos)
{
	int line = 5;
	if (fram + pointR >= 50) {
		line = 1;
	}
	DrawCircle(pos.x, pos.y, fram + pointR, 0xffaaaa, false, line);
	if (fram + pointR - 10 >= pointR) {
		DrawCircle(pos.x, pos.y, fram + pointR - 10, 0xdd7777, false, line);
	}
	if (fram + pointR - 20 >= pointR) {
		DrawCircle(pos.x, pos.y, fram + pointR - 20, 0x993333, false, line);
	}
	if (fram + pointR - 20 >= 50) {
		return true;
	}
	return false;
}

void mouseEffect::Init()
{

	for (auto pos : oldPos) {
	pos.x = -100;
	pos.y = -100;
	}
}

void mouseEffect::Run()
{
	//現在座標取得
	int x, y;
	GetMousePoint(&x, &y);
	for (int n = 0; n < vecMax; n++) {
		DrawCircle(oldPos[n].x, oldPos[n].y, pointR, 0xffff00);
	}
	DrawCircle(x, y, pointR, 0xffffff);
	//座標履歴に追加
	oldPos[crrentNum % vecMax].x = x + std::rand() % 10 - 5;
	oldPos[crrentNum % vecMax].y = y + std::rand() % 10 - 5;
	//左クリックの押下情報
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
		mousenow = true;
	}
	else {
		mousenow = false;
	}
	if (mousenow == true && mouseold == false) {
		clickcnt.push_back(crrentNum);

		mouseClickPoint.push_back({ x, y });
	}
	for (int n = 0; n < clickcnt.size(); n++) {
		if (clickcnt[n] >= 0) {
			if (MouseClickEffect(crrentNum - clickcnt[n], mouseClickPoint[n])) {
				clickcnt[n] = -1;
			}
		}
	}
	for (int n = 0; n < clickcnt.size(); n++) {
		if (clickcnt[n] < 0) {
			clickcnt.erase(clickcnt.begin() + n);
			mouseClickPoint.erase(mouseClickPoint.begin() + n);
		}
	}
	mouseold = mousenow;
	crrentNum++;
}

