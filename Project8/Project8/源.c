#include <stdio.h>
#include <windows.h>


int main()
{
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(double*));
	printf("%d\n",sizeof(float*));
	system("pause");
	return 0;
}