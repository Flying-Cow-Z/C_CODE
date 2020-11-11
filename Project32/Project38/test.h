#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>

#pragma warning(disable:4996)

#define ROW 3
#define COL 3
#define BLACK_PIECE 'X'
#define WHITE_PIECE 'O'

void Menu();
void Game();
void InitBoard(char board[][COL],int row,int col);//第一维度可省略
void ShowBoard(char board[][COL], int row, int col);
int  PlayMove(char board[][COL], int row, int col);
char JudgeResult(char board[][COL], int row, int col);
void  ComputerMove(char board[][COL], int row, int col);

#endif