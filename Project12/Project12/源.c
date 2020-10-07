#include<stdio.h>
#include<windows.h>
int main()
{
	int a ,b;
		for (a = 100; a <= 200; a++)
		{
			for (b = 2; b <= a - 1; b++)
			{
				if (a % b == 0)
				{
					break;
				}
			
			}
			if (b == a)
			{
				printf("%d ", a);
			}
		}
		printf("\n");
	system("pause");
	return 0;
}
