#include<stdio.h>

unsigned long fun(unsigned long  n)
{
	unsigned long  x = 0;
	int t;
	while (n)
	{
		t = n % 10;  //ȡĩβ���֣�����֮���ж�


		if (t % 2 == 0)

			x = 10 * x + t;   //��ʱ��¼����֤*t����


		n = n / 10;   //ȥ�����һ�����֣��µ�����������ѭ��

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