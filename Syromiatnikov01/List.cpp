#include "List.h"

int List::  getSize() const
{
	return size;
}

void List:: CreateArray(int size1)
{
	monitors = new LedMonitor[size1];

	for (int i = 0; i < size1; i++)
	{
		monitors[i] = NewElement();
	}
	size = size1;
}

void List:: AddMonitor(List old)
{
	monitors = new LedMonitor[size + 1];
	for (int count = 0; count < size; count++)
	{
		monitors[count] = old.monitors[count];
	}
	monitors[size++] = NewElement();

	delete[] old.monitors;
}

bool List:: DeleteMonitor(List old)
{
	int answer;
	int num = 0;
	monitors = new LedMonitor[size - 1];
	printf("\nEnter the number of monitor you wish to delete: ");
	scanf_s("%i", &answer);

	if (answer > size)
	{
		printf("\nError 666: You are trying to choose element out of boarder of the list\n");
		return false;
	}
	else 
	{
		for (int count = 0; count < answer - 1; count++)
		{
			monitors[num++] = old.monitors[count];
		}
		for (int count = answer; count < size; count++)
		{
			monitors[num++] = old.monitors[count];
		}
		delete[] old.monitors;
		size -= 1;
	}
}

LedMonitor List::NewElement()
{
	LedMonitor New;
	New.setLength(rand()% 10 - 1);
	New.setWidth(rand() % 10 - 1);
	New.setDiagonal(rand() % 10 - 1);
	New.setId(rand() % 10 - 1);
	return New;
}

void List:: PrintAll() const
{
	printf("\n%-5s%-5s%-5s%-5s%-5s", "Number", " Length", " Width", " Diagonal", " ID");
	for (int count = 0; count < size; count++)
	{
		printf("\n%-9d%-6d%-7d%-5d%4d", count + 1, monitors[count].getLength(), monitors[count].getWidth(), monitors[count].getDiagonal(), monitors[count].getId());
	}

}

void List:: GetById(int count1) const
{
	printf("\n%-5s%-5s%-5s%-5s", "Number", " Length", " Width", " Diagonal");
	printf("\n%-9d%-6d%-7d%-5d", count1, monitors[count1 - 1].getLength(), monitors[count1 - 1].getWidth(), monitors[count1 - 1].getDiagonal());
}

void List:: FreeMemory()
{
	delete[] monitors;
}
