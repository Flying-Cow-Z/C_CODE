#include<stdio.h>

unsigned long fun(unsigned long  n)
{
	unsigned long  x = 0;
	int t;
	while (n)
	{
		t = n % 10;  //取末尾数字，便于之后判定


		if (t % 2 == 0)

			x = 10 * x + t;   //及时记录，保证*t更新


		n = n / 10;   //去除最后一个数字，新的数继续参与循环

	}
	return  x;
}
int main()
{
	unsigned long  n = -1;
	while (n>99999999 || n<0)
	{
		printf("Please input(0<n<100000000): ");
		scanf_s("%ld", &n);
	}
	printf("\nThe result is: %ld\n", fun(n));
	system("pause");
}