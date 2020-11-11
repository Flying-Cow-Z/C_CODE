#include"test.h"


int main()
{
	int quit = 0;
	while (!quit){
		int select = 0;
		Menu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			break;
		case 2:
			printf("欢迎下次再玩，再见咯！\n");
			quit = 1;
			break;
		default:
			printf("你的输入有误，请重新输入...");
			break;
		}
	}
	system("pause");
	return 0;
}