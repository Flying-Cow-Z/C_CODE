#include <stdio.h>
#include <string.h>
#include <windows.h>

#pragma warning(disable:4996)

#define MAX 600

//����ֵ ������(�β�, �βΣ��β�, ...){
//	//�����Ĵ���
//}

//�շ�
int MyAdd(int x, int y){
	int result = x + y;
	return result;
	//return x + y;
}
int MySub(int x, int y){
	return x - y;
}
int MyMul(int x, int y){
	return x * y;
}
int MyDiv(int x, int y){
	return x / y;
}
int main()
{
	while (1){
		printf("please enter two data: ");
		int x = 0;
		int y = 0;
		/*scanf("%d ", &x);
		scanf("%d ", &y);*/

		scanf("%d %d", &x, &y);
		//fflush(stdout);

		char op ;
		printf("\n please enter you op<+-*/>:\n");
		scanf("%c", &op);
		

		if ('+' == op){
			printf("%d + %d = %d\n", x, y, MyAdd(x, y));
		}
		else if ('-' == op){
			printf("%d - %d = %d\n", x, y, MySub(x, y));
		}
		else if ('*' == op){
			printf("%d * %d = %d\n", x, y, MyMul(x, y));
		}
		else if ('/' == op){
			if (y != 0){
				printf("%d / %d = %d\n", x, y, MyDiv(x, y));
			}
			else{
				printf("div zero! error!!\n");
			}
		}
		else{
			//TODO
			printf("enter Error!\n");
		}
	}

	//10..
	//int  i = 0;
	//do{
	//	printf("bit\n");
	//	i++;
	//} while (1); //��ִ�У����ж�
	//for (int i = 0; i < 10; i++){
	//	printf("i: %d\n", i);
	//	Sleep(1000);
	//}
	//for (;;){
	//	printf(".");
	//}
	//for (��������; �����ж�; ��������){
	//	//��ִ�еĴ���
	//}
	//printf("OK");
	//Sleep(3000);
	//int line = 0;
	//while (line <= MAX){
	//	printf("coding...\n");
	//	line++;
	//}
	//if (line > MAX){
	//	printf("���������߷壡\n");
	//}
	/*printf("%d\n", 11== 11);
	printf("%d\n", 11 == 10);*/
	//bool ture/false,Cû��bool����
	//while (1){
	//	int select = 0;
	//	printf("����û�кú�coding�أ�<0:yes, 1:ing, 2:no># ");
	//	scanf("%d", &select);
	//	if (0 == select){
	//		printf("��ϲ�����ܴﵽ�õ�offer!\n");
	//	}
	//	else if (1 == select){
	//		printf("��ϲ��������·��offer\n");
	//	}
	//	else{
	//		printf("��Ǹ������!\n");
	//	}
	//}
	//int i = 1; //��������
	//while(i <= 10 ){ //�����ж�. 1. (��ִ���ڲ�����) 2. �ڽ���while�ж�
	//	printf("i : %d\n", i);
	//	i = i + 1; //i += 1; i++, ++i; //��������
	//	Sleep(1000);
	//}

	//while (1){
	//	printf(".");
	//}
	//while (����[�仯]){
	//	//ִ�ж��õ����
	//}
	//for;
	//do{} while;

	//if (����){
	//	//��������
	//	//ִ�иô�����еĴ���
	//}
	//else{
	//	//����������
	//	//ִ�иô�����еĴ���
	//}






	//char c = '\'';
	//printf("%c\n", c);
	//7:0~6
	//2:0 1
	//8:0~7
	//16:0 1 2 3 4 5 6 7 8 9 A B C D E F
	// \x3F
	//11 -> 1*10 + 1
	//11 -> 1*2^1+1*2^0 -> 3
	//3F -> 3*16^1 + F*16^0 -> 48+15 -> 63
	/*printf("\c");
	printf("%d\n", sizeof("\c"));*/
	//\32����������
	/*printf("%d\n", strlen("c:\test\328\test.c"));*/ //C
	//printf("%d\n", strlen("c:\test\328\test.c")); //C++
	//printf("%d\n", strlen("abcdef"));//�ַ����ĳ���
	//printf("%d\n", sizeof("abcdef"));//�ַ����Ĵ�С
	//printf("\'"); 
	//printf("\"");
	//printf("c:\code\test.c\n");
	//printf("��\\��\n"); //ת��:�����⺬��ת����ͨ���壬������ͨ����ת�����⺬��
	//char str1[] = "bit";
	//char str2[] = {'b','i','t'};
	//char str3[] = { 'b', 'i', 't','\0' };
	//printf("%s\n", str1);
	//printf("%s\n", str2);
	//printf("%s\n", str3);
	//char str[16] = "hello bit!";
	//printf("%d\n", sizeof(""));
	//printf("%d\n", sizeof(str1));

	system("pause");//���Ǳ���ģ�������Ϊ�˱��ڹ۲�
	return 0;
}

