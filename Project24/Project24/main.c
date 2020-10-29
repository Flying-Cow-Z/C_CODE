#include "test.h"

//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值，打印出结果

//double Cal( )
//{
//	int i = 1;
//	double res = 0.0;
//	int flag = 1;
//	for (; i <= 100; i++)
//	{
//		res += (1.0 / i)*flag;
//		flag = -flag;
//	}
//	return res;
//}
//int main()
//{
//
//
//	system("pause");
//	return 0;
//}



//int main()
//
//{
//
//	int a = 0;
//
//
//
//	int b = 0;
//
//	int result = 0;
//
//	for (b = 1; b <= 9; b++)
//
//	{
//
//
//
//		for (a = 1; a <= b; a++)
//
//		{
//
//			result = a * b;
//
//
//
//			printf("%d * %d = %d  ", b, a, result);
//
//		}
//
//		printf("\n");
//
//	}
//
//int  fun(int year)
//{
//
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		{
//			return 1;
//		}
//	
//
//}
//
//int main()
//{
//	int year = 0;
//	printf("请输入一个闰年：\n");
//	scanf_s("%d",&year);
//
//	
//	if (fun(year) == 1)
//	{
//		printf("%d是闰年！",year);
//	}
//	else{
//		printf("%d不是闰年！", year);
//	}
//int fun(int *x,int *y)
//{
//	int temp = 0;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//
//}
//int main()
//{
//	int a = 4;
//	int b = 5;
//	int res = fun(&a,&b);
//	printf("%d,%d\n",a,b);
//	system("pause");
//
//	return 0;
//
//}
int fun(int x,int y){

	int result = 0;

	for (y = 1; y <= 9; y++)

	{



		for (x = 1; x <= y; x++)

		{

			result = x * y;



			printf("%d * %d = %d  ", y, x, result);

		}

		printf("\n");

	}
}
int main()

{
	int a = 0;
	int b = 0;

	int result = fun(a,b);

	printf("%d\n",result);

	system("pause");

	return 0;

}
