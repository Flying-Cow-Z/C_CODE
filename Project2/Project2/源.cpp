#include<stdio.h>
#include<windows.h>

//下面代码，打印结果是什么？为什么？（突出'\0'的重要性）
int main()
{
	char arr1[] = "bit";
	char arr2[] = { 'b', 'i', 't' };
	char arr3[] = { 'b', 'i', 't', '\0' };
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("%s\n", arr3);

	system("pause");
	return 0;
}