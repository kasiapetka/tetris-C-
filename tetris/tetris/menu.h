#pragma once
#include <SFML/Graphics.hpp>

class menu
{
private:
	const  int exit = 1;
	const  int play = 2;
	const  int rules = 3;
	sf::RenderWindow window{ sf::VideoMode(1000, 800), "tetris" };
	sf::Texture exit_t, back_t, bg_t;
	sf::Sprite bg_s;
public:
	menu();
	 int game_menu();
	 void print_rules();
	 void save_score(int score);
	 void write_to_file(const std::string &playerInput, int score);
	 void print_scores();
};