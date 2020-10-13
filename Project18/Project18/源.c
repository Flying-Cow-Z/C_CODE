#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#pragma warning(disable:4996)

void Menu()
{
	printf("###########################");
	printf("## 1.开始游戏 2.退出游戏 ##");
	printf("###########################");

}

void Game()
{
	srand((unsigned int)time(NULL));


	int rand_num = rand() % 100 + 1;
	
	printf("..........游戏开始..........\n");
	while (1)
	{
		int data = 0;
		printf("我猜:");
		scanf("%d", &data);
		if (rand_num > data)
		{
			printf("你猜小了！\n");
		}
		else if (rand_num < data)
		{
			printf("你猜大了！\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
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
		printf("\n请输入你的选项：\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			printf("要不要再打一把？\n");
			break;
		case 2:
			quit = 1;
			printf("游戏结束!\n");
			break;
		default:
			printf("你输入的结果有误，请重试！\n");

		}



	}
	system("pause");
	return 0;
}
