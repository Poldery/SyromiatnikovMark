#include "Class.h"
int main()
{
	Menu();
	if (_CrtDumpMemoryLeaks())
	{
		printf("\n\nMemory leak detected");
	}
	else
		printf("\nThere is no memory leak");
	return 0;
}

void Menu()
{
	List One;
	int command = 0;
	int	menu = 1;
	int a_size = 0;
	int num = 0;
	One.CreateArray(3);

	printf("Hello user. Your array has been created. Type the number to begin work with the array");

	while (menu)
	{
		printf("\n\n1.Print all monitors.\n2.Add new monitor\n3.Print one monitor\n4.Delete one monitor\n5.End of the work\n");
		printf("\nFild for typing: ");

		scanf("%d", &command);

		switch (command)
		{
		case 1:
			One.PrintAll();
			break;
		case 2:
			One.AddMonitor(One);
			break;
		case 3:
			printf("Enter the number of monitor: ");
			scanf("%i", &num);
			One.PrintOne(num);
			break;
		case 4:
			One.DeleteMonitor(One);
			break;
		case 5:
			menu = 0;
			break;
		default:
			printf("Error 666: Wrong number.");
			break;
		}
	}
	One.FreeMemory();
	return;
}
