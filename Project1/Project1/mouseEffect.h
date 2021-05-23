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

	//�N���b�N�̃G�t�F�N�g
	bool MouseClickEffect(int fram, Vector2 pos);

	bool mouseold = false;
	bool mousenow = false;
	//�}�E�X�̍��W����
	std::vector <Vector2> mouseClickPoint;
	std::vector<int> clickcnt;
	//�O�Ղ̔��a
	const int pointR = 2;
	int crrentNum = 0;

public:
	//�X���O���g���C���X�^���X
	static mouseEffect& Instance() {
		static mouseEffect instance;
		return instance;
	}
	void Init();
	void Run();
};

