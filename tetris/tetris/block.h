#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "board.h"

class block
{
protected:
	int id;
	sf::Vector2i position;
	int rotation;
	std::array<sf::Vector2i, 4> blockCoord;
	bool lying;
	//std::array<sf::Vector2i, 4> new_block;
	//std::array<sf::Vector2i, 4> old_block;
	// sf::Sprite _sprite; sf::IntRect{ (id % 7) * 39, 0, 39, 39 } to w interface
public:
	block();
	int get_id();
	void set_id(int _id);
	void set_rotation(int _rotation);
	int get_rotation();
	bool get_lying();
	void set_position(sf::Vector2i _position);
	int get_ix_blockCoord(int i);
	int get_iy_blockCoord(int i);
	void set_ix_blockCoord(int i,int x);
	void set_iy_blockCoord(int i,int y);
	void set_lying(bool l);
	sf::Vector2i get_position();
	block operator= (block & _block);
	void move_left(board & _game_board);
	void move_right(board & _game_board);
	void move_down(board & _game_board);
	virtual void rotate(board & _game_board);
	
}; 
