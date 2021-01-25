#include <stdio.h>

int main()
{
char ch;
printf("请输入明文：");
do{
	ch = getchar();
	if((ch >= 'A' && ch <= 'X' )|| (ch >= 'a' && ch <= 'x'))
	{
		ch = ch + 3;
	}
	else if(ch > 'X' && ch <= 'Z' )
	{
		
		ch = 'A' + ( 2 - ( 'Z' - ch));
	}
	else if (ch > 'x' && ch <= 'z')
	{
		ch = 'a' + ( 2 - ( 'z' - ch));
	}
	putchar(ch);
} while (ch != '\n');
}
