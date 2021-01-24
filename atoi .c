	int ch ;
	long long int num = 0;
	long long int temp = 0;//临时变量，用于测试是否超出范围
	int is_overflow = 0;

	const int max_int = (pow(2, sizeof(int) * 8) / 2 ) - 1;
	const int min_int = pow(2, sizeof(int) * 8) / (-2);

	printf("请输入代转换的字符串：");

	do
	{
		ch = getchar();//依次得到输入字符的ASCII

		if (ch >= '0' && ch <= '9') 
		{
			temp = 10 * num + (ch - '0');
			if (temp > max_int || temp < min_int) 
			{
				is_overflow = 1;
				break;
			} else 
			{
				num = temp;
			}
		}
		else 
		{
			if (num)
			{
				break;//如果已输出数字,则退出循环
			}
		}

	} while (ch != '\n');

	if (is_overflow) 
	{
		printf("数值超出范围，结果未定义！\n");
	} 
        else 
	{
		if (!num && num != 0)
		{
			printf("未找到任何数值！\n");
		} 
		else 
		{
			printf("结果是%lld\n", num);
		}
	 }
	return 0;
}
