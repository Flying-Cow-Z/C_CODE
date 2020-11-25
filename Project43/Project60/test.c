#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#pragma warning (disable:4996)


int Find(int a[][5], int row, int col, int x)
{
	int i = 0;
	int j = col - 1;
	while (i < row && j >= 0)
	{
		if (x < a[i][j]){
			j--;
		}
		else if(x > a[i][j]){
			i++;
		}
		else{
			return 1;
		}
	}
	return -1;
}
int main()
{
	int a[][5] = {
		{1,2,3,4,5},
		{7,8,9,10,11},
		{12,13,14,15,16},
		{17,18,19,20,21}
	};

	int x = 20;
	int ret = Find(a, 4, 5, 20);
	printf("%d\n", ret); //1为存在 -1为不存在
	system("pause");
	return 0;
}









//方法3
//
//void LeftRotate(char *str, int len, int num)
//{
//	assert(str);
//	assert(len > 0);
//	assert(num > 0);
//	num %= len;  // 去重!
//	int i = 0;
//	for (i = num; i < num + len; i++)//abcd1234abcd1234
//	{
//		printf("%c",str[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	char str1[] = "abcd1234";
//	char str2[] = "cd1234ab";
//	int len = strlen(str1);
//	int num = 3;//左旋3次	
//	char *double_string = (char*)malloc(2 * len + 1);
//	if (double_string == NULL)
//	{
//		return -1;
//	}
//	strcpy(double_string, str1);
//	strcat(double_string, str1);
//	printf("%s\n", double_string);
//	LeftRotate(double_string, len, num);
//
//	/*if (strstr(double_string, str2) != NULL)
//	{
//		printf("yes!\n");
//	}
//	else{
//		printf("no!\n");
//	}
//		*/system("pause");
//	return 0;
//}

//方法2
//void Reserve(char *str, int start, int end)
//{
//	while (start < end)
//	{
//		char temp = str[start];
//		str[start] = str[end];
//		str[end] = temp;
//		start++, end--;
//	}
//}

//void LeftRotate(char *str, int len, int num)
//{
//	assert(str);
//	assert(len > 0);
//	assert(num >= 0);
//	num %= len;  // 去重!
//    //子串划分
//	//[0,num - 1]
//	Reserve(str, 0, num - 1);
//	//[num.len - 1]
//	Reserve(str, num, len - 1);
//	//[0,len - 1]
//	Reserve(str, 0, len - 1);
//}
//int main()
//{
//	char str1[] = "abcd1234";
//    char str2[] = "cd1234ab";
//	int len = strlen(str1);
//	int num = 3;//左旋3次	
//	//printf("before: %s\n", str1);
//		int i = 0;
//		for (; i < len; i++)
//		{
//			if (strcmp(str1, str2) == 0)
//			{
//				printf("yes！\n");
//				break;
//			}
//			LeftRotate(str1, len, 1);
//		}
//		if (i == len)
//		{
//			printf("no!\n");
//		}
//	//	//printf("%d\n", strlen(str1));
//	//	//printf("after : %s\n", str1);
//
//	 
//	system("pause");
//	return 0;
//}
//方法1
//void LeftRotate(char *str, int len, int num)
//{
//	assert(str);
//	assert(len > 0);
//	assert(num > 0);
//	num %= len;  // 去重!
//	while (num)
//	{
//		char temp = str[0];
//		int i = 0;
//		for (; i < len - 1; i++)
//		{
//			str[i] = str[i + 1];
//		}
//		str[i] = temp;
//		num--;
//	}
//}
//int main()
//{
//	char str1[] = "abcd1234";
//	char str2[] = "cd1234ab";
//	int len = strlen(str1);
//	int num = 3;//左旋3次
//
//	//printf("before: %s\n", str1);
//	int i = 0;
//	for (; i < len; i++)
//	{
//		if (strcmp(str1, str2) == 0)
//		{
//			printf("yes！\n");
//			break;
//		}
//		LeftRotate(str1, len, 1);
//	}
//	if (i == len)
//	{
//		printf("no!\n");
//	}
//	//printf("%d\n", strlen(str1));
//	//printf("after : %s\n", str1);
//
//
//
//	system("pause");
//	return 0;
//}