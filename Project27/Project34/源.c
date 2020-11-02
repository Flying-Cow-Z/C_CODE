#include<stdio.h>
#include<windows.h>
#pragma warning (disable :4996)

void fun(char*_str)
{
	char *start = _str;
	char *end = _str + strlen(_str) - 1;
	char temp = *start;
	*start = *end;
	*end = '\0';
	if (strlen(_str+1) >= 2)
	{
		fun(_str + 1);

	}
	*end = temp;

}

int main()
{
	char str[10];
	scanf("%s", str);
	fun(str);
	printf("%s",str);
	printf("\n");
	system("pause");
	return 0;


}


/*void fun(char*_str)
{
	if (*_str != '\0')
	{
		fun(_str + 1);
		printf("%c",*_str);
	
	}

}



int main()
{
	char str[10];
	scanf("%s", str);
	fun(str);

	printf("\n");
	system("pause");
	return 0;
}*/







/*void fun(char *_str)
{
	char *start = _str;
	char *end = _str + strlen(_str) - 1;
	char temp = 0;
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++, end--;
	}
}
int main()
{
	char str[10];
	scanf("%s", str);
	printf("倒序之前：%s\n", str);
	fun(str);
	printf("倒序之后：%s\n", str);
	system("pause");
	return 0;
}*/