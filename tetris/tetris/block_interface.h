#pragma once
#include <SFML/Graphics.hpp>
#include "block.h"
#include "board.h"

class block_if
{
private:
	sf::Sprite blockSprite;
public:
	board & block_display(block &_block, board&  _game_board);
	sf::Sprite& get_blockSprite();
	void set_blockSprite(sf::Sprite& sp);
};