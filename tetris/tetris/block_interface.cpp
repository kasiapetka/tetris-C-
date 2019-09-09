#include "pch.h"
#include "block_interface.h"
#include "square.h"


board & block_if::block_display(block & _block, board & _game_board)
{
	using namespace sf;


	//bl = _block;
	
	if (_block.get_iy_blockCoord(0) < 17 && _block.get_iy_blockCoord(1) < 17 &&
		_block.get_iy_blockCoord(2) < 17 && _block.get_iy_blockCoord(3) < 17)
		if (_game_board.grid[(_block.get_iy_blockCoord(0)+1) * 10 + _block.get_ix_blockCoord(0)].get_fill() != true &&
			_game_board.grid[(_block.get_iy_blockCoord(1)+1)* 10 + _block.get_ix_blockCoord(1)].get_fill() != true &&
			_game_board.grid[(_block.get_iy_blockCoord(2)+1)* 10 + _block.get_ix_blockCoord(2)].get_fill() != true &&
			_game_board.grid[(_block.get_iy_blockCoord(3)+1) * 10 + _block.get_ix_blockCoord(3)].get_fill() != true)
		{
			//elapsedt = sf::Time::Zero;

			for (int i = 0; i < 4; ++i)
			{
				_block.set_iy_blockCoord(i, _block.get_iy_blockCoord(i) + 1);
			}

		}
		else
		{
			for (int i = 0; i < 4; ++i)
			{
				_game_board.grid[_block.get_iy_blockCoord(i) * 10 + _block.get_ix_blockCoord(i)].set_fill(true);
				_game_board.grid[_block.get_iy_blockCoord(i) * 10 + _block.get_ix_blockCoord(i)].set_id(_block.get_id());
			}
			_block.set_lying(true);
		}

	if (_block.get_iy_blockCoord(0) >= 17 || _block.get_iy_blockCoord(1) >= 17 ||
		_block.get_iy_blockCoord(2) >= 17 || _block.get_iy_blockCoord(3) >= 17) {

		for (int i = 0; i < 4; ++i)
		{
			_game_board.grid[(_block.get_iy_blockCoord(i) ) * 10 + (_block.get_ix_blockCoord(i))].set_fill(true);
			_game_board.grid[(_block.get_iy_blockCoord(i) ) * 10 + (_block.get_ix_blockCoord(i) )].set_id(_block.get_id());
		}
		_block.set_lying(true);
	}
	return _game_board;
}

sf::Sprite& block_if::get_blockSprite()
{
	return blockSprite;
}

void block_if::set_blockSprite(sf::Sprite & sp)
{
	blockSprite = sp;
}
