#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int main(){

	printf("输入三个数：");
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	scanf("%d %d %d",&a,&b,&c);
	if (a > b)
	{
		if (c>a){
			printf("%d %d %d\n",c,a,b);
		}

	}


	system("pause");
	return 0;
}