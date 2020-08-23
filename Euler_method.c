#include<stdio.h>
#include<math.h>
int main()
{
    
    int i;
    float theta = 0, x = 0.42, y = 0;
    for(i = 1; i<100; i++)
    {
        theta = theta + 0.05;
        x = x + 0.01 * cos(theta);
        y = y + 0.01 * sin(theta);
    }
    printf("%f %f %f",theta,x,y);
    return 0;
}
