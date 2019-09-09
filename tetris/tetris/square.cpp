#include "pch.h"
#include "square.h"

square::square()
{
	position = sf::Vector2i{ 3, 0 };
	rotation = 0;
	id = 1;
	for (int i = 0; i < 4; ++i) {
		blockCoord[i].x = blockInfo[i] % 4 + 4;
		blockCoord[i].y = blockInfo[i] / 4;
	}
}

void square::rotate(board & _game_board)
{
	return;
}
