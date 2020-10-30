#include<stdio.h>
#include<windows.h>

void ShowInt(int x)
{
	ShowInt(x / 10);
	if (x < 10)
	{
		printf(" %d ",x);
		return;
	}
}
int main()
{
	int a = 0;
	scanf_s("%d",&a);
	ShowInt(a);
	system("pause");
	return 0;
}