#include<stdio.h>
#include<windows.h>

int main(){
	int n = 0;
	int arr[5] = { 1, 2, 3, 4 };
	int num = sizeof(arr) / sizeof(arr[0]);
	printf("数组元素的个数是%d\n", num);
	for (n = 0; n <= 4; n++){
		printf("%d", arr[n]);
	}
	printf("\n");
	system("pause");
	return 0;
}
