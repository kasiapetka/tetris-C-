#include "pch.h"
#include "field_interface.h"

void field_if::field_display(sf::Vector2f & position)
{
	using namespace sf;
	rectangle.setSize(Vector2f(39.f, 39.f));
	rectangle.setFillColor(Color::Transparent);
	rectangle.setPosition(position);
	rectangle.setOutlineThickness(1.f);
	rectangle.setOutlineColor(Color::Cyan);
}

void field_if::set_fd(field & _field)
{
	fd.set_hor(_field.get_hor());
	fd.set_ver(_field.get_ver());
	fd.set_fill(_field.get_fill());
	fd.set_id(_field.get_id());
}

void field_if::set_fill(bool _fill)
{
	fd.set_fill(_fill);
}

void field_if::set_sprite(sf::Sprite _sprite)
{
	sprite = _sprite;
}

void field_if::del_sprite()
{
	sprite.setColor(sf::Color(255, 255, 255,0));
}

bool field_if::get_fill()
{
	return fd.get_fill();
}

int field_if::get_id()
{
	return fd.get_id();
}

int field_if::get_ver()
{
	return fd.get_ver();
}

int field_if::get_hor()
{
	return fd.get_hor();
}

sf::RectangleShape & field_if::get_rec()
{
	return rectangle;
}

sf::Sprite field_if::get_sprite()
{
	return sprite;
}
