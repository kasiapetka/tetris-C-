#include "pch.h"
#include "letterI.h"

letterI::letterI()
{
	position = sf::Vector2i{ 3, 1 };
	rotation = 0;
	id = 2;
	for (int i = 0; i < 4; ++i) {
		blockCoord[i].x = blockInfo[i] % 4 + 4;
		blockCoord[i].y = blockInfo[i] / 4 ;
	}
}

void letterI::rotate(board & _game_board)
{
	if (rotation == 0)
	{
		for (int i = 0, j = -1; i < 4; ++i, j++)
			if ((blockCoord[i].x + j) < 0 ||
				(blockCoord[i].x + j) > 9 ||
				_game_board.grid[blockCoord[1].y * 10 + blockCoord[i].x + j].get_fill() == true)
				return;
		for (int i = 0,j=-1; i < 4; ++i,j++) 
		{
			blockCoord[i].x = blockCoord[i].x+j;
			blockCoord[i].y = blockCoord[1].y;
		}
		rotation = 1;
		return;
	}
	else if (rotation == 1)
	{
		for (int i = 0, j = -1; i < 4; ++i, j++)
			if ((blockCoord[i].y + j) < 0 ||
				(blockCoord[i].y + j) > 17 || 
				_game_board.grid[(blockCoord[i].y + j) * 10 + blockCoord[1].x].get_fill() == true)
				return;
		for (int i = 0, j = -1; i < 4; ++i, j++)
		{
			blockCoord[i].x = blockCoord[1].x ;
			blockCoord[i].y = blockCoord[i].y + j;
		}
		rotation = 0;
		return;
	}
}
