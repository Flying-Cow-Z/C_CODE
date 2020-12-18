#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning (disable :4996)

#define SIZE 64
#define DEFAULT_NAME "张三"
#define DEFAULT_PASSWORD "123456" 
#define TRY_COUNT 3

int main()
{
	int count = TRY_COUNT;
	char name[SIZE];
	char password[SIZE];
	while (count > 0){
		printf("请输入用户名:");
		scanf("%s", name);//至于为什么不用取地址，涉及到降维问题
			printf("请输入密码:");
		scanf("%s", password);

		if (strcmp(name, DEFAULT_NAME) == 0 && strcmp(password, DEFAULT_PASSWORD) == 0)
		{
			printf("欢迎进入！\n");
			break;
		}
		else
		{
			printf("请重试！\n");
			count--;
		}
	}
	if (0 == count)
	{
		printf("请60s之后再试....\n");
		int time = 60;
		while (time > 0)
		{
			printf("请在 %d s后重试！\r", time);
			time--;
			Sleep(500);
		}
	}
	system("pause");
	return 0;
}