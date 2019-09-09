#pragma once
#include "block.h"


class square :public block
{
private:
	int blockInfo[4] = { 0, 1,  4,  5 };
public:
	square();
	void rotate(board & _game_board);
};