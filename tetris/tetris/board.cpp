#include "pch.h"
#include "board.h"
#include "settings.h"
#include <iterator>

board::board()
{
}


void board::fill_board()
{
	int id_0 = 0;

	for (int i = 0; i < settings::height; i++)
		for (int j = 0; j < settings::width; j++)
		{
			field fd;
			fd.set_ver(j);
			fd.set_hor(i);
			fd.set_id(id_0);
			fd.set_fill(false);
			grid.push_back(fd);
		}
}

board board::operator=(const board & _board)
{
	for (auto i = 0; i < _board.grid.size(); i++)
	{
		grid[i] = _board.grid[i];
	}
	return *this;
}