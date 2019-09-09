#include "pch.h"
#include "game.h"
#include <SFML/Graphics.hpp>
#include "block.h"
#include "square.h"
#include "letterT.h"
#include "letterL.h"
#include "letterZ.h"
#include "letterI.h"
#include "reverseZ.h"
#include "reverseL.h"
#include "settings.h"
#include"full_line.h"
#include "menu.h"
#include <iostream>
#include <memory>


game::game() :window{ sf::VideoMode(1000, 800), "tetris" }, elapsedt(sf::Time::Zero), game_board(),score(0),level(1)
{
	std::string ex = "could not load game texture\n";

	if (!tex.loadFromFile("blocks.png") || !game_over.loadFromFile("game_over.png") || 
		!next_blockt.loadFromFile("next.png") || !font.loadFromFile("Digital_tech.otf") || !exit.loadFromFile("exit2.png"))
	{
		throw ex;
	}

	highscore.setFont(font);
	highscore.setCharacterSize(50);
	game_board = std::make_unique<board>();
}

int game::create_game()
{
	using namespace sf;
	using namespace std;
	int check = 0;
	Time deltaTime{ Time::Zero };
	Clock clock;
	board_if _board;
	block_if _block, nex_block;
	Sprite next_block_s,exit_s;
	next_block_s.setTexture(next_blockt);
	next_block_s.setPosition(Vector2f(0.f, 0.f));
	exit_s.setTexture(exit);
	exit_s.setPosition(Vector2f(750.f, 670.f));


	game_board->fill_board();
	currBlock = std::make_unique<square>();
	Sprite iblock(tex, sf::IntRect{ (currBlock->get_id() % 7) * settings::block_dim, 0, settings::block_dim, settings::block_dim });

	_block.set_blockSprite(iblock);
	*nextBlock = create_next_block();

	while (window.isOpen())
	{
		Event event;
		window.setFramerateLimit(60);

		elapsedt = clock.getElapsedTime();
		_board = _board.board_display(*game_board, tex);

		if (elapsedt >= trigger)
		{
			*game_board = _block.block_display(*currBlock, *game_board);
			clock.restart();
		}
		if (currBlock->get_lying() == true)
		{
			full_line::check_lines(*game_board,score);
			
			if ( trigger > sf::seconds(0.1) && level*100 == score)
			{
				level++;
				trigger -= sf::seconds(0.1);
			}

			try
			{
				check_game_state();
			}
			catch (bool state)
			{
			}
			_board = _board.board_display(*game_board, tex);
			currBlock.swap(nextBlock);
			*nextBlock = create_next_block();

			Sprite jblock(tex, sf::IntRect{ (currBlock->get_id() % 7) * settings::block_dim, 0, settings::block_dim, settings::block_dim });
			_block.set_blockSprite(jblock);

		}
		while (window.pollEvent(event))
		{
			Vector2i localPosition = Mouse::getPosition(window);
			auto translated_pos = window.mapPixelToCoords(localPosition);
			
			if (exit_s.getGlobalBounds().contains(translated_pos))
				exit_s.setColor(Color(255, 255, 255, 128));
			else
				exit_s.setColor(Color(255, 255, 255, 255));

			if ((Mouse::isButtonPressed(Mouse::Left) && exit_s.getGlobalBounds().contains(translated_pos)))
			{
				window.clear();
				window.close();
				menu m;
				m.save_score(score);
				return 0;
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Left)
			{
				currBlock->move_left(*game_board);
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Space)
			{
				currBlock->rotate(*game_board);
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Right)
			{
				currBlock->move_right(*game_board);
			}

			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Down)
			{
				currBlock->move_down(*game_board);
			}

			if (event.type == Event::Closed)
			{
				window.close();
				return 1;
			}
		}

		window.clear();

		for (int i = 0; i < settings::height; i++)
			for (int j = 0; j < settings::width; j++)
			{
				window.draw(_board._board[i * settings::width + j].get_sprite());
				window.draw(_board._board[i * settings::width + j].get_rec());
			}
		window.draw(next_block_s);
		
		for (int i = 0; i < 4; ++i)
		{
			_block.get_blockSprite().setPosition((currBlock->get_ix_blockCoord(i) * settings::block_dim) + (290),
				((currBlock->get_iy_blockCoord(i) + 1) * settings::block_dim));
			window.draw(_block.get_blockSprite());
		}

		Sprite kblock(tex, sf::IntRect{ (nextBlock->get_id() % 7) * settings::block_dim, 0, settings::block_dim, settings::block_dim });
		nex_block.set_blockSprite(kblock);

		for (int i = 0; i < 4; ++i) {
			nex_block.get_blockSprite().setPosition((nextBlock->get_ix_blockCoord(i) * settings::block_dim) - 50,
				(nextBlock->get_iy_blockCoord(i)*settings::block_dim) + 150);
			window.draw(nex_block.get_blockSprite());
		}
		draw_score();
		window.draw(exit_s);

		window.display();

		try
		{
			check_game_state();
		}
		catch(bool state)
		{
			Sprite game_overs;
			game_overs.setTexture(game_over);
			game_overs.setPosition(Vector2f(250.f, 200.f));
			window.draw(game_overs);
			window.display();
			sleep(sf::seconds(5));
			window.clear();
			//window.display();

			//enter_name();
			window.close();
			menu m;
			m.save_score(score);
			return 0;
		}
	
	}
}

block& game::create_next_block()
{
	srand(time(0));
	int i =  (rand() % 7) + 1;

	if (i == 1) nextBlock = std::make_unique<square>();
	else if (i == 2) nextBlock = std::make_unique<letterI>();
	else if (i == 3) nextBlock = std::make_unique<letterZ>();
	else if (i == 4) nextBlock = std::make_unique<reverseZ>();
	else if (i == 5) nextBlock = std::make_unique<letterT>();
	else if (i == 6) nextBlock = std::make_unique<letterL>();
	else if (i == 7) nextBlock = std::make_unique<reverseL>();
	return *nextBlock;
}

void game::check_game_state()
{
	bool ex = false;

	if (game_board->grid[nextBlock->get_iy_blockCoord(0) * settings::width + nextBlock->get_ix_blockCoord(0)].get_fill() == true ||
		game_board->grid[nextBlock->get_iy_blockCoord(1) * settings::width + nextBlock->get_ix_blockCoord(1)].get_fill() == true ||
		game_board->grid[nextBlock->get_iy_blockCoord(2) * settings::width + nextBlock->get_ix_blockCoord(2)].get_fill() == true ||
		game_board->grid[nextBlock->get_iy_blockCoord(3) * settings::width + nextBlock->get_ix_blockCoord(3)].get_fill() == true)
	{	
		throw ex;
		return;
	}
}

void game::draw_score()
{
	using namespace sf;
	using namespace std;
	
	string sc = to_string(score);
	sf::String scS;
	scS = sc;
	sf::String your_score = "Your score";
	sf::Text your_sc;
	your_sc.setFont(font);
	your_sc.setString(your_score);
	your_sc.setPosition(740.f, 70.f);
	your_sc.setCharacterSize(40);
	highscore.setString(scS);
	highscore.setPosition(820.f, 120.f);
	window.draw(highscore);
	window.draw(your_sc);
	
	string lv = to_string(level);
	sf::String lvS;
	lvS = lv;
	sf::String your_level = "Level";
	sf::Text level;
	sf::Text your_lv;
	your_lv.setFont(font);
	level.setFont(font);
	your_lv.setString(your_level);
	level.setString(lvS);
	level.setCharacterSize(40);
	your_lv.setCharacterSize(40);
	your_lv.setPosition(780.f,180.f);
	level.setPosition(830.f,230.f);
	window.draw(level);
	window.draw(your_lv);
}



