#include "pch.h"
#include "full_line.h"


void full_line::check_lines(board & _game_board,int &score)
{
	int count;
	auto i = _game_board.grid.rbegin();

	do
	{
		count = 0;
		for (int j = 0; j < settings::width; j++)
		{
			
			if ((*i).get_fill() == true)
				count++;
			i++;
		}

		if (count == settings::width)
		{
			delete_line(_game_board, (*i).get_hor() + 1);
			score += 10;
			i = _game_board.grid.rbegin();
		}

	} while (count != 0 && i != _game_board.grid.rend());
}

void full_line::delete_line(board & _game_board, int row)
{
	for (int i = row; i > 0; i--)
		for (int j = 0; j < settings::width; j++)
		{
			_game_board.grid[i * settings::width + j] = _game_board.grid[(i - 1) * settings::width + j];
		}

	for (int j = 0; j < settings::width; j++)
	{
		_game_board.grid[j].set_fill(false);
		_game_board.grid[j].set_id(0);
	}
}



/*


	do
	{
		count = 0;
		for (int j = 0; j < settings::width; j++)
		{
			if (_game_board.grid[i * settings::width + j].get_fill() == true)
				count++;
		}
		i--;

		if (count == settings::width)
		{
			delete_line(_game_board, i + 1);
			i = 17;
		}

	} while (count != 0 && i >= 0);


	*/