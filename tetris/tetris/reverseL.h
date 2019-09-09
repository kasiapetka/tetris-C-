#pragma once
#include "block.h"

class reverseL :public block
{
private:
	int blockInfo[4] = { 1, 5, 9, 8 };
public:
	reverseL();
	void rotate(board & _game_board);
};