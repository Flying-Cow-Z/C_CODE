#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning (disable :4996)

#define SIZE 64
#define DEFAULT_NAME "����"
#define DEFAULT_PASSWORD "123456" 
#define TRY_COUNT 3

int main()
{
	int count = TRY_COUNT;
	char name[SIZE];
	char password[SIZE];
	while (count > 0){
		printf("�������û���:");
		scanf("%s", name);//����Ϊʲô����ȡ��ַ���漰����ά����
			printf("����������:");
		scanf("%s", password);

		if (strcmp(name, DEFAULT_NAME) == 0 && strcmp(password, DEFAULT_PASSWORD) == 0)
		{
			printf("��ӭ���룡\n");
			break;
		}
		else
		{
			printf("�����ԣ�\n");
			count--;
		}
	}
	if (0 == count)
	{
		printf("��60s֮������....\n");
		int time = 60;
		while (time > 0)
		{
			printf("���� %d s�����ԣ�\r", time);
			time--;
			Sleep(500);
		}
	}
	system("pause");
	return 0;
}