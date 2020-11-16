#include<stdio.h>
#include<windows.h>

//void Printf(int *arr, int n)
//{
//	int i = 0;
//	for (; i < n; i++)
//	{
//		printf("%d ",*(arr+i));
//	}
//	printf("\n");
//}
//void fun(char *a)
//{
//	if (NULL == a){
//		return;
//	}
//	else{
//		char *start = a;
//		char *end = a + strlen(a) - 1;
//		while (start < end)
//		{
//			char temp = 0;
//			temp = *start;
//			*start = *end;
//			*end = temp;
//
//			start++, end--;
//
//		}
//	
//	}
//
//}
//int Sum(n)
//{
//	int temp = 0;
//	int sum = 0;
//	int i = 0;
//	for (; i < 5; i++)
//	{
//		temp = temp * 10 + n;
//		sum += temp;
//	}
//	return sum;
//}
int main()
{

	int i = 0;
	int line = 0;
	printf("请输入行数line:");
	scanf_s("%d",&line);
	for (; i < line; i++)
	{
		int j = 0;// j 是一行的循环次数
		for (; j < line - 1 - i; j++)
		{
			printf(" ");
		}
		
		for (j = 0; j < 2 * i + 1;j++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (i = 0; i < line - 1; i++)
	{
		int j = 0;
		for (; j < i+1; j++)
		{
			printf(" ");
		}
		for (j = 0;j < 2*(line - 1 )- 1 - 2*i; j++)
		{
			printf("*");
		}
		printf("\n");

	}
	//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，例如：2 + 22 + 222 + 2222 + 22222
	/*printf("Please enter a number: \n");
	int a = 0;
	scanf_s("%d", &a);
	printf("%d\n", Sum(a));*/
	//char a[] = "abcd1234";
	//fun(a);
	//printf("%s\n", a);
	/*int arr[5] = {1,2,3,4,5};
	int num = sizeof(arr) / sizeof(arr[0]);
	printf(arr,num);*/
	system("pause");
	return 0;
}