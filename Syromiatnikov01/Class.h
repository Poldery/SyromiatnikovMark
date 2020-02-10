#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <clocale>

void Menu();


class LedMonitor
{
private:
	int length;
	int width;
	int diagonal;

public:
	int getLength() const
	{
		return length;
	}

	void setLength(int mon_length)
	{
		this->length = mon_length;
	}

	int getWidth() const
	{
		return width;
	}

	void setWidth(int mon_width)
	{
		this->width = mon_width;
	}

	int getDiagonal() const
	{
		return diagonal;
	}

	void setDiagonal(int mon_diagonal)
	{
		this->diagonal = mon_diagonal;
	}
};



class List
{
private:
	int size;

public:

	int getSize() const
	{
		return size;
	}

	LedMonitor* monitors;

	void CreateArray(int size1)
	{
		monitors = new LedMonitor[size1];

		for (int i = 0; i < size1; i++)
		{
			monitors[i] = NewElement();
		}
		size = size1;
	}

	void AddMonitor(List old)
	{
		monitors = new LedMonitor[size + 1];
		for (int count = 0; count < size; count++)
		{
			monitors[count] = old.monitors[count];
		}
		monitors[size++] = NewElement2();

		delete[] old.monitors;
	}

	void DeleteMonitor(List old)
	{
		int answer;
		int num = 0;
		monitors = new LedMonitor[size - 1];
		printf("\nEnter the number of monitor you wish to delete: ");
		scanf("%i", &answer);
		for (int count = 0; count < answer - 1; count++) {
			monitors[num++] = old.monitors[count];
		}
		for (int count = answer; count < size; count++) {
			monitors[num++] = old.monitors[count];
		}
		delete[] old.monitors;
		size -= 1;
	}

	LedMonitor NewElement()
	{
		LedMonitor New;
		New.setLength(12);
		New.setWidth(24);
		New.setDiagonal(36);
		return New;
	}

	LedMonitor NewElement2()
	{
		LedMonitor New;
		New.setLength(30);
		New.setWidth(40);
		New.setDiagonal(50);
		return New;
	}

	void PrintAll() const
	{
		printf("\n%-5s%-5s%-5s%-5s", "Number", " Length", " Width", " Diagonal");
		for (int count = 0; count < size; count++)
		{
			printf("\n%-9d%-6d%-7d%-5d", count + 1, monitors[count].getLength(), monitors[count].getWidth(), monitors[count].getDiagonal());
		}

	}

	void PrintOne(int count1) const
	{
		printf("\n%-5s%-5s%-5s%-5s", "Number", " Length", " Width", " Diagonal");
		printf("\n%-9d%-6d%-7d%-5d", count1, monitors[count1 - 1].getLength(), monitors[count1 - 1].getWidth(), monitors[count1 - 1].getDiagonal());
	}

	void FreeMemory()
	{
		delete[] monitors;
	}

	LedMonitor CreateEl()
	{
		LedMonitor el;
		int char1, char2, char3;
		printf("\nEnter Id: ");
		scanf("%i", &char1);
		el.setLength(char1);
		printf("\nEnter Pages: ");
		scanf("%i", &char2);
		el.setWidth(char2);
		printf("\nEnter Year: ");
		scanf("%i", &char3);
		el.setDiagonal(char3);
		printf("\n");
		return el;
	}
};
