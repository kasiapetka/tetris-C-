#pragma once
#include <SFML/Graphics.hpp>
#include"field_interface.h"
#include "board.h"
#include "block.h"
#include "settings.h"

class board_if
{
public:
	field_if _board[settings::width*settings::height];
public:
	board_if& board_display(board & _game_board,  sf::Texture &tex);
};