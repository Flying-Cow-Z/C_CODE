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
			printf("��Ϸ��ʼ��\n");
			Game();
			printf("����һ�ѣ�\n");
			break;
		case 2:
			printf("�´��ټ�����\n");
			quit = 1;
			break;
		default:
			printf("�����������������ԣ�\n");
			break;
		}
		
	}



	system("pause");
	return 0;


}