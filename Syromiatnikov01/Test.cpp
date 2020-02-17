#include "List.h"
#include "Monitor.h"

int TestOfCreation(List x);

int main()
{
	LedMonitor* test_monitors;

	List TestOne;

	TestOne.CreateArray(3);

	int size = TestOfCreation(TestOne);

	TestOne.TestAddMonitor(TestOne, size, test_monitors);

	TestOne.TestDeleteMonitor(TestOne, size, test_monitors);

	delete[] TestOne.monitors;

	_getchar_nolock();
}


int TestOfCreation(List x)
{
	int res = x.getSize();
	int expected = 3;
	if (expected == res)
	{
		printf("Array have been created successfully\n");
		return expected;
	}
	else
	{
		printf("Array haven`t been created.");
		return 0;
	}
}

void List:: TestAddMonitor(List old, int size, LedMonitor* test_monitors)
{
	int expected = 4;
	test_monitors = new LedMonitor[size + 1];
	for (int count = 0; count < size; count++)
	{
		test_monitors [count] = old.monitors[count];
	}
	test_monitors[size++] = NewElement();
	if (expected == size)
		printf("\nThe unit test of Adding ran successfully");
	else
		printf("Error 1337: The unit test of Adding isn`t ran successfully\n");
}

void List:: TestDeleteMonitor(List old, int size, LedMonitor* test_monitors)
{
	int expected = 2;
	int answer;
	int num = 0;

	test_monitors = new LedMonitor[size - 1];

	printf("\nEnter the number of monitor you wish to delete: ");
	scanf_s("%i", &answer);

	for (int count = 0; count < answer - 1; count++) 
	{
		test_monitors[num++] = old.monitors[count];
	}
	for (int count = answer; count < size; count++) 
	{
		test_monitors[num++] = old.monitors[count];
	}

	size -= 1;

	if (expected == size)
		printf("\nThe unit test of Deleting ran successfully");
	else
		printf("Error 1337: The unit test of Deleting isn`t ran successfully\n");
}