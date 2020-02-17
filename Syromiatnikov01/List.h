#pragma once

#include "Monitor.h"

class List
{
private:
	int size;

public:

	int getSize() const;

	LedMonitor* monitors;

	void CreateArray(int);
	
	void AddMonitor(List);

	void TestAddMonitor(List, int, LedMonitor*);

	bool DeleteMonitor(List);

	void TestDeleteMonitor(List old, int, LedMonitor*);
	
	LedMonitor NewElement();
	
	void PrintAll() const;

	void GetById(int) const;
	
	void FreeMemory();
	
};