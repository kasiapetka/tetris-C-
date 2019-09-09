#include "pch.h"
#include "reverseZ.h"

reverseZ::reverseZ()
{
	position = sf::Vector2i{ 3, 0 };
	rotation = 0;
	id =4;
	for (int i = 0; i < 4; ++i) {
		blockCoord[i].x = blockInfo[i] % 4 + 4;
		blockCoord[i].y = blockInfo[i] / 4;
	}
}

void reverseZ::rotate(board & _game_board)
{
	if (rotation == 0)
	{
		if ((blockCoord[0].x - 1) < 0 ||
			(blockCoord[1].x + 1) > 9 ||
			_game_board.grid[(blockCoord[0].y) * 10 + blockCoord[0].x - 1].get_fill() == true ||
			_game_board.grid[(blockCoord[1].y) * 10 + blockCoord[1].x + 1].get_fill() == true)
			return;

		std::swap(blockCoord[1], blockCoord[2]);
		std::swap(blockCoord[1], blockCoord[0]);

		blockCoord[0].y = blockCoord[1].y;
		blockCoord[0].x = blockCoord[1].x - 1;

		blockCoord[3].y = blockCoord[2].y;
		blockCoord[3].x = blockCoord[2].x + 1;

		rotation = 1;
		return;
	}
	if (rotation == 1)
	{
		if ((blockCoord[0].y + 1) > 17 ||
			(blockCoord[0].y + 2) > 17 ||
			_game_board.grid[(blockCoord[0].y + 1) * 10 + blockCoord[0].x].get_fill() == true ||
			_game_board.grid[(blockCoord[0].y + 2) * 10 + blockCoord[0].x].get_fill() == true)
			return;

		std::swap(blockCoord[2], blockCoord[1]);
		std::swap(blockCoord[2], blockCoord[0]);

		blockCoord[2].y = blockCoord[0].y + 1;
		blockCoord[2].x = blockCoord[0].x - 1;

		blockCoord[3].y = blockCoord[0].y + 2;
		blockCoord[3].x = blockCoord[0].x - 1;

		rotation = 0;
		return;
	}
}

