#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<ctype.h>
#include<limits.h>

int strtus = 0;
int myatoi(const char*str)
{
	assert(str);
	int flag = 1;
	long long result = 0;
	int i = 0;
	while (isspace(str[i]))
	{
		i++;
	}
	if (str[i] == '-')
	{
		flag = -flag;
		i++;
	}
	while (str[i])
	{
		if (isdigit(str[i])){
			result = 10 * result + flag * (str[i] - '0');
			if (result > INT_MAX || result < INT_MIN)
			{
				strtus = 1;
				break;
			}
		}
		else{
			strtus = 2;
			break;
		}
		i++;
	}
	
	return (int)result;
}
int main()
{
	const char *str = "  -12345";

	int res = myatoi(str);
	printf("strtus:%d,res:%d\n",strtus, res);
	system("pause");
	return 0;
}
//int FindTwoSingle(int a[],int num, int *x, int *y)
//{
//	assert(a);
//	assert(num > 0);
//	assert(x);
//	assert(y);
//	int result = a[0];
//
//	for (int i = 1; i < num; i++)
//	{
//		result ^= a[i];
//	}
//	int pos = 1;
//	while (1)
//	{
//		if (result & pos)
//		{
//			break;
//		}
//		pos <<= 1;
//	}
//	*x = 0;
//	*y = 0;
//	for (int i = 0; i < num; i++)
//	{
//		if (a[i] & pos){
//			*x ^= a[i];
//		}
//		else{
//			*y ^= a[i];
//		}
//	}
//}
//
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 11, 55, 1, 2, 3, 4, 5, 6, 7 };
//	int num = sizeof(a) / sizeof(a[0]);
//	int x = 0;
//	int y = 0;
//	FindTwoSingle(a,num, &x, &y);
//	printf("找到的两个数为：%d,%d\n", x, y);
//	system("pause");
//	return 0;
//}