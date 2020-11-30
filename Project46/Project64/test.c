#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<string.h>

const char * my_strstr(const char * str1, const char * str2)
{
	assert(str1);
	assert(str2);

	const char *str_start = str1;
	const char *str_p = str1;

	const char *sub_p = str2;

	while (*str_start){
		
		str_p = str_start;
		sub_p = str2;
		while (*sub_p && *str_p && *sub_p == *str_p){
		
			str_p++, sub_p++;
			
		}
		if (*sub_p == '\0')
		{
			return str_start;
		}
		str_start++;
	}
	return NULL;
}

int main()
{

	const char *str1 = "abcd1234xyz";
	const char *str2 = "1234";
	printf("%s\n", my_strstr(str1, str2));
	system("pause");
	return 0;
}

//void * mymemove(void * dst, const void * src, size_t num)
//{
//	assert(dst != NULL);
//	assert(src != NULL);
//	//assert(num > 0);
//
//	char *dst_p = (char*)dst;
//	const char *src_p = (char*)src;
//
//	if (dst_p > src_p && dst_p < src_p + num )//´ÓÓÒÏò×ó
//	{
//		src_p = src_p + num - 1;
//		dst_p = dst_p + num - 1;
//		while (num > 0)
//		{
//			*dst_p = *src_p;
//			dst_p--;
//			src_p--;
//			num--;
//		}
//	}
//
//	else{
//		
//		while (num > 0)
//		{
//			*dst_p = *src_p;
//			dst_p++;
//			src_p++;
//			num--;
//		}
//	}
//	return dst_p;
//}

//int main()
//{
//	char str[64] = "abcd1234";
//	int num = strlen(str);
//	printf("%s\n", mymemcpy(str + 1, str, num));
//	system("pause");
//	return 0;
//}