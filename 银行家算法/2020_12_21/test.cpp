#include<iostream>
using namespace std;
#define MAXPROGRAM 10//最大进程数
#define MAXRESOURCE 10//最大资源数
int Available[MAXRESOURCE];//可用资源数组
int Max[MAXPROGRAM][MAXRESOURCE];//最大需求数组
int Allocation[MAXPROGRAM][MAXRESOURCE];//分配数组
int Need[MAXPROGRAM][MAXRESOURCE];//需求数组
int Request[MAXPROGRAM][MAXRESOURCE];//资源请求数组
int Finish[MAXPROGRAM];//表示系统是否有足够的资源分配
int order[MAXPROGRAM];//资源分配序列
//存在关系：Need[MAXPROGRAM][MAXRESOURCR]=Max[MAXPROGRAM][MAXRESOURCR]-Allocation[MAXPROGRAM][MAXRESOURCR]
int pro;//进程数目
int res;//资源种类
int init()//初始化
{
	cout << "-------------------------银行家算法-----------------------" << endl;
	cout << "请输入进程数目：" << endl;
	cin >> pro;
	cout << "请输入资源种类：" << endl;
	cin >> res;
	cout << "请输入各类资源的最大需求矩阵（按[行][列]输入）：" << endl;
	for (int i = 0; i < pro; i++)
	{
		for (int j = 0; j < res; j++)
		{
			cin >> Max[i][j];
		}
	}
	cout << "请输入各类资源的需求矩阵（按[行][列]输入）：" << endl;
	for (int i = 0; i < pro; i++)
	{
		for (int j = 0; j < res; j++)
		{
			cin >> Need[i][j];
		}
	}
	cout << "请输入各类资源已分配矩阵：" << endl;
	for (int i = 0; i < pro; i++)
	{
		for (int j = 0; j < res; j++)
		{
			cin >> Allocation[i][j];
			Need[i][j] = Max[i][j] - Allocation[i][j];
			if (Need[i][j] < 0)
			{
				cout << "您输入的第" << i + 1 << "个进程已分配的第" << j + 1 << "类资源错误，请重新输入：" << endl;
				j--;
				continue;
			}
		}
	}
	cout << "请输入可用资源矩阵：" << endl;
	for (int j = 0; j < res; j++)
	{
		cin >> Available[j];
	}
	cout << "-------------------------输入完成-------------------------" << endl;
	cout << "您输入的Max矩阵为：" << endl;
	for (int i = 0; i < pro; i++)
	{
		for (int j = 0; j < res; j++)
		{
			cout << Max[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "您输入的Allocation矩阵为：" << endl;
	for (int i = 0; i < pro; i++)
	{
		for (int j = 0; j < res; j++)
		{
			cout << Allocation[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "您输入的Need矩阵为：" << endl;
	for (int i = 0; i < pro; i++)
	{
		for (int j = 0; j < res; j++)
		{
			cout << Need[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "您输入的Available矩阵为：" << endl;
	for (int j = 0; j < res; j++)
	{
		cout << Available[j] << "\t";
	}
	cout << endl;
	return 0;
}
bool safe()//安全性算法
{
	int Work[MAXRESOURCE];
	int ord = 0;//安全序列里的序号
	int i, j, k;
	for (j = 0; j < res; j++)
	{
		Work[j] = Available[j];
	}
	for (i = 0; i < pro; i++)
	{
		Finish[i] = false;//表示系统没有分配资源给该进程
	}
	for (i = 0; i < pro; i++)//每次从头开始找能被分配资源的进程
	{
		if (Finish[i] == true)//如果该进程已被分配资源
		{
			continue;
		}
		else
		{
			for (j = 0; j < res; j++)
			{
				if (Need[i][j] > Work[j])//如果需求资源大于可获取资源，进程不能获得资源（资源不够给进程分配）
				{
					break;
				}
			}
			if (j == res)//（该进程每个所需资源都能被满足）进程获得资源后可顺利执行，改变标志位；哪个进程资源分配完成，就释放出已分配的资源
			{
				Finish[i] = true;
				for (k = 0; k < res; k++)
				{
					Work[k] = Work[k] + Allocation[i][k];
				}
				order[ord++] = i;//安全序列数组；ord++是要把进程序列全安排进去
				i = -1;//方便下次继续从0开始搜索满足资源分配的进程
			}
			else
			{
				continue;
			}
		}
		if (ord == pro)//如果pro个进程都被分配好资源
		{
			cout << "此刻系统是安全的！" << endl;
			cout << "安全序列为：" << endl;
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
	cout << "此刻系统是不安全的！" << endl;
	return false;
}
void bank()//银行家算法
{
	char if_again = ' ';
	int M;
	int flag = 0;//判断输入的请求向量是否满足小于Need和Available矩阵
	while (1)
	{
		cout << "请输入您想为第几个进程分配资源（0为第一个进程，依次类推）：" << endl;
		cin >> M;
		cout << "请输入资源请求向量：" << endl;
		for (int j = 0; j < res; j++)
		{
			cin >> Request[M][j];
		}
		for (int j = 0; j < res; j++)
		{
			if (Request[M][j] > Need[M][j])//不满足，为1
			{
				cout << "请求向量超过进程的需求量，请重新输入！" << endl;
				flag = 1;
				break;
			}
		}
		for (int j = 0; j < res; j++)
		{
			if (Request[M][j] > Available[j])//不满足，为1
			{
				cout << "请求向量超过资源可用量，请重新输入！" << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			for (int j = 0; j < res; j++)//如果资源请求向量满足条件，执行下列步骤
			{
				Available[j] = Available[j] - Request[M][j];
				Need[M][j] = Need[M][j] - Request[M][j];
				Allocation[M][j] = Allocation[M][j] + Request[M][j];
			}
			if (safe())//如果安全性算法执行成功
			{
				cout << "请求分配成功！" << endl;
				cout << "分配后Allocation矩阵为：" << endl;
				for (int i = 0; i < pro; i++)
				{
					for (int j = 0; j < res; j++)
					{
						cout << Allocation[i][j] << "\t";
					}
					cout << endl;
				}
				cout << "分配后Need矩阵为：" << endl;
				for (int i = 0; i < pro; i++)
				{
					for (int j = 0; j < res; j++)
					{
						cout << Need[i][j] << "\t";
					}
					cout << endl;
				}
				cout << "分配后Available矩阵为：" << endl;
				for (int j = 0; j < res; j++)
				{
					cout << Available[j] << "\t";
				}
				cout << endl;
			}
			else
			{
				cout << "请求分配失败！" << endl;
				for (int j = 0; j < res; j++)//没执行成功，要把试分配的结果还原
				{
					Available[j] = Available[j] + Request[M][j];
					Need[M][j] = Need[M][j] + Request[M][j];
					Allocation[M][j] = Allocation[M][j] - Request[M][j];
				}
				cout << "分配前的Allocation矩阵为：" << endl;
				for (int i = 0; i < pro; i++)
				{
					for (int j = 0; j < res; j++)
					{
						cout << Allocation[i][j] << "\t";
					}
					cout << endl;
				}
				cout << "分配前的Need矩阵为：" << endl;
				for (int i = 0; i < pro; i++)
				{
					for (int j = 0; j < res; j++)
					{
						cout << Need[i][j] << "\t";
					}
					cout << endl;
				}
				cout << "分配前的Available矩阵为：" << endl;
				for (int j = 0; j < res; j++)
				{
					cout << Available[j] << "\t";
				}
				cout << endl;
			}
		}
		cout << "是否还想要再次请求分配？是请按“Y”或“y”,否按任意键" << endl;
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