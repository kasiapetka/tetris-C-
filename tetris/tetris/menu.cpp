#include "pch.h"
#include "menu.h"
#include "game.h"
#include <string>
#include <regex>
#include <list>
#include <fstream>

menu::menu()
{
	if (!bg_t.loadFromFile("background.jpg", sf::IntRect(0, 0, 1080, 1920))
		|| !exit_t.loadFromFile("exit.jpg") || !back_t.loadFromFile("back.png"))
		return;

	bg_s.setTexture(bg_t);
	bg_s.setPosition(sf::Vector2f(0.f, 0.f));
}

int menu::game_menu()
{
	using namespace sf;

	sf::Texture tetris_t, play_t, rules_t,highsc_t;
	sf::Sprite tetris_s, exit_s, play_s, rules_s, highsc_s;
	
	if (!tetris_t.loadFromFile("tetris.jpg", sf::IntRect(0, 0, 594, 249)))
	{
		return EXIT_FAILURE;
	}
	if (!play_t.loadFromFile("play.jpg", sf::IntRect(0, 0, 316, 107)))
	{
		return EXIT_FAILURE;
	}
	
	if (!rules_t.loadFromFile("rules.jpg", sf::IntRect(0, 0, 371, 107)) || !highsc_t.loadFromFile("highscores.png"))
	{
		return EXIT_FAILURE;
	}
	
	tetris_s.setTexture(tetris_t);
	tetris_s.setPosition(Vector2f(260.f, 30.f));
	play_s.setTexture(play_t);
	play_s.setPosition(Vector2f(100.f, 250.f));
	rules_s.setTexture(rules_t);
	rules_s.setPosition(Vector2f(100.f, 400.f));
	exit_s.setTexture(exit_t);
	exit_s.setPosition(Vector2f(100.f, 550.f));
	highsc_s.setTexture(highsc_t);
	highsc_s.setPosition(Vector2f(560.f, 250.f));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			Vector2i localPosition = Mouse::getPosition(window);
			auto translated_pos = window.mapPixelToCoords(localPosition);

			if (exit_s.getGlobalBounds().contains(translated_pos))
				exit_s.setColor(Color(255, 255, 255, 128));
			else
				exit_s.setColor(Color(255, 255, 255, 255));
			if (play_s.getGlobalBounds().contains(translated_pos))
				play_s.setColor(Color(255, 255, 255, 128));
			else
				play_s.setColor(Color(255, 255, 255, 255));
			
			if (rules_s.getGlobalBounds().contains(translated_pos))
				rules_s.setColor(Color(255, 255, 255, 128));
			else
				rules_s.setColor(Color(255, 255, 255, 255));
			
			if (highsc_s.getGlobalBounds().contains(translated_pos))
				highsc_s.setColor(Color(255, 255, 255, 128));
			else
				highsc_s.setColor(Color(255, 255, 255, 255));

			if (event.type == Event::Closed || (Mouse::isButtonPressed(Mouse::Left) && exit_s.getGlobalBounds().contains(translated_pos)))
			{
				window.close();
				return exit;
			}

			if (Mouse::isButtonPressed(Mouse::Left) && play_s.getGlobalBounds().contains(translated_pos))
			{
				window.close();
				try
				{
					game g;
					g.create_game();
				}
				catch (std::string ex)
				{
					return exit;
				}
				return play;
			}

			if (Mouse::isButtonPressed(Mouse::Left) && rules_s.getGlobalBounds().contains(translated_pos))
			{
				print_rules();
			}

			if (Mouse::isButtonPressed(Mouse::Left) && highsc_s.getGlobalBounds().contains(translated_pos))
			{
				print_scores();
			}
		}

		window.clear();
		window.draw(bg_s);
		window.draw(tetris_s);
		window.draw(play_s);
		window.draw(rules_s);
		window.draw(exit_s);
		window.draw(highsc_s);
		window.display();
	}
	return EXIT_SUCCESS;
}

void menu::print_rules()
{
	using namespace sf;
	Texture controls_t;
	Sprite controls_s, back_s;

	if (!controls_t.loadFromFile("controls.png", sf::IntRect(0, 0, 1000, 800)))
	{
		return;
	}

	controls_s.setTexture(controls_t);
	controls_s.setPosition(Vector2f(0.f, 0.f));
	back_s.setTexture(back_t);
	back_s.setPosition(Vector2f(700.f, 670.f));


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			Vector2i localPosition = Mouse::getPosition(window);
			auto translated_pos = window.mapPixelToCoords(localPosition);

			if (back_s.getGlobalBounds().contains(translated_pos))
				back_s.setColor(Color(255, 255, 255, 128));
			else
				back_s.setColor(Color(255, 255, 255, 255));

			if ((Mouse::isButtonPressed(Mouse::Left) && back_s.getGlobalBounds().contains(translated_pos)))
			{
				return;
			}

			if (event.type == Event::Closed)
			{
				window.close();
				return;
			}
		}

		window.clear();
		window.draw(controls_s);
		window.draw(back_s);
		
		window.display();
	}
}

void menu::save_score(int score)
{
	using namespace sf;
	Font font;
	font.loadFromFile("Digit.ttf");

	Texture  enter_name_t,save_t;
	Sprite  enter_name_s, exit_s, back_s,save_s;
	String playerInput;
	Text playerText, your_sc, your_name;
	std::string sc = std::to_string(score);
	String your_score = "Your score   " + sc;

	String your_nm = "Name should have maximum 15 signs and consist only of letters";

	playerText.setFont(font);
	playerText.setPosition(330.f, 190.f);
	playerText.setCharacterSize(100);


	if (!enter_name_t.loadFromFile("enter_name.png") || !save_t.loadFromFile("save.png"))
	{
		return;
	}

	your_sc.setString(your_score);
	your_sc.setFont(font);
	your_sc.setPosition(330.f, 290.f);
	your_sc.setCharacterSize(80);
	your_sc.setStyle(Text::Bold);
	
	your_name.setString(your_nm);
	your_name.setFont(font);
	your_name.setPosition(120.f, 380.f);
	your_name.setCharacterSize(40);

	save_s.setTexture(save_t);
	save_s.setPosition(Vector2f(650.f, 520.f));
	back_s.setTexture(back_t);
	back_s.setPosition(Vector2f(50.f, 520.f));
	enter_name_s.setTexture(enter_name_t);
	enter_name_s.setPosition(Vector2f(200.f, 50.f));
	exit_s.setTexture(exit_t);
	exit_s.setPosition(Vector2f(50.f, 650.f));
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			Vector2i localPosition = Mouse::getPosition(window);
			auto translated_pos = window.mapPixelToCoords(localPosition);
			
		
			if (exit_s.getGlobalBounds().contains(translated_pos))
				exit_s.setColor(Color(255, 255, 255, 128));
			else
				exit_s.setColor(Color(255, 255, 255, 255));

			if (back_s.getGlobalBounds().contains(translated_pos))
				back_s.setColor(Color(255, 255, 255, 128));
			else
				back_s.setColor(Color(255, 255, 255, 255));

			if (save_s.getGlobalBounds().contains(translated_pos))
				save_s.setColor(Color(255, 255, 255, 128));
			else
				save_s.setColor(Color(255, 255, 255, 255));

			if (event.type == Event::Closed || (Mouse::isButtonPressed(Mouse::Left) && exit_s.getGlobalBounds().contains(translated_pos)))
			{
				window.close();
				return;
			}
			
			if ((Mouse::isButtonPressed(Mouse::Left) && back_s.getGlobalBounds().contains(translated_pos)))
			{
				game_menu();
			}

			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode != 8)
				{
					playerInput += event.text.unicode;
					playerText.setString(playerInput);
				}
			}

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Backspace && playerInput.getSize() !=0 )
			{
				playerInput.erase(playerInput.getSize() - 1, 1);
				playerText.setString(playerInput);
			}

			if ((Mouse::isButtonPressed(Mouse::Left) && save_s.getGlobalBounds().contains(translated_pos)))
			{
				const std::regex pattern
				("([a-z]||[A-Z]){1,15}(\\s)*");
				std::string player_in = playerInput;

				if (std::regex_match(player_in, pattern) == true)
				{
					write_to_file(playerInput, score);
					game_menu();
				}
				else
				{
					playerInput = "";
					save_score(score);
				}
			}
		}
		window.clear();
		window.draw(bg_s);
		window.draw(enter_name_s);
		window.draw(exit_s);
		window.draw(back_s);
		window.draw(save_s);
		window.draw(your_sc);
		window.draw(your_name);
		window.draw(playerText);
		window.display();
	}
}

void menu::write_to_file(const std::string &playerInput, int score)
{
	using namespace std;
	fstream file;
	file.open("highscores.txt", ios_base::in);

	std::string name, line;
	int pos, sc;

	if (!file.good())
	{
		return;
	}
	else
	{
		std::list<int> score_list;
		std::list<string> name_list;


		while (file >> pos >> name >> sc)
		{
			score_list.push_back(sc);
			name_list.push_back(name);
		}


		int user_pos = 1;
		auto p = score_list.begin();
		auto r = name_list.begin();

		while (r != name_list.end() && p != score_list.end() && *p > score)
		{
			user_pos++;
			p++;
			r++;
		}
		score_list.insert(p, 1, score);
		name_list.insert(r, 1, playerInput);

		int i = 1;
		p = score_list.begin();
		r = name_list.begin();

		file.close();
		file.open("highscores.txt", ios_base::out);

		while (r != name_list.end() && p != score_list.end())
		{
			file << i << " " << *r << " " << *p << std::endl;
			i++;
			p++;
			r++;
		}
		score_list.erase(score_list.begin(), score_list.end());
		name_list.erase(name_list.begin(), name_list.end());
	}
	file.close();
}


void menu::print_scores()
{
	using namespace sf;
	using namespace std;
	Sprite back_s;
	fstream file;
	Font font;
	font.loadFromFile("Digit.ttf");
	std::list<Text> names_t;

	file.open("highscores.txt", ios_base::in);
	string line,a,b,c;
	int i = 0;

	back_s.setTexture(back_t);
	back_s.setPosition(Vector2f(700.f, 670.f));

	if (!file.good())
	{
		return;
	}
	else
	{
		Vector2f original(290.f, 150.f);
		while (file >> a >> b >> c && i<3)
		{
			line = a + " " + b + " " + c;
			
			Text a;
			String a_s;
			i++;
			a_s = line;
			a.setString(a_s);
			a.setCharacterSize(100);
			a.setPosition(original);
			a.setFont(font);
			names_t.push_back(a);
			original.y += 120;
		}
		
	}

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			Vector2i localPosition = Mouse::getPosition(window);
			auto translated_pos = window.mapPixelToCoords(localPosition);

			if (back_s.getGlobalBounds().contains(translated_pos))
				back_s.setColor(Color(255, 255, 255, 128));
			else
				back_s.setColor(Color(255, 255, 255, 255));

			if ((Mouse::isButtonPressed(Mouse::Left) && back_s.getGlobalBounds().contains(translated_pos)))
			{
				return;
			}

			if (event.type == Event::Closed)
			{
				window.close();
				return;
			}
		}

		window.clear();
		window.draw(bg_s);
		window.draw(back_s);

		for (auto i = names_t.begin(); i != names_t.end(); i++) {
			window.draw((*i));
		}

		window.display();
	}
	names_t.erase(names_t.begin(),names_t.end());
}


