#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#pragma warning(disable:4996)

void Menu()
{
	printf("###########################");
	printf("## 1.��ʼ��Ϸ 2.�˳���Ϸ ##");
	printf("###########################");

}

void Game()
{
	srand((unsigned int)time(NULL));


	int rand_num = rand() % 100 + 1;
	
	printf("..........��Ϸ��ʼ..........\n");
	while (1)
	{
		int data = 0;
		printf("�Ҳ�:");
		scanf("%d", &data);
		if (rand_num > data)
		{
			printf("���С�ˣ�\n");
		}
		else if (rand_num < data)
		{
			printf("��´��ˣ�\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
			break;
		}
	}
}
int main()
{
	
	int quit = 0;
	while (!quit)
	{
		Menu();
		int select = 0;
		printf("\n���������ѡ�\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			printf("Ҫ��Ҫ�ٴ�һ�ѣ�\n");
			break;
		case 2:
			quit = 1;
			printf("��Ϸ����!\n");
			break;
		default:
			printf("������Ľ�����������ԣ�\n");

		}



	}
	system("pause");
	return 0;
}
