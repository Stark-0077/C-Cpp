#include<stdio.h>
#include<math.h>
#define pai 3.14
int main()
{
    int i;
    float theta = 0, x = 4/(3*pai), y = 0;
    for(i = 1; i<=100; i++)
    {
        theta = theta + 0.0471;
        x = x + 0.01 * cos(theta);
        y = y + 0.01 * sin(theta);
        printf("step %d  \t", i );
        printf("%f %f %f",theta,x,y);
        printf("\n");
    }
    return 0;
}
