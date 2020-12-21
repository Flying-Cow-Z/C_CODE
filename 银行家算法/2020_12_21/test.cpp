#include<iostream>
using namespace std;
#define MAXPROGRAM 10//��������
#define MAXRESOURCE 10//�����Դ��
int Available[MAXRESOURCE];//������Դ����
int Max[MAXPROGRAM][MAXRESOURCE];//�����������
int Allocation[MAXPROGRAM][MAXRESOURCE];//��������
int Need[MAXPROGRAM][MAXRESOURCE];//��������
int Request[MAXPROGRAM][MAXRESOURCE];//��Դ��������
int Finish[MAXPROGRAM];//��ʾϵͳ�Ƿ����㹻����Դ����
int order[MAXPROGRAM];//��Դ��������
//���ڹ�ϵ��Need[MAXPROGRAM][MAXRESOURCR]=Max[MAXPROGRAM][MAXRESOURCR]-Allocation[MAXPROGRAM][MAXRESOURCR]
int pro;//������Ŀ
int res;//��Դ����
int init()//��ʼ��
{
	cout << "-------------------------���м��㷨-----------------------" << endl;
	cout << "�����������Ŀ��" << endl;
	cin >> pro;
	cout << "��������Դ���ࣺ" << endl;
	cin >> res;
	cout << "�����������Դ�����������󣨰�[��][��]���룩��" << endl;
	for (int i = 0; i < pro; i++)
	{
		for (int j = 0; j < res; j++)
		{
			cin >> Max[i][j];
		}
	}
	cout << "�����������Դ��������󣨰�[��][��]���룩��" << endl;
	for (int i = 0; i < pro; i++)
	{
		for (int j = 0; j < res; j++)
		{
			cin >> Need[i][j];
		}
	}
	cout << "�����������Դ�ѷ������" << endl;
	for (int i = 0; i < pro; i++)
	{
		for (int j = 0; j < res; j++)
		{
			cin >> Allocation[i][j];
			Need[i][j] = Max[i][j] - Allocation[i][j];
			if (Need[i][j] < 0)
			{
				cout << "������ĵ�" << i + 1 << "�������ѷ���ĵ�" << j + 1 << "����Դ�������������룺" << endl;
				j--;
				continue;
			}
		}
	}
	cout << "�����������Դ����" << endl;
	for (int j = 0; j < res; j++)
	{
		cin >> Available[j];
	}
	cout << "-------------------------�������-------------------------" << endl;
	cout << "�������Max����Ϊ��" << endl;
	for (int i = 0; i < pro; i++)
	{
		for (int j = 0; j < res; j++)
		{
			cout << Max[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "�������Allocation����Ϊ��" << endl;
	for (int i = 0; i < pro; i++)
	{
		for (int j = 0; j < res; j++)
		{
			cout << Allocation[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "�������Need����Ϊ��" << endl;
	for (int i = 0; i < pro; i++)
	{
		for (int j = 0; j < res; j++)
		{
			cout << Need[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "�������Available����Ϊ��" << endl;
	for (int j = 0; j < res; j++)
	{
		cout << Available[j] << "\t";
	}
	cout << endl;
	return 0;
}
bool safe()//��ȫ���㷨
{
	int Work[MAXRESOURCE];
	int ord = 0;//��ȫ����������
	int i, j, k;
	for (j = 0; j < res; j++)
	{
		Work[j] = Available[j];
	}
	for (i = 0; i < pro; i++)
	{
		Finish[i] = false;//��ʾϵͳû�з�����Դ���ý���
	}
	for (i = 0; i < pro; i++)//ÿ�δ�ͷ��ʼ���ܱ�������Դ�Ľ���
	{
		if (Finish[i] == true)//����ý����ѱ�������Դ
		{
			continue;
		}
		else
		{
			for (j = 0; j < res; j++)
			{
				if (Need[i][j] > Work[j])//���������Դ���ڿɻ�ȡ��Դ�����̲��ܻ����Դ����Դ���������̷��䣩
				{
					break;
				}
			}
			if (j == res)//���ý���ÿ��������Դ���ܱ����㣩���̻����Դ���˳��ִ�У��ı��־λ���ĸ�������Դ������ɣ����ͷų��ѷ������Դ
			{
				Finish[i] = true;
				for (k = 0; k < res; k++)
				{
					Work[k] = Work[k] + Allocation[i][k];
				}
				order[ord++] = i;//��ȫ�������飻ord++��Ҫ�ѽ�������ȫ���Ž�ȥ
				i = -1;//�����´μ�����0��ʼ����������Դ����Ľ���
			}
			else
			{
				continue;
			}
		}
		if (ord == pro)//���pro�����̶����������Դ
		{
			cout << "�˿�ϵͳ�ǰ�ȫ�ģ�" << endl;
			cout << "��ȫ����Ϊ��" << endl;
			for (i = 0; i < ord; i++)
			{
				cout << order[i];
				if (i != ord - 1)
				{
					cout << "-->";
				}
			}
			cout << "" << endl;
			return true;
		}
	}
	cout << "�˿�ϵͳ�ǲ���ȫ�ģ�" << endl;
	return false;
}
void bank()//���м��㷨
{
	char if_again = ' ';
	int M;
	int flag = 0;//�ж���������������Ƿ�����С��Need��Available����
	while (1)
	{
		cout << "����������Ϊ�ڼ������̷�����Դ��0Ϊ��һ�����̣��������ƣ���" << endl;
		cin >> M;
		cout << "��������Դ����������" << endl;
		for (int j = 0; j < res; j++)
		{
			cin >> Request[M][j];
		}
		for (int j = 0; j < res; j++)
		{
			if (Request[M][j] > Need[M][j])//�����㣬Ϊ1
			{
				cout << "���������������̵������������������룡" << endl;
				flag = 1;
				break;
			}
		}
		for (int j = 0; j < res; j++)
		{
			if (Request[M][j] > Available[j])//�����㣬Ϊ1
			{
				cout << "��������������Դ�����������������룡" << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			for (int j = 0; j < res; j++)//�����Դ������������������ִ�����в���
			{
				Available[j] = Available[j] - Request[M][j];
				Need[M][j] = Need[M][j] - Request[M][j];
				Allocation[M][j] = Allocation[M][j] + Request[M][j];
			}
			if (safe())//�����ȫ���㷨ִ�гɹ�
			{
				cout << "�������ɹ���" << endl;
				cout << "�����Allocation����Ϊ��" << endl;
				for (int i = 0; i < pro; i++)
				{
					for (int j = 0; j < res; j++)
					{
						cout << Allocation[i][j] << "\t";
					}
					cout << endl;
				}
				cout << "�����Need����Ϊ��" << endl;
				for (int i = 0; i < pro; i++)
				{
					for (int j = 0; j < res; j++)
					{
						cout << Need[i][j] << "\t";
					}
					cout << endl;
				}
				cout << "�����Available����Ϊ��" << endl;
				for (int j = 0; j < res; j++)
				{
					cout << Available[j] << "\t";
				}
				cout << endl;
			}
			else
			{
				cout << "�������ʧ�ܣ�" << endl;
				for (int j = 0; j < res; j++)//ûִ�гɹ���Ҫ���Է���Ľ����ԭ
				{
					Available[j] = Available[j] + Request[M][j];
					Need[M][j] = Need[M][j] + Request[M][j];
					Allocation[M][j] = Allocation[M][j] - Request[M][j];
				}
				cout << "����ǰ��Allocation����Ϊ��" << endl;
				for (int i = 0; i < pro; i++)
				{
					for (int j = 0; j < res; j++)
					{
						cout << Allocation[i][j] << "\t";
					}
					cout << endl;
				}
				cout << "����ǰ��Need����Ϊ��" << endl;
				for (int i = 0; i < pro; i++)
				{
					for (int j = 0; j < res; j++)
					{
						cout << Need[i][j] << "\t";
					}
					cout << endl;
				}
				cout << "����ǰ��Available����Ϊ��" << endl;
				for (int j = 0; j < res; j++)
				{
					cout << Available[j] << "\t";
				}
				cout << endl;
			}
		}
		cout << "�Ƿ���Ҫ�ٴ�������䣿���밴��Y����y��,�������" << endl;
		cin >> if_again;
		if (if_again == 'Y' || if_again == 'y')
		{
			continue;
		}
		else
			break;
	}
}
int main()
{
	init();
	safe();
	bank();
	return 0;
}