#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
using namespace std;

#define OK 1    //完成
#define ERROR 0 //出错

typedef int Status;

typedef struct free_work//定义一个空闲区说明表结构
{
	int num; //分区序号
	long address; //起始地址
	long size;   //分区大小
	int state;   //分区状态
	int flag;  //是否被访问过
}ElemType;

typedef struct Node// 线性表的双向链表存储结构
{
	ElemType data;
	struct Node *infront; //前趋指针
	struct Node *next;  //后继指针
}Node, *LinkList;

LinkList first; //头结点头结点
LinkList f_end;  //尾结点
int flag;//记录要删除的分区序号

Status InitList()//开创带头结点的内存空间链表
{
	first = (LinkList)malloc(sizeof(Node));
	f_end = (LinkList)malloc(sizeof(Node));
	first->infront = NULL;
	first->next = f_end;
	f_end->infront = first;
	f_end->next = NULL;
	f_end->data.num = 1;
	f_end->data.address = 0;
	f_end->data.size = 1024;
	f_end->data.state = 0;
	f_end->data.flag = 0;
	return OK;
}

void sort()//分区序号重新排序
{
	Node *p = first->next;
	Node *q = NULL;
	q = p->next;
	for (; p != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (p->data.num >= q->data.num)
			{
				q->data.num += 1;
			}
		}
	}
}

//显示主存分配情况
void show()
{
	int flag = 0;//用来记录分区序号
	Node *p = first;

	sort();
	printf("\n\t\t》空间分配情况《\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
	printf("分区序号\t起始地址\t分区大小\t分区状态\n\n");
	p = p->next;
	while (p)
	{
		printf("%d\t\t%d\t\t%d", p->data.num, p->data.address, p->data.size);
		if (p->data.state == 0) printf("\t\t空闲\n\n");
		else printf("\t\t已分配\n\n");
		p = p->next;
	}
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
}

//首次适应算法
Status First_fit(int request)
{
	//为申请作业开辟新空间且初始化
	Node *p = first->next;
	LinkList temp = (LinkList)malloc(sizeof(Node));
	temp->data.size = request;
	temp->data.state = 1;
	p->data.num = 1;
	while (p)
	{
		if ((p->data.state == 0) && (p->data.size == request))
		{//有大小恰好合适的空闲块
			p->data.state = 1;
			return OK;
			break;
		}
		else if ((p->data.state == 0) && (p->data.size > request))
		{//有空闲块能满足需求且有剩余
			temp->infront = p->infront;
			temp->next = p;
			temp->data.address = p->data.address;
			temp->data.num = p->data.num;
			p->infront->next = temp;
			p->infront = temp;
			p->data.address = temp->data.address + temp->data.size;
			p->data.size -= request;
			p->data.num += 1;
			return OK;
			break;
		}
		p = p->next;
	}
	return ERROR;
}
//循环首次适应算法
Status Next_fit(int request)
{
	Node *p = first->next;
	LinkList temp = (LinkList)malloc(sizeof(Node));
	temp->data.size = request;
	temp->data.state = 1;
	p->data.num = 1;
	while (p)
	{
		if ((f_end->data.flag == 1) && (p->data.state == 0))
		{
			while (p)
			{
				p->data.flag = 0;
				p = p->next;
			}
			p = first->next;
		}
		if ((p->data.state == 0) && (p->data.size == request) && (p->data.flag == 0))
		{//有大小恰好合适的空闲块
			p->data.state = 1;
			p->data.flag = 1;
			return OK;
		}
		else if ((p->data.state == 0) && (p->data.size > request) && (p->data.flag == 0))
		{//有空闲块能满足需求且有剩余
			temp->infront = p->infront;
			temp->next = p;
			temp->data.address = p->data.address;
			temp->data.num = p->data.num;
			p->infront->next = temp;
			p->infront = temp;
			p->data.address = temp->data.address + temp->data.size;
			p->data.size -= request;
			p->data.num += 1;
			p->data.flag = 1;
			return OK;
		}
		p->data.flag = 1;
		p = p->next;
	}
	return ERROR;
}
//最佳适应算法
Status Best_fit(int request)
{
	int ch; //记录剩余空间
	Node *p = first->next;;
	Node *q = NULL; //记录插入位置
	LinkList temp = (LinkList)malloc(sizeof(Node));
	temp->data.size = request;
	temp->data.state = 1;
	p->data.num = 1;
	while (p) //初始化最小空间和最佳位置
	{
		if ((p->data.state == 0) && (p->data.size >= request))
		{
			if (q == NULL)
			{
				q = p;
				ch = p->data.size - request;
			}
			else if ((p->data.state == 0) && (q->data.size > p->data.size))
			{
				q = p;
				ch = p->data.size - request;
			}
		}
		p = p->next;
	}
	if (q == NULL)
	{
		return ERROR;//没有找到空闲块
	}
	else if (q->data.size == request)
	{
		q->data.state = 1;
		return OK;
	}
	else
	{
		temp->infront = q->infront;
		temp->next = q;
		temp->data.address = q->data.address;
		temp->data.num = q->data.num;
		q->infront->next = temp;
		q->infront = temp;
		q->data.address += request;
		q->data.size = ch;
		q->data.num += 1;
		return OK;
	}
	return OK;
}

//最差适应算法
Status Worst_fit(int request)
{
	int ch; //记录最大剩余空间
	Node *p = first->next;
	Node *q = NULL; //记录最佳插入位置
	LinkList temp = (LinkList)malloc(sizeof(Node));
	temp->data.size = request;
	temp->data.state = 1;
	p->data.num = 1;
	while (p) //初始化最大空间和最佳位置
	{
		if (p->data.state == 0 && (p->data.size >= request))
		{
			if (q == NULL)
			{
				q = p;

				ch = p->data.size - request;
			}
			else if (q->data.size < p->data.size)
			{
				q = p;
				ch = p->data.size - request;
			}
		}
		p = p->next;
	}
	if (q == NULL) return ERROR;//没有找到空闲块
	else if (q->data.size == request)
	{
		q->data.size = 1;
		return OK;
	}
	else
	{
		temp->infront = q->infront;
		temp->next = q;
		temp->data.address = q->data.address;
		temp->data.num = q->data.num;
		q->infront->next = temp;
		q->infront = temp;
		q->data.address += request;
		q->data.size = ch;
		q->data.num += 1;
		return OK;
	}
	return OK;
}

//分配主存
Status allocation(int a)
{
	int request;//申请内存大小
	printf("请输入申请分配的主存大小(单位:KB):");
	scanf_s("%d", &request);
	if (request < 0 || request == 0)
	{
		printf("分配大小不合适，请重试！");
		return ERROR;
	}
	switch (a)
	{
	case 1: //默认首次适应算法
		if (First_fit(request) == OK) printf("\t****分配成功！****");
		else printf("\t****内存不足，分配失败！****");
		return OK;
		break;
	case 2: //循环首次适应算法
		if (Next_fit(request) == OK) printf("\t****分配成功！****");
		else printf("\t****内存不足，分配失败！****");
		return OK;
		break;
	case 3: //选择最佳适应算法
		if (Best_fit(request) == OK) printf("\t****分配成功！****");
		else printf("\t****内存不足，分配失败！****");
		return OK;
		break;
	case 4: //选择最差适应算法
		if (Worst_fit(request) == OK) printf("\t****分配成功！****");
		else printf("\t****内存不足，分配失败！****");
		return OK;
		break;
	}
}

Status deal1(Node *p)//处理回收空间
{
	Node *q = first;
	for (; q != NULL; q = q->next)
	{
		if (q == p)
		{
			if (q->infront->data.state == 0 && q->next->data.state != 0)
			{
				q->infront->data.size += q->data.size;
				q->infront->next = q->next;
				q->next->infront = q->infront;
				q = q->infront;
				q->data.state = 0;
				q->data.num = flag - 1;
			}
			if (q->infront->data.state != 0 && q->next->data.state == 0)
			{
				q->data.size += q->next->data.size;
				q->next = q->next->next;
				q->next->next->infront = q;
				q->data.state = 0;
				q->data.num = flag;
			}
			if (q->infront->data.state == 0 && q->next->data.state == 0)
			{
				q->infront->data.size += q->data.size;
				q->infront->next = q->next;
				q->next->infront = q->infront;
				q = q->infront;
				q->data.state = 0;
				q->data.num = flag - 1;
			}
			if (q->infront->data.state != 0 && q->next->data.state != 0)
			{
				q->data.state = 0;
			}
		}
	}
	return OK;
}

Status deal2(Node *p)//处理回收空间
{
	Node *q = first;
	for (; q != NULL; q = q->next)
	{
		if (q == p)
		{
			if (q->infront->data.state == 0 && q->next->data.state != 0)
			{
				q->infront->data.size += q->data.size;
				q->infront->next = q->next;
				q->next->infront = q->infront;
				q = p->infront;
				q->data.state = 0;
				q->data.num = flag - 1;
			}
			if (q->infront->data.state != 0 && q->next->data.state == 0)
			{
				q->data.state = 0;
			}
			if (q->infront->data.state == 0 && q->next->data.state == 0)
			{
				q->infront->data.size += q->data.size;
				q->infront->next = q->next;
				q->next->infront = q->infront;
				q = q->infront;
				q->data.state = 0;
				q->data.num = flag - 1;
			}
			if (q->infront->data.state != 0 && q->next->data.state != 0)
			{
				q->data.state = 0;
			}
		}
	}
	return OK;
}

//主存回收
Status recovery(int flag)
{
	Node *p = first;
	for (; p != NULL; p = p->next)
	{
		if (p->data.num == flag)
		{
			if (p->infront == first)
			{
				if (p->next != f_end)//当前P指向的下一个不是最后一个时
				{
					if (p->next->data.state == 0)      //与后面的空闲块相连
					{
						p->data.size += p->next->data.size;
						p->next->next->infront = p;
						p->next = p->next->next;
						p->data.state = 0;
						p->data.num = flag;
					}
					else p->data.state = 0;
				}
				if (p->next == f_end)//当前P指向的下一个是最后一个时
				{
					p->data.state = 0;
				}
			}//结束if(p->infront==block_first)的情况
			else if (p->infront != first)
			{
				if (p->next != f_end)
				{
					deal1(p);
				}
				else
				{
					deal2(p);
				}
			}//结束if(p->infront!=block_first)的情况
		}//结束if(p->data.num==flag)的情况
	}
	printf("\t****回收成功****");
	return OK;
}

//主函数
int main()
{
	int i;  //操作选择标记
	int a;//算法选择标记
	printf("**********************************************************\n");
	printf("\t\t内存分配算法\n");
	printf("\n(1)首次适应算法\n(2)循环首次适应算法\n(3)最佳适应算法\n(4)最差适应算法\n");
	printf("**********************************************************\n");
	printf("\n");
	printf("请输入所使用的内存分配算法:");
	scanf_s("%d", &a);
	while (a < 1 || a>4)
	{
		printf("输入错误，请重新输入所使用的内存分配算法:\n");
		scanf_s("%d", &a);
	}
	switch (a)
	{
	case 1:printf("\n\t****使用首次适应算法：****\n"); break;
	case 2:printf("\n\t****使用最佳适应算法：****\n"); break;
	case 3:printf("\n\t****使用最坏适应算法：****\n"); break;
	}
	InitList(); //开创空间表
	while (1)
	{
		show();
		printf("\t1: 分配内存\t2: 回收内存\t0: 退出\n");
		printf("请输入您的操作：");
		scanf_s("%d", &i);
		if (i == 1)
			allocation(a); // 分配内存
		else if (i == 2)  // 内存回收
		{
			printf("请输入您要释放的分区号：");
			scanf_s("%d", &flag);
			recovery(flag);
		}
		else if (i == 0)
		{
			printf("\n退出程序\n");
			break; //退出
		}
		else //输入操作有误
		{
			printf("输入有误，请重试！");
			continue;
		}
	}
}



