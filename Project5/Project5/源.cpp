#include <stdio.h>



#include<windows.h>



#pragma warning(disable : 4996)



int MAX(int _x, int _y)

{





	if (_x> _y)

	{

		c = _x;

		return c;

	}

	else if (_x <_y)

	{

		c = _y;

		return c;

	}

	else{

		c = _x;

		return c;

	}



}











int main()

{

	int c = 0;

	int a = 0;

	int b = 0;

	

	printf("请输入两个数字：");

	scanf("%d%d", &a, &b);



	c = MAX(a, b);

	printf("%d\n", c);

	system("pause");



	return 0;

}