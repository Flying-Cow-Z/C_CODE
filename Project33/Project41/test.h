#ifndef _TEST_H_
#define _TEST_H_


#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#pragma warning(disable:4996)
#define ROW 12  //��
#define COL 12  //��
#define NUM 20  //�׵ĸ���Ϊ20

void Menu();
void Game();
void InitBoard(char board[][ROW],int row,int col,char elem);
void SetMine(char mine[][ROW], int row, int col);
char GetNum(char mine[][ROW], int x, int y);
void ShowBoard(char board[][ROW], int row, int col);

#endif