
#include<stdio.h>
#include<windows.h>
#include<math.h>
#pragma warning(disable:4996)



int main()
{

	char str[8];
	memset(str, 'a', 8);
	
	int i = 0;

	for (; i <= 8; i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");
	system("pause");
	return 0;
	}