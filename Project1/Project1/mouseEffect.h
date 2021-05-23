#pragma once
#include<vector>

class Vector2
{
public:
	int x;
	int y;
};

class mouseEffect
{
private:
	mouseEffect() = default;
	mouseEffect(const mouseEffect&) = delete;
	void operator = (const mouseEffect&) = delete;

	//クリックのエフェクト
	bool MouseClickEffect(int fram, Vector2 pos);

	bool mouseold = false;
	bool mousenow = false;
	//マウスの座標履歴
	std::vector <Vector2> mouseClickPoint;
	std::vector<int> clickcnt;
	//軌跡の半径
	const int pointR = 2;
	int crrentNum = 0;

public:
	//スングルトンインスタンス
	static mouseEffect& Instance() {
		static mouseEffect instance;
		return instance;
	}
	void Init();
	void Run();
};

