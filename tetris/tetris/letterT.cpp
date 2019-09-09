#include "pch.h"
#include "letterT.h"
#include <iostream>

letterT::letterT()
{
	position = sf::Vector2i{ 3, 0 };
	rotation = 0;
	id = 5;
	for (int i = 0; i < 4; ++i) {
		blockCoord[i].x = blockInfo[i] % 4 + 4;
		blockCoord[i].y = blockInfo[i] / 4 ;
	}
}

void letterT::rotate(board & _game_board)
{
	if (rotation == 0)
	{
			if ((blockCoord[2].y + 1) > 17 ||
				_game_board.grid[(blockCoord[2].y + 1) * 10 + blockCoord[2].x].get_fill() == true)
				return;

			swap_coords();

		blockCoord[3].y = blockCoord[2].y + 1;
		blockCoord[3].x = blockCoord[2].x;
		rotation = 1;
		return;
	}
	else if (rotation == 1)
	{
		if ((blockCoord[2].x - 1) < 0 ||
			_game_board.grid[(blockCoord[2].y) * 10 + blockCoord[2].x -1].get_fill() == true)
			return;

		swap_coords();

		blockCoord[3].y = blockCoord[2].y;
		blockCoord[3].x = blockCoord[2].x-1;
		rotation = 2;
		return;
	}
	else if (rotation == 2)
	{
		if ((blockCoord[2].y- 1) < 0 ||
			_game_board.grid[(blockCoord[2].y-1) * 10 + blockCoord[2].x].get_fill() == true)
			return;

		swap_coords();

		blockCoord[3].y = blockCoord[2].y-1;
		blockCoord[3].x = blockCoord[2].x;
		rotation = 3;
		return;
	}
	else if (rotation == 3)
	{
		if ((blockCoord[2].x + 1) > 9 ||
			_game_board.grid[(blockCoord[2].y) * 10 + blockCoord[2].x+1].get_fill() == true)
			return;

		swap_coords();

		blockCoord[3].y = blockCoord[2].y;
		blockCoord[3].x = blockCoord[2].x+1;
		rotation = 0;
		return;
	}
}

void letterT::swap_coords()
{
	std::swap(blockCoord[0], blockCoord[3]);
	std::swap(blockCoord[3], blockCoord[1]);
}