#include "pch.h"
#include "field.h"

field::field():id(9)
{
}

field field::operator=(const field & _field)
{
	id = _field.id;
	filled = _field.filled;
//	ver = _field.ver;
//	hor = _field.hor;
	return (*this);
}


void field::set_id(int _id)
{
	id = _id;
}

void field::set_fill(bool _fill)
{
	filled = _fill;
}

void field::set_ver(char _ver)
{
	ver = _ver;
}

void field::set_hor(char _hor)
{
	hor = _hor;
}

int field::get_id()
{
	return id;
}

bool field::get_fill()
{
	return filled;
}

int field::get_ver()
{
	return ver;
}

int field::get_hor()
{
	return hor;
}
