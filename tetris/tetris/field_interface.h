#pragma once
#include <SFML/Graphics.hpp>
#include "field.h" 

class field_if
{
private:
	field fd;
	sf::RectangleShape rectangle;
	sf::Sprite sprite;
public:
	void field_display(sf::Vector2f &position);
	void set_fd(field &_field);
	void set_fill(bool _fill);
	void set_sprite(sf::Sprite _sprite);
	void del_sprite();
	bool get_fill();
	int get_id();
	int get_ver();
	int get_hor();
	sf::RectangleShape& get_rec();
	sf::Sprite get_sprite();
};