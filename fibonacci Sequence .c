#include <stdio.h>

int main()
{

  long a = 1, b = 1, c, i;

        for (i = 3; i <= 24; i++)
        {
                c = a + b;
                a = b;
                b = c;
        }

        printf("两年后，总共有%ld只兔子！\n", c);

        return 0;

}
