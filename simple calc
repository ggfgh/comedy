#include <stdio.h>

int main() 
{
	int b = 1;

	long double i, j, result;
	char symbol = ' ';
	while (b) 
	{
		printf("请输入合法四则运算式\n");
		scanf("%Lf %c %Lf", &i, &symbol, &j);
		if (symbol == '+') 
		{
			result = i + j;
			b = 0;
		} 
		else if (symbol == '-') 
		{
			result = i - j;
			b = 0;
		} else if (symbol == '*') 
		{
			result = i * j;
			b = 0;
		} 
		else if (symbol == '/') 
		{
			if (j == 0) 
			{
				continue;
			}
			result = i / j;
			b = 0;
		}
		else //其他不合法的情况 
		 {
			continue;
		 }
	}
	
	printf("计算结果为%Lf", result);

	return 0;
}
