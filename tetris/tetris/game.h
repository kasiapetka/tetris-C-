#pragma once
#include "block.h"
#include "board.h"
#include "board_interface.h"
#include "block_interface.h"

class game
{
private:
	sf::RenderWindow window;
	sf::Texture tex;
	sf::Texture next_blockt,game_over,exit;
	sf::Time elapsedt;
	std::unique_ptr<block> currBlock;
	std::unique_ptr<block> nextBlock;
	std::unique_ptr<board> game_board;
	sf::Font font;
	sf::Text highscore;
	sf::Time trigger{ sf::seconds(1) };
	int score;
	int level;
public:
	game();
	int create_game();
	block& create_next_block();
	void check_game_state();
	void draw_score();
};