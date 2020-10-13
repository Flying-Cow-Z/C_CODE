#include<stdio.h>
#include<windows.h>

int main()
{
	
	const char *str = "|/-\\-";
	int index = 0;
	while (1){
		printf("%c\r", str[index % 4]);
		Sleep(1000);
		index++;
	}
	system("pause");
	return 0;
}