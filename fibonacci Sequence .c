#include <stdio.h>

int main()
{
/*斐波那契数列F(0)=0，F(1)=1, F(n)=F(n - 1)+F(n - 2)（n ≥ 2，n ∈ N*）*/

        long a = 1, b = 1, c, i;

        for (i = 3; i <= 24; i++)
        {
                c = a + b;
                a = b;
                b = c;
        }

        printf("两年后，总共有%ld对兔子！\n", c);

        return 0;
}
