#pragma once
#include "block.h"

class reverseZ :public block
{
private:
	int blockInfo[4]={ 1,5,  4, 8 };
public:
	reverseZ();
	void rotate(board & _game_board);
};