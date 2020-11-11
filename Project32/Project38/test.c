#include"test.h"

void Menu()
{
	printf("###############################\n");
	printf("##### 欢迎来到三子棋游戏！#####\n");
	printf("###############################\n");
	printf("###### 1.Play     2.exit ######\n");
	printf("###############################\n");
	printf("Please select < 1 , 2 > : ");
}

void Game()
{
	char board[ROW][COL];
	InitBoard(board,ROW,COL);
	char result = 'N';
	srand((unsigned long)time(NULL));
	while (1)
	{
		ShowBoard(board, ROW, COL);
		int type = PlayMove(board, ROW, COL);

		if (1 == type)
		{
			printf("输入有误，请重新输入....\n");
			continue;
		}
		else if (2 == type)
		{
			printf("输入的坐标已被占用，重新输入...\n");
			continue;
		}
		else
		{
			printf("用户落子完毕。\n");

		}

		result = JudgeResult(board, ROW, COL);
		if (result != 'N')
		{
			break;
		}
	
		ComputerMove(board, ROW, COL);
		result=JudgeResult(board, ROW, COL);
		if (result != 'N')
		{
			break;
		}
	
	}
	ShowBoard(board, ROW, COL);
	switch (result)
	{
	
	case BLACK_PIECE:
		printf("你赢了！\n");
		break;
	case WHITE_PIECE:
		printf("电脑赢了！");
		break;
	case 'E':
		printf("平手！\n");
		break;
	default:
		printf("有bug！\n");
		break;
	}

	
}

void InitBoard(char board[][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}

void ShowBoard(char board[][COL], int row, int col)
{
	printf("   | 1 | 2 | 3 |\n");
	int i = 0;
	for (; i < row; i++)
	{
		printf("----------------\n");
		printf(" %d | %c | %c | %c |\n",i+1,board[i][0],board[i][1],board[i][2]);
	}
	printf("----------------\n");
}

int PlayMove(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入你的坐标<x,y>: ");
	scanf("%d%d",&x,&y);
	if (x >=1 && x <= 3 && y >=1  && y <= 3)
	{
		if (board[x-1 ][y-1 ] != ' ')
		{
			return 2;
		}
		else{
			board[x - 1][y - 1] = BLACK_PIECE;
			return 0;
		}
	}
	else{
		return 1;//用户输入坐标有误。
	}

}

char JudgeResult(char board[][COL], int row, int col)
//用户赢 'X'
//电脑赢 'O'
//平局 'E'
//next 'N'
{
	int i = 0 ;
	for (; i < row; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			return board[i][0];
		}
	}
	for (i=0; i < col; i++)
	{
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			return board[0][i];
		}
	}
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[0][0];
	}
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return board[1][1];
	}
	for (i=0; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			if (board[i][j] = ' ')
			{
				return 'N';
			}
		}
	}
	return 'E';

}

void  ComputerMove(char board[][COL], int row, int col)
{
	while (1)
	{
		int i = rand() % row;
		int j = rand() % col;
		if (board[i][j] == ' ')
		{
			board[i][j] = WHITE_PIECE;
			break;
		}
	}
	printf("电脑落子完毕\n");
	Sleep(500);
}
