#include<stdio.h>
#include<windows.h>

int swap(int *x, int *y)
{
	printf("swap:����֮ǰ��%d %d\n", *x, *y);
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
	printf("swap:����֮ǰ��%d %d\n", *x, *y);
}

int main()
{
	int a = 20;
	int b = 30;
	printf("main:����֮ǰ��%d %d\n", a, b);
	swap(&a , &b);
	printf("main:����֮��%d %d\n", a, b);
	system("pause");
	return 0;
}