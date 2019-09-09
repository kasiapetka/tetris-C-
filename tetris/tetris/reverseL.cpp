#include "pch.h"
#include "reverseL.h"

reverseL::reverseL()
{
	position = sf::Vector2i{ 3, 0 };
	rotation = 0;
	id = 7;
	for (int i = 0; i < 4; ++i) {
		blockCoord[i].x = blockInfo[i] % 4 +4 ;
		blockCoord[i].y = blockInfo[i] / 4;
	}
}

void reverseL::rotate(board & _game_board)
{
	if (rotation == 0)
	{
		if ((blockCoord[1].x - 1) < 0 ||
			(blockCoord[1].x + 1) > 9 ||
			(blockCoord[0].x - 1) < 0 ||
			_game_board.grid[(blockCoord[0].y) * 10 + blockCoord[0].x - 1].get_fill() == true ||
			_game_board.grid[(blockCoord[1].y) * 10 + blockCoord[1].x + 1].get_fill() == true ||
			_game_board.grid[(blockCoord[1].y) * 10 + blockCoord[1].x - 1].get_fill() == true)
			return;


		blockCoord[0].y = blockCoord[1].y;
		blockCoord[0].x = blockCoord[1].x + 1;

		blockCoord[2].y = blockCoord[1].y;
		blockCoord[2].x = blockCoord[1].x - 1;

		blockCoord[3].y = blockCoord[1].y - 1;
		blockCoord[3].x = blockCoord[1].x - 1;

		rotation = 1;
		return;
	}
	else if (rotation == 1)
	{
		if ((blockCoord[0].y - 1) < 0 ||
			(blockCoord[1].y + 1) > 17 ||
			(blockCoord[1].y - 1) < 0 ||
			_game_board.grid[(blockCoord[0].y - 1) * 10 + blockCoord[0].x].get_fill() == true ||
			_game_board.grid[(blockCoord[1].y + 1) * 10 + blockCoord[1].x].get_fill() == true ||
			_game_board.grid[(blockCoord[1].y - 1) * 10 + blockCoord[1].x].get_fill() == true)
			return;


		blockCoord[0].y = blockCoord[1].y + 1;
		blockCoord[0].x = blockCoord[1].x;

		blockCoord[2].y = blockCoord[1].y - 1;
		blockCoord[2].x = blockCoord[1].x;

		blockCoord[3].y = blockCoord[1].y - 1;
		blockCoord[3].x = blockCoord[1].x + 1;

		rotation = 2;
		return;
	}
	else if (rotation == 2)
	{
		if ((blockCoord[1].x) - 1 < 0 ||
			(blockCoord[1].x) + 1 > 9 ||
			(blockCoord[0].x) + 1 > 9 ||
			_game_board.grid[(blockCoord[0].y) * 10 + blockCoord[0].x + 1].get_fill() == true ||
			_game_board.grid[(blockCoord[1].y) * 10 + blockCoord[1].x + 1].get_fill() == true ||
			_game_board.grid[(blockCoord[1].y) * 10 + blockCoord[1].x - 1].get_fill() == true)
			return;


		blockCoord[0].y = blockCoord[1].y;
		blockCoord[0].x = blockCoord[1].x - 1;

		blockCoord[2].y = blockCoord[1].y;
		blockCoord[2].x = blockCoord[1].x + 1;

		blockCoord[3].y = blockCoord[1].y + 1;
		blockCoord[3].x = blockCoord[1].x + 1;

		rotation = 3;
		return;
	}
	else if (rotation == 3)
	{
		if ((blockCoord[0].y) + 1 > 17 ||
			(blockCoord[1].y) + 1 > 17 ||
			(blockCoord[1].y) - 1 < 0 ||
			_game_board.grid[(blockCoord[2].y + 1) * 10 + blockCoord[2].x].get_fill() == true ||
			_game_board.grid[(blockCoord[1].y + 1) * 10 + blockCoord[1].x].get_fill() == true ||
			_game_board.grid[(blockCoord[1].y - 1) * 10 + blockCoord[1].x].get_fill() == true)
			return;


		blockCoord[0].y = blockCoord[1].y - 1;
		blockCoord[0].x = blockCoord[1].x;

		blockCoord[2].y = blockCoord[1].y + 1;
		blockCoord[2].x = blockCoord[1].x;

		blockCoord[3].y = blockCoord[1].y + 1;
		blockCoord[3].x = blockCoord[1].x - 1;

		rotation = 0;
		return;
	}

}
