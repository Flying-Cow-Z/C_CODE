#include<stdio.h>
#include<windows.h>
int main()
{
	int a = 20;
	printf("%d\n", *((char*)&a));
	system("pause");
	return 0;
}