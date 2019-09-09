#include "pch.h"
#include "board_interface.h"
#include "settings.h"


board_if& board_if::board_display(board & _game_board,sf::Texture &tex)
{
	using namespace sf;

	Vector2f original(290.f, 39.f);
	Vector2f position(290.f, 39.f);
	Vector2f move_hor(39.f, 0.f);
	Vector2f move_ver(0.f, 39.f);
	
	for (int i = 0; i < settings::height; i++)
	{
		for (int j = 0; j < settings::width; j++)
		{
			int id = _game_board.grid[i * settings::width + j].get_id();

			if (id == 0)
			{
				_board[i * 10 + j].del_sprite();
			}
			if (id != 0)
			{
				Sprite iblock(tex, sf::IntRect{ (id % 7) * 39, 0, 39, 39 });
				iblock.setPosition(j * 39+290, (i + 1) * 39);
				_board[i * 10 + j].set_sprite(iblock);
			}
			_board[i * settings::width + j].set_fd(_game_board.grid[i * settings::width + j]);
			_board[i * settings::width + j].field_display(position);
			position = position + move_hor;
		}
		position = original + move_ver;
		original = original + move_ver;
	}
	return *this;
}