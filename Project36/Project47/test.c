#include<stdio.h>
#include<windows.h>

int main()
{
	//���0��100000֮������С�ˮ�ɻ������������
	//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
    //�� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ�������

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
			int i = 0;//��λ��
			int j = 0;//ʮλ��
			
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
			int i = 0; //��λ
			int j = 0; //ʮλ
			int x = 0; //��λ
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

			int i = 0; //��λ
			int j = 0; //ʮλ
			int x = 0; //��λ
			int y = 0; //ǧλ
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