#include <stdio.h>

void fun(long  s, long *t)
{
	int   d;
	long  sl = 1;
	*t = 0;

	while (s > 0)
	{
		d = s % 10;         //ȡĩβ���֣�����֮���ж�

		if (d % 2 != 0)
		{
			*t = d * sl + *t;  //��ʱ��¼����֤*t����
			sl *= 10;
		}
		s /= 10;        //ȥ�����һ�����֣��µ�����������ѭ��
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