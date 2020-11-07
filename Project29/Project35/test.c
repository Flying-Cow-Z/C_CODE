#include<stdio.h>
#include<windows.h>

int fun(int n,int k)
{
	if (k == 0)
	{
		return 1;
	}
	return n*fun(n, k - 1);



}
int main()
{
	int b = 0;
	int a = 0;
	scanf_s("%d",&a);
	scanf_s("%d", &b);
	int ret = fun(a,b);
	printf("%d\n", ret);
	system("pause");
	return 0;

}
