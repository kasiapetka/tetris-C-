#pragma once
#include "field.h"
#include <vector>

class board
{
public:
	std::vector<field> grid;
public:
	board();

	void fill_board();	//ustawia wspolrzedne pol planszy 
	board operator=(const board& _board);
};