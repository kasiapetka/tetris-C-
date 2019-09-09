#pragma once

class field
{
private:
	bool filled;
	char ver;
	char hor;
	int id;
public:
	field();
	field operator=(const field& _field);//operator przypisania
	void set_id(int _id);
	void set_fill(bool _fill);
	void set_ver(char _ver);
	void set_hor(char _hor);
	int get_id();
	bool get_fill();
	int get_ver();
	int get_hor();
};