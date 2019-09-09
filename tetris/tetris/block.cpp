#include "pch.h"
#include "block.h"
#include "settings.h"

block::block():lying(false)
{
}

int block::get_id()
{
	return id;
}

void block::set_id(int _id)
{
	id = _id;
}

void block::set_rotation(int _rotation)
{
	rotation = _rotation;
}

int block::get_rotation()
{
	return rotation;
}

bool block::get_lying()
{
	return lying;
}

void block::set_position(sf::Vector2i _position)
{
	position = _position;
}

int block::get_ix_blockCoord(int i)
{
	if (i > 3)
		return 0;
	return blockCoord[i].x;
}

int block::get_iy_blockCoord(int i)
{
	if (i > 3)
		return 0;
	return blockCoord[i].y;
}

void block::set_ix_blockCoord(int i, int x)
{
	blockCoord[i].x = x;
}

void block::set_iy_blockCoord(int i, int y)
{
	blockCoord[i].y = y;
}

void block::set_lying(bool l)
{
	lying = l;
}

sf::Vector2i block::get_position()
{
	return position;
}


block block::operator=(block & _block)
{
	id = _block.id;
	rotation = _block.rotation;
	position = _block.position;
	blockCoord = _block.blockCoord;
	lying = _block.lying;
	return *this;
}

void block::move_left(board & _game_board)
{
	
	for (int i = 0; i < settings::block_size; ++i)
	{
		if (blockCoord[i].x <= 0 || _game_board.grid[blockCoord[i].y * settings::width + blockCoord[i].x-1].get_fill() == true)
			return;
	}
	for (int i = 0; i < settings::block_size; ++i)
	{
		blockCoord[i].x--;
	}
}

void block::move_right(board & _game_board)
{
	for (int i = 0; i < settings::block_size; ++i)
	{
		if (blockCoord[i].x >= 9 || _game_board.grid[blockCoord[i].y * settings::width + blockCoord[i].x + 1].get_fill() == true)
			return;
	}
	for (int i = 0; i < settings::block_size; ++i)
	{
		blockCoord[i].x++;
	}
}

void block::move_down(board & _game_board)
{
	for (int i = 0; i < settings::block_size; ++i)
	{
		if (blockCoord[i].y >= (settings::height - 1)|| _game_board.grid[(blockCoord[i].y + 1)* 10 + blockCoord[i].x].get_fill() == true)
			return;
	}
	for (int i = 0; i < settings::block_size; ++i)
	{
		blockCoord[i].y++;
	}
}

void block::rotate(board & _game_board)
{}
