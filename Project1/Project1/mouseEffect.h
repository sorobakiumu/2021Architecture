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

	bool MouseClickEffect(int fram, Vector2 pos);

	bool mouseold = false;
	bool mousenow = false;
	std::vector <Vector2> mouseClickPoint;
	std::vector<int> clickcnt;
	const int pointR = 8;
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

