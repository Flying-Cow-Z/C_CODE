#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<string.h>
#pragma warning (disable:4996)

int mystrcmp(const char *str2, const char* str1)
{
	assert(str1);
	assert(str2);
	int ret = 0;
	while (!(ret = *(unsigned char*)str2 - *(unsigned char*)str1) && *str1)
	{
		str1++, str2++;
	}

	if (ret > 1)
	{
		ret = 1;
	}
	else if (ret < 1)
	{
		ret = -1;
	}
	else
	{
		ret = 0;
	}
	return ret;
}
int main()
{
	const char *src = "12345a";
	const char *pst = "123456";
	printf("%d\n", mystrcmp(pst, src));
	system("pause");
	return 0;
}

//char *mystrcat(char* str2, const char* str1)
//{
//	assert(str1);
//	assert(str2);
//	char* ret = str2;
//	while (*str2)
//	{
//		str2++;
//	}
//	
//	while (*str1)
//	{
//		*str2 = *str1;
//		str1++, str2++;
//	}
//	return ret;
//}
//int main()
//{
//	const char *src = "123456";
//	char pst[16] = "abcd";
//	printf("%s\n",mystrcat(pst, src));
//	system("pause");
//	return 0;
//}

//char *mystrcpy(char*str2, const char*str1)
//{
//	assert(str1);
//	assert(str2);
//
//	char *ret = str2;
//     1.
//	while (*str1 != '\0')
//	{
//		*str2 = *str1;
//		str1++, str2++;
//	}
//	*str2 = '\0';
//
//	 2.
//	while (*str2++ = *str1++);
//
//	 3.
//	while (*str2 = *str1)//先赋值，再判定*str2是否为\0
//	{
//		str1++, str2++;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	const char *src = "123456";
//	char pst[16];
//	printf("%s\n",mystrcpy(pst, src));
//	system("pause");
//	return 0;
//}
//



//char my_strlen(const char *src)
//{
//	assert(src);
//
//	 my_strlen 写法1
//	int count = 0;
//	while (*src)
//	{
//		src++;
//		count++;
//	}
//	return count;
//
//	 my_strlen 写法2
//	const char *start = src;
//	const char *end = src;
//	while (*end)
//	{
//		end++;
//	}
//	return end - start;
//
//	 my_strlen 写法3
//	if (*src == '\0')
//	{
//		return 0;
//
//	}
//	return 1 + my_strlen(src + 1);
//}

//int main()
//{
//	const char *src = "123456";
//	printf("%d\n", my_strlen(src));
//
//
//	
//	system("pause");
//	return 0;
//}


//const char *src = "123456";
//char pst[] = "abcdefg";
//printf("%s\n", strncpy(pst, src, 4));