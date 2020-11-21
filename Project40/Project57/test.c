#include <stdio.h> 
#include<windows.h>
int cnt=0; 
int fib(int n)
{ 
	cnt++; 
	if(n==0)
		return 1;
	else if(n==1) 
		return 2; 
	else return fib(n-1)+fib(n-2);
}
void main()
{
	fib(8); 
	printf("%d\n",cnt);
	system("pause");
	return 0;
}