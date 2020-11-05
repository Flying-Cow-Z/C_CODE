#include <stdio.h>

void fun(long  s, long *t)
{
	int   d;
	long  sl = 1;
	*t = 0;

	while (s > 0)
	{
		d = s % 10;         //取末尾数字，便于之后判定

		if (d % 2 != 0)
		{
			*t = d * sl + *t;  //及时记录，保证*t更新
			sl *= 10;
		}
		s /= 10;        //去除最后一个数字，新的数继续参与循环
	}
}
int main()
{
	long s, t;
	printf("\nPlease enter s:");
	scanf_s("%ld", &s);
	fun(s, &t);
	printf("The result is: %ld\n", t);
	system("pause");
}