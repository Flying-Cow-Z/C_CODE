#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{

	/*char str[5] = { 'a', 'a', 'a', 'a', 'a' };
	printf("%s", str);*/

	/*char ch[10];
	int i = 0;
	for (; i < 10; i++)
	{
		scanf_s("%c", &ch[i]);
	}
	
	for (i = 0; i < 10; i++)
	{
		printf("%c", ch[i]);
	}*/

	char str[] = "helloworld";
	printf("�����ַ��ĸ���: ");
	int k = 0;
	scanf_s("%d", &k);
	int num = strlen(str);

	int j = 0;

	for (; j < k; j++)
	{

		int temp = str[0];

		for (int i = 0; i < num - 1; i++)
		{
			str[i] = str[i + 1];


		}
		str[num - 1] = temp;
	}


	printf("��ת����ַ���:%s\n", str);

	printf("�����ַ�����");

	char ch[11] = "";
	int i = 0;
	//1.while (getchar() != '\n');
	
	//2.getchar();
	/*3. char th;
	scanf("%c",&th);  ����%c -> \n */
		for (; i < 10; i++) 
		{
			scanf("%c", &ch[i]);
		}
	
	printf("%s\n",ch);
	if (strcmp(str,ch)  ==  0 )
	{
		printf("����ת����ַ�����\n");
		
	}
	else
	{
		printf("������ת����ַ�����\n");
	}



	system("pause");
	return 0;
}

