#pragma once
#include "board.h"
#include "settings.h"

class full_line
{
public:
	static void check_lines(board & _game_board,int &score);
	static void delete_line(board & _game_board, int row);
};