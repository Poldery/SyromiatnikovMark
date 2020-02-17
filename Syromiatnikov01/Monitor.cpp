#include "Monitor.h"

int LedMonitor:: getLength() const
{
	return length;
}

void LedMonitor:: setLength(int mon_length)
{
	this->length = mon_length;
}

int LedMonitor:: getWidth() const
{
	return width;
}

void LedMonitor:: setWidth(int mon_width)
{
	this->width = mon_width;
}

int LedMonitor:: getDiagonal() const
{
	return diagonal;
}

void LedMonitor:: setDiagonal(int mon_diagonal)
{
	this->diagonal = mon_diagonal;
}

int LedMonitor:: getId() const
{
	return id;
}

void LedMonitor:: setId(int mon_id)
{
	this->id = mon_id;
}