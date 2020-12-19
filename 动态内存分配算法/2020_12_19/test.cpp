#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
using namespace std;

#define OK 1    //���
#define ERROR 0 //����

typedef int Status;

typedef struct free_work//����һ��������˵����ṹ
{
	int num; //�������
	long address; //��ʼ��ַ
	long size;   //������С
	int state;   //����״̬
	int flag;  //�Ƿ񱻷��ʹ�
}ElemType;

typedef struct Node// ���Ա��˫������洢�ṹ
{
	ElemType data;
	struct Node *infront; //ǰ��ָ��
	struct Node *next;  //���ָ��
}Node, *LinkList;

LinkList first; //ͷ���ͷ���
LinkList f_end;  //β���
int flag;//��¼Ҫɾ���ķ������

Status InitList()//������ͷ�����ڴ�ռ�����
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

void sort()//���������������
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

//��ʾ����������
void show()
{
	int flag = 0;//������¼�������
	Node *p = first;

	sort();
	printf("\n\t\t���ռ���������\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
	printf("�������\t��ʼ��ַ\t������С\t����״̬\n\n");
	p = p->next;
	while (p)
	{
		printf("%d\t\t%d\t\t%d", p->data.num, p->data.address, p->data.size);
		if (p->data.state == 0) printf("\t\t����\n\n");
		else printf("\t\t�ѷ���\n\n");
		p = p->next;
	}
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
}

//�״���Ӧ�㷨
Status First_fit(int request)
{
	//Ϊ������ҵ�����¿ռ��ҳ�ʼ��
	Node *p = first->next;
	LinkList temp = (LinkList)malloc(sizeof(Node));
	temp->data.size = request;
	temp->data.state = 1;
	p->data.num = 1;
	while (p)
	{
		if ((p->data.state == 0) && (p->data.size == request))
		{//�д�Сǡ�ú��ʵĿ��п�
			p->data.state = 1;
			return OK;
			break;
		}
		else if ((p->data.state == 0) && (p->data.size > request))
		{//�п��п���������������ʣ��
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
//ѭ���״���Ӧ�㷨
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
		{//�д�Сǡ�ú��ʵĿ��п�
			p->data.state = 1;
			p->data.flag = 1;
			return OK;
		}
		else if ((p->data.state == 0) && (p->data.size > request) && (p->data.flag == 0))
		{//�п��п���������������ʣ��
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
//�����Ӧ�㷨
Status Best_fit(int request)
{
	int ch; //��¼ʣ��ռ�
	Node *p = first->next;;
	Node *q = NULL; //��¼����λ��
	LinkList temp = (LinkList)malloc(sizeof(Node));
	temp->data.size = request;
	temp->data.state = 1;
	p->data.num = 1;
	while (p) //��ʼ����С�ռ�����λ��
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
		return ERROR;//û���ҵ����п�
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

//�����Ӧ�㷨
Status Worst_fit(int request)
{
	int ch; //��¼���ʣ��ռ�
	Node *p = first->next;
	Node *q = NULL; //��¼��Ѳ���λ��
	LinkList temp = (LinkList)malloc(sizeof(Node));
	temp->data.size = request;
	temp->data.state = 1;
	p->data.num = 1;
	while (p) //��ʼ�����ռ�����λ��
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
	if (q == NULL) return ERROR;//û���ҵ����п�
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

//��������
Status allocation(int a)
{
	int request;//�����ڴ��С
	printf("�������������������С(��λ:KB):");
	scanf_s("%d", &request);
	if (request < 0 || request == 0)
	{
		printf("�����С�����ʣ������ԣ�");
		return ERROR;
	}
	switch (a)
	{
	case 1: //Ĭ���״���Ӧ�㷨
		if (First_fit(request) == OK) printf("\t****����ɹ���****");
		else printf("\t****�ڴ治�㣬����ʧ�ܣ�****");
		return OK;
		break;
	case 2: //ѭ���״���Ӧ�㷨
		if (Next_fit(request) == OK) printf("\t****����ɹ���****");
		else printf("\t****�ڴ治�㣬����ʧ�ܣ�****");
		return OK;
		break;
	case 3: //ѡ�������Ӧ�㷨
		if (Best_fit(request) == OK) printf("\t****����ɹ���****");
		else printf("\t****�ڴ治�㣬����ʧ�ܣ�****");
		return OK;
		break;
	case 4: //ѡ�������Ӧ�㷨
		if (Worst_fit(request) == OK) printf("\t****����ɹ���****");
		else printf("\t****�ڴ治�㣬����ʧ�ܣ�****");
		return OK;
		break;
	}
}

Status deal1(Node *p)//������տռ�
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

Status deal2(Node *p)//������տռ�
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

//�������
Status recovery(int flag)
{
	Node *p = first;
	for (; p != NULL; p = p->next)
	{
		if (p->data.num == flag)
		{
			if (p->infront == first)
			{
				if (p->next != f_end)//��ǰPָ�����һ���������һ��ʱ
				{
					if (p->next->data.state == 0)      //�����Ŀ��п�����
					{
						p->data.size += p->next->data.size;
						p->next->next->infront = p;
						p->next = p->next->next;
						p->data.state = 0;
						p->data.num = flag;
					}
					else p->data.state = 0;
				}
				if (p->next == f_end)//��ǰPָ�����һ�������һ��ʱ
				{
					p->data.state = 0;
				}
			}//����if(p->infront==block_first)�����
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
			}//����if(p->infront!=block_first)�����
		}//����if(p->data.num==flag)�����
	}
	printf("\t****���ճɹ�****");
	return OK;
}

//������
int main()
{
	int i;  //����ѡ����
	int a;//�㷨ѡ����
	printf("**********************************************************\n");
	printf("\t\t�ڴ�����㷨\n");
	printf("\n(1)�״���Ӧ�㷨\n(2)ѭ���״���Ӧ�㷨\n(3)�����Ӧ�㷨\n(4)�����Ӧ�㷨\n");
	printf("**********************************************************\n");
	printf("\n");
	printf("��������ʹ�õ��ڴ�����㷨:");
	scanf_s("%d", &a);
	while (a < 1 || a>4)
	{
		printf("�������������������ʹ�õ��ڴ�����㷨:\n");
		scanf_s("%d", &a);
	}
	switch (a)
	{
	case 1:printf("\n\t****ʹ���״���Ӧ�㷨��****\n"); break;
	case 2:printf("\n\t****ʹ�������Ӧ�㷨��****\n"); break;
	case 3:printf("\n\t****ʹ�����Ӧ�㷨��****\n"); break;
	}
	InitList(); //�����ռ��
	while (1)
	{
		show();
		printf("\t1: �����ڴ�\t2: �����ڴ�\t0: �˳�\n");
		printf("���������Ĳ�����");
		scanf_s("%d", &i);
		if (i == 1)
			allocation(a); // �����ڴ�
		else if (i == 2)  // �ڴ����
		{
			printf("��������Ҫ�ͷŵķ����ţ�");
			scanf_s("%d", &flag);
			recovery(flag);
		}
		else if (i == 0)
		{
			printf("\n�˳�����\n");
			break; //�˳�
		}
		else //�����������
		{
			printf("�������������ԣ�");
			continue;
		}
	}
}



