#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <clocale>
#include <cstdlib>

class LedMonitor
{
private:
	int length;
	int width;
	int diagonal;
	int id;

public:
	int getLength() const;
	
	void setLength(int mon_length);
	
	int getWidth() const;
	
	void setWidth(int mon_width);
	
	int getDiagonal() const;
	
	void setDiagonal(int mon_diagonal);

	int getId() const;

	void setId(int mon_id);
};



