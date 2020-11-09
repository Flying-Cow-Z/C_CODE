#include<stdio.h>
#include<windows.h>
//#define ROW 3
//#define COL 4



//void bubble_sort(int arr[],int num)
//{
//	int i = 0;
//	for (; i < num - 1; i++)
//	{
//		int j = 0;
//		for (; j < num - 1 - i; j++)
//		{
//			if (arr[j]>arr[j + 1]){
//				int temp = 0;
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
int main()

{
	int arr[10] = {1,2,3,4,5};
	printf("%p\n",arr);
	printf("%p\n", &arr[0]);
	printf("%p\n", *arr);
	printf("%p\n", arr+1);
	printf("%p\n", &arr+1);


	/*int arr[] = { 2, 5, 9, 8, 6, 4, 7, 3 };
	int num = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, num);
	int a = 0;
	for (; a < num;a++){
		printf("%d ",arr[a]);
	}


*/



	/*int arr[ROW][COL];
	int i = 0;
	for (; i <= ROW;i++)
	{
		int j = 0;
		for (; j <= COL; j++)
		{
			printf("arr[%d][%d] = %p\n",i,j,&arr[i][j]);
		}
	}*/
	system("pause");
	return 0;
}