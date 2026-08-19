#include <stdio.h>
int main()
{
    int a=3, b=5, k, z=1;
    do
    {
        for(k=a+b; k>=6; k=k-3)
        {
            if(k % 4 == 0)
                printf("&");
            else if(k % 2 == 0)
                printf("!");
            else
                printf("?");
        }
        printf("\n");
        b = b - z;
        if(b < 3)
            z = 2;
        a = a + 1;
    }
    while(a % 2 == 0);
}
