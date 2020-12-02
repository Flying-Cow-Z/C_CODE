#include<stdio.h>
#include<windows.h>

double Cal()
{
	int i = 1;
	double res = 0.0;
	int flag = 1;
	for (; i <= 100; i++)
	{
		res += (1.0 / i)*flag;
		flag = -flag;
	}
	return res;
}
int main()
{

	double ret = Cal();
	printf("%lf\n", ret);
	system("pause");
	return 0;
}
