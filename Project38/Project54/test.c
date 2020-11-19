#include<stdio.h>
#include<windows.h>
void swap_arr(int arr[], int num){
	int start = 0;
	int end = num - 1;
	int temp;
	while (start < end){
		while (start < end&&arr[start] % 2 != 0){
			start++;
		}
		while (start < end&&arr[end] % 2 == 0){
			end--;
		}
		if (start < end)
		{
			temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
  			start++, end--;
		}
	}
}
int main()
{
	int arr[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	printf("before:\n");
	for (; i < num; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	swap_arr(arr, num);
	printf("after:\n");
	for (i = 0; i < num; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
