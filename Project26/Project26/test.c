int  ShowInt(int x)
{

	if (1 == x||2 == x)
	{
		return 1;
	}
	return ShowInt(x-1)+ShowInt(x-2);

	//if (x > 1)
	//{
	//	return x * showint(x - 1);
	//}
	//return 1;


	/*if (x > 9)
	{
		ShowInt(x / 10);

	}
	printf("%d ",x % 10);*/
}