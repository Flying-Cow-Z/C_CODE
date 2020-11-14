#include<stdio.h>
#include<windows.h>

//void Printf(int *arr, int n)
//{
//	int i = 0;
//	for (; i < n; i++)
//	{
//		printf("%d ",*(arr+i));
//	}
//	printf("\n");
//}
void fun(char *a)
{
	if (NULL == a){
		return;
	}
	else{
		char *start = a;
		char *end = a + strlen(a) - 1;
		while (start < end)
		{
			char temp = *start;
			
			*start = *end;
			*end = temp;

			start++, end--;
			
		}
	}

}
int main()
{

	char a[] = "abcd1234";
	fun(a);
	/*int arr[5] = {1,2,3,4,5};
	int num = sizeof(arr) / sizeof(arr[0]);
	printf(arr,num);*/
	system("pause");
	return 0;
}