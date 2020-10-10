#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)


int jiec(int a)
{

	int result = 1;

	while (a > 0)
	{
		printf("%d!+", a);
		result = a * result;

		a--;

		if (0 == a)
		{
			break;
		}

	}

	return result;

}
int main()
{
	int i, sum = 0;
	for (i = 1; i < 11; i++)
	{
		sum = sum + jiec(i);
		printf("\b=%d\n", sum);
	}
	printf("结果为%d\n", sum);

	system("pause");
	return 0;
}















//计算1的阶乘加到10的阶乘
/*#include <stdio.h>
#include <stdlib.h>
int jiec(int x)
{
	int i;
	int s = 1;
	for (i = 1; i <= x; i++)
		s = s*i;
	return(s);
}


int main(){
	int i, ret = 0;
	for (i = 1; i <11; i++) {
		ret = ret + jiec(i);
	}
	printf("%d\n", ret);
	system("pause");
	return 0;
}*/
