#include "test.h"

void Menu()
{
	printf("####################\n");
	printf("##欢迎来到扫雷游戏##\n");
	printf("## 1.Play   2.exit##\n");
	printf("####################\n");
	printf("请输入<1 or 2 >  ");
}

void  Game()
{
	srand((unsigned long)time(NULL));
	char board[ROW][COL];
	char mine[ROW][COL];
	InitBoard(board ,ROW,COL,'*');
	InitBoard(mine, ROW, COL,'0');
	SetMine(mine, ROW, COL);

	int count = (ROW - 2)*(COL - 2) - NUM;
	while (count > 0)	
	{
		system("cls");
		ShowBoard(board,ROW,COL);
		int x = 0;
		int y = 0;
		printf("请输入你想要的坐标< x, y> ");
		scanf("%d %d",&x,&y);
		if (x < 1 || x > 10 || y < 1 || y > 10)
		{
			printf("您输入的坐标不合理，请重新输入\n");
			Sleep(1000);
			continue;
		}
		if (board[x][y] != '*')
		{
			printf("您输入的坐标已被占用，请重新输入\n");
		}
		if (mine[x][y] == '0')
		{
			count--;
			char num = GetNum(mine, x, y);
			board[x][y] = num;
		}
		else
		{
			printf("（%d,%d）处有雷，你已经被炸死了\n",x,y);
			break;
		}
	}

	if (count > 0)
	{
		printf("很遗憾，扫雷失败\n");
	}
	else
	{
		printf("你成功了！\n");
	}
	ShowBoard(mine, ROW, COL);

}
void InitBoard(char board[][ROW], int row, int col, char elem)
{
	int i = 0;
	for (; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			board[i][j] = elem;
		}

	}
}
void SetMine(char mine[][ROW], int row, int col )
{
	int n = NUM;
	while (n)
	{
		int x = rand() % (row - 2) + 1;
		int y = rand() % (col - 2) + 1;
		if (mine[x][y] == '1')
		{
			continue;
		}
		mine[x][y] = '1';
		n--;
	}
}
char GetNum(char mine[][ROW], int x, int y)
{
return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] 	+ mine[x + 1][y] + mine[x + 1][y + 1] - 7 * '0';
	
}

void ShowBoard(char board[][ROW], int row, int col)
{
	printf("     ");
	int i = 1;
	for (; i <= col-2; i++)
	{
		printf(" %d |",i);
	}
	printf("\n");
	printf("----");
	for (i = 1; i <= col - 2; i++)
	{
		printf("----");
	}
	printf("\n");
	for ( i = 1; i <= row - 2; i++)
	{
		printf(" %2d| ",i);
		int j = 1;
		for (; j <= col-2; j++)
		{
			printf(" %-2c|", board[i][j]);
		}
	
		
		printf("\n");
		for (j = 1; j <= col - 2; j++)
		{
			printf("----");
		}
		printf("----");
		printf("\n");
	}


}