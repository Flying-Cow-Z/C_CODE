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
			printf("��ӭ�´����棬�ټ�����\n");
			quit = 1;
			break;
		default:
			printf("���������������������...");
			break;
		}
	}
	system("pause");
	return 0;
}