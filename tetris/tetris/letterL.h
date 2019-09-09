#pragma once
#include "block.h"

class letterL :public block
{
private:
	int blockInfo[4] = { 0, 4,  8, 9 };
public:
	letterL();
	void rotate(board & _game_board);
};