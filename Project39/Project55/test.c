#include<stdio.h>
#include<windows.h>

//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：

//A选手说：B第二，我第三；

//B选手说：我第二，E第四；

//C选手说：我第一，D第二；

//D选手说：C最后，我第三；

//E选手说：我第四，A第一；

//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次

void FoundNum()
{
	int a = 1;
	for (; a <= 5; a++)
	{
		int b = 1;
		for (; b <= 5;b++)
		{
			int c = 1;
			for (; c <= 5;c++)
			{
				int d = 1;
				for (;d <= 5; d++)
				{
					int e = 1;
					for (; e<= 5; e++)
					{
						if (((b == 2) + (a == 3)) == 1 && \
							((b == 2) + (e == 4)) == 1 && \
							((c == 1) + (d == 2)) == 1 && \
							((c == 5) + (d == 3)) == 1 && \
							((e == 4) + (a == 1)) == 1)
						{
							unsigned char flag = 0;
							flag |= (1 << (a - 1));
							flag |= (1 << (b - 1));
							flag |= (1 << (c - 1));
							flag |= (1 << (d - 1));
							flag |= (1 << (e- 1));
							
							

							while (flag){
								if (flag & 1)
								{
									flag >>= 1;
								}
								else{
									break;
								}

							}
							if (!flag)
							{
								printf("A:%d B:%d C:%d D:%d E:%d \n", a, b, c, d, e);
							}
							
							
							
						}
					}
				}
			}
		}
	}
}
int main()
{
	FoundNum();
	system("pause");
	return 0;
}

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词 :
//A说：不是我。
//
//B说：是C。
//
//C说：是D。
//
//D说：C在胡说
//
//已知3个人说了真话，1个人说的是假话。
//
//现在请根据这些信息，写一个程序来确定到底谁是凶手
//
//void ShowKiller()
//{
//	char killer = 'A';
//	for (; killer <= 'D'; killer++)
//	{
//		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
//		{
//			printf("killer is %c !\n",killer);
//		}
//	}
//}
//int main()
//{
//	ShowKiller();
//	system("pause");
//	return 0;
//}



////杨辉三角
//void ShowYang()
//{
//	int i = 0;
//	int j = 0;
//	int arr[10][10] ;
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			arr[i][j] = 1;
//
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		for (j =1; j < i; j++)
//		{
//			arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
//
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ",arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//
//	ShowYang();
//	system("pause");
//	return 0;
//}