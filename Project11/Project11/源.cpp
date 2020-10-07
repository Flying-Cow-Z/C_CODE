#include<stdio.h>
#include<windows.h>

int fun(int _a,int _b)
{
	int temp = 0;
	int _i = 0;
	if (_a < _b)
	{
		temp =  _a;
		_a = _b;
		_b = temp;
		
	}
	for (_i = _b; _i >= 0; _i--)
	{
		if (_a % _i == 0 && _b %_i == 0)
		{
			return _i;
		}
	}
}

int main()
{
	int a, b ; 
	printf("请输入两个数：<a,b>");
	scanf_s("%d %d",&a,&b);
	int result = fun(a,b);//fun函数用来实现找出最大公约数
	printf("%d和%d的公约数为%d\n",a,b,result);
	system("pause");
	return 0;
}