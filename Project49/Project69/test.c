#include <stdio.h>
#include <string.h>
#include <windows.h>

#pragma warning(disable:4996)

#define MAX 600

//返回值 函数名(形参, 形参，形参, ...){
//	//正常的代码
//}

//驼峰
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
	//} while (1); //先执行，在判定
	//for (int i = 0; i < 10; i++){
	//	printf("i: %d\n", i);
	//	Sleep(1000);
	//}
	//for (;;){
	//	printf(".");
	//}
	//for (条件设置; 条件判定; 条件更新){
	//	//待执行的代码
	//}
	//printf("OK");
	//Sleep(3000);
	//int line = 0;
	//while (line <= MAX){
	//	printf("coding...\n");
	//	line++;
	//}
	//if (line > MAX){
	//	printf("走向人生高峰！\n");
	//}
	/*printf("%d\n", 11== 11);
	printf("%d\n", 11 == 10);*/
	//bool ture/false,C没有bool类型
	//while (1){
	//	int select = 0;
	//	printf("你有没有好好coding呢？<0:yes, 1:ing, 2:no># ");
	//	scanf("%d", &select);
	//	if (0 == select){
	//		printf("恭喜，你能达到好的offer!\n");
	//	}
	//	else if (1 == select){
	//		printf("恭喜，你正在路上offer\n");
	//	}
	//	else{
	//		printf("抱歉。。。!\n");
	//	}
	//}
	//int i = 1; //条件设置
	//while(i <= 10 ){ //条件判定. 1. (先执行内部条件) 2. 在进行while判定
	//	printf("i : %d\n", i);
	//	i = i + 1; //i += 1; i++, ++i; //条件更新
	//	Sleep(1000);
	//}

	//while (1){
	//	printf(".");
	//}
	//while (条件[变化]){
	//	//执行对用的语句
	//}
	//for;
	//do{} while;

	//if (条件){
	//	//条件成立
	//	//执行该代码块中的代码
	//}
	//else{
	//	//条件不成立
	//	//执行该代码块中的代码
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
	//\32被单独解释
	/*printf("%d\n", strlen("c:\test\328\test.c"));*/ //C
	//printf("%d\n", strlen("c:\test\328\test.c")); //C++
	//printf("%d\n", strlen("abcdef"));//字符串的长度
	//printf("%d\n", sizeof("abcdef"));//字符串的大小
	//printf("\'"); 
	//printf("\"");
	//printf("c:\code\test.c\n");
	//printf("比\\特\n"); //转义:把特殊含义转成普通含义，或者普通含义转成特殊含义
	//char str1[] = "bit";
	//char str2[] = {'b','i','t'};
	//char str3[] = { 'b', 'i', 't','\0' };
	//printf("%s\n", str1);
	//printf("%s\n", str2);
	//printf("%s\n", str3);
	//char str[16] = "hello bit!";
	//printf("%d\n", sizeof(""));
	//printf("%d\n", sizeof(str1));

	system("pause");//不是必须的，仅仅是为了便于观察
	return 0;
}

