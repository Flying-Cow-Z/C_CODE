#include<stdio.h>
#include<windows.h>

int main()
{
	//求出0～100000之间的所有“水仙花数”并输出。
	//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，
    //如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。

	int a = 0;
	for (a = 0; a <= 10000; a++)
	{

		if (a >= 0 && a < 10)
		{
			for (a = 0; a < 10; a++)
			{

				if (a == (a ^ 1))
					printf("%d ", a);
				
			}
			
		}

		else if (a >= 10 && a < 100)
		{
			int i = 0;//个位数
			int j = 0;//十位数
			
			i = a % 10;
			j = a / 10;
			for (a = 10; a < 100; a++)
			{

				if (a == (i ^ 2 )+( j ^ 2))
				{
					printf("%d ", a);
				}
			
			}
		
		}

		else if (a >= 100 && a < 1000)
		{
			int i = 0; //个位
			int j = 0; //十位
			int x = 0; //百位
			int temp = 0;
		
			i = a % 100;
			x = a / 100;
			temp = a / 10;
			j = temp % 10;
			for (a = 100; a < 1000; a++)
			{
				if (a == (i ^ 3) + (j ^ 3) + (x ^ 3))
				{
					printf("%d ", a);
				}
			
			}
			
		}
		else if (a >= 1000 && a < 10000)
		{

			int i = 0; //个位
			int j = 0; //十位
			int x = 0; //百位
			int y = 0; //千位
			int temp1 = 0;
			int temp2 = 0;
			
			i = a % 1000;
			y = a / 1000;
			temp1 = a / 10;
			j = temp1 % 100;
			temp2 = a / 100;
			x = temp2 % 10;
			for (a = 1000; a < 10000; a++)
			{
				if (a == (i ^ 4) + (j ^ 4) +( x ^ 4) + (y ^ 4))
				{
					printf("%d ", a);
				}
			
			}
			
		}
		else if (a == 10000)
		{
			if (a != (1 ^ 5) +( 0 ^ 5) + (0 ^ 5) +( 0 ^ 5) +( 0 ^ 5))
			{
				printf(" ");
			}
			
		}
	}
	system("pause");
	return 0;
}