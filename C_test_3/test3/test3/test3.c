#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

void fun(char p1[], char p2[])
{
	int length1 = strlen(p1);   //求传入数组的长度，用strlen函数
	int length2 = strlen(p2);
	int i = 0;
	int j = 0;
	for (i = length1; i < length1 + length2; i++)
	{
		if (j >= length2)
		{
			break;  //当数组p2下标到length2的时候，赋值结束，跳出循环
		}
		p1[i] = p2[j];
		j++;
	}
	p1[i] = '\0';
}

int main()
{
	char s1[80];
	char s2[40];
	void NONO();

	printf("Enter s1 and s2:\n");
	scanf("%s", s1);
	scanf("%s", s2);
	printf("s1=%s\n", s1);
	printf("s2=%s\n", s2);
	printf("Invoke fun(s1,s2):\n");
	fun(s1, s2);
	printf("After invoking:\n");
	printf("%s\n", s1);
	NONO();
	system("pause");
}

void NONO()
{/* 本函数用于打开文件，输入测试数据，调用fun函数，输出数据，关闭文件。*/
	int i;
	FILE *rf, *wf;
	char s1[80], s2[40];

	rf = fopen("in.dat", "r");
	wf = fopen("out.dat", "w");
	for (i = 0; i < 10; i++) {
		fscanf(rf, "%s", s1);
		fscanf(rf, "%s", s2);
		fun(s1, s2);
		fprintf(wf, "%s\n", s1);
	}
	fclose(rf);
	fclose(wf);
}