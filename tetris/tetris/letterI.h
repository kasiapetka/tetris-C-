#pragma once
#include "block.h"

class letterI :public block
{
private:
	int blockInfo[4] = { 0, 4, 8, 12 };
public:
	letterI();
	void rotate(board & _game_board);
};