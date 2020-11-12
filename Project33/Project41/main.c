#include "test.h"


int main()
{
	int quit = 0;
	while (!quit)
	{
		int select = 0;
		Menu();
		scanf("%d",&select);
		switch (select)
		{
		case 1:
			printf("游戏开始！\n");
			Game();
			printf("再玩一把？\n");
			break;
		case 2:
			printf("下次再见咯！\n");
			quit = 1;
			break;
		default:
			printf("您的输入有误，请重试！\n");
			break;
		}
		
	}



	system("pause");
	return 0;


}