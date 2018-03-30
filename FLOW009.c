#include <stdio.h>

int main()
{
    long t,a;
    float b;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&a);
        scanf("%f",&b);
        if(a>1000)
            printf("%.6f\n",a*b*0.9);
        else
            printf("%.6f\n",a*b);
    }
    return 0;
}
