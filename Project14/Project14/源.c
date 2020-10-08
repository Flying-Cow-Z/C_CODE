#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
	int n, i, b;
	for (n = 101; n <= 200; n = n + 2)
	{
		b = sqrt(n);
		for (i = 2; i <= b; i++)
		if (n%i == 0)break;
		if (i >= b + 1)
		{
			printf("%d\n", n);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
