#pragma once
#include "block.h"

class letterT :public block
{
private:
	 int blockInfo[4]= { 1, 4, 5, 6 };
public:
	letterT();
	void rotate(board & _game_board);
	void swap_coords();
};