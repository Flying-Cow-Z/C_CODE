#include<stdio.h>
#include<windows.h>

//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������

//Aѡ��˵��B�ڶ����ҵ�����

//Bѡ��˵���ҵڶ���E���ģ�

//Cѡ��˵���ҵ�һ��D�ڶ���

//Dѡ��˵��C����ҵ�����

//Eѡ��˵���ҵ��ģ�A��һ��

//����������ÿλѡ�ֶ�˵����һ�룬����ȷ������������

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

//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ��� :
//A˵�������ҡ�
//
//B˵����C��
//
//C˵����D��
//
//D˵��C�ں�˵
//
//��֪3����˵���滰��1����˵���Ǽٻ���
//
//�����������Щ��Ϣ��дһ��������ȷ������˭������
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



////�������
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