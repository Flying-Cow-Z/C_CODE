#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)


int main()
{
	int a = 0;
	for (a = 1; a < 101; a++)
	{
		if (a % 2 != 0)
		printf("%d ", a);

	}


	system("pause");
	return 0;
}