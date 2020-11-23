#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<assert.h>

int main()
{
	char str[] = "hello world";

	printf("×óĞı×Ö·ûµÄ¸öÊı: ");
	int k = 0;
	scanf_s("%d", &k);
	int num = strlen(str);
	for (int j = 0; j < k; j++)
	{

		int temp = str[0];
		for (int i = 0; i < num - 1; i++)
		{
			str[i] = str[i + 1];

		}
		str[num-1] = temp;
	}

	printf("%s\n", str);


	system("pause");
	return 0;
}

//void Show(int arr[],int num)
//{
//	int i = 0;
//	for (; i < num; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//}
//
//void swap(char*x, char*y,int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		*(x + i) ^= *(y + i);	
//		*(y + i) ^= *(x + i);
//		*(x + i) ^= *(y + i);
//	}
//}
//int MySort(void* base,int num, int size,int(*Compar)(const void*, const void*))
//{
//	assert(base);
//	assert(Compar);
//	char*_base = (char*)base;
//	int flag = 0;
//	int i = 0;
//	for (; i < num - 1; i++)
//	{
//		int j = 0;
//		for (; j < num - 1 - i; j++)
//		{
//			if (Compar(_base + size*j, _base + size*(j + 1))>0)
//			{
//				flag = 1;
//				swap(_base + size*j, _base + size*(j + 1),size);
//			}
//		}
//		if (0 == flag)
//		{
//			break;
//		}
//	}
//
//}
//int Compar(const void*vx, const void*vy)
//{
//	int *x = (int *)vx;
//	int *y = (int *)vy;
//	if (*x > *y)
//	{
//		return 1;
//	}
//	else if (*x < *y)
//	{
//		return -1;
//	}
//	else
//	{
//		return 0;
//	}
//
//}
//int main()
//{
//	//void qsort(void* base, size_t num, size_t size,
//	//int(*compar)(const void*, const void*));
//	
//	int arr[8] = { 6, 5, 9, 88, 4, 7, 2, 3 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	Show(arr,num);
//
//	MySort(arr, num, sizeof(int), Compar);
//	Show(arr, num);
//	system("pause");
//	return 0;
//}