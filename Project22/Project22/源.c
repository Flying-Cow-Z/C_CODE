#include<stdio.h>

#include<windows.h>

#pragma warning (disable:4996)
#define SIZE 10

int Max(int a[], int num)
{
	int i = 0;
	int max = a[0];
	while (i < num)
	{
		if (max < a[i])
		{
			max = a[i];
		}
		i++;
	}
	return max;

}
int main()

{
	int a[SIZE] = {0};
	int i = 0;
	for (; i < SIZE; i++)
	{
		scanf("%d",&a[i]);

	}

	int ret = Max(a,SIZE);


	printf("%d ",ret);
	system("pause");

	return 0;

}