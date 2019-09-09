#pragma once
#include "block.h"

class letterZ :public block
{
private:
	int blockInfo[4] = { 0, 4, 5,  9 };
public:
	letterZ();
	void rotate(board & _game_board);
};