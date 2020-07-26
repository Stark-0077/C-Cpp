#include <stdio.h>

int main()
{
    int a[100],i,j,t,n;

    //we will input n numbers
    scanf("%d",&n);

    //input these numbers one by one
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    //bubble sort number from large to small
    for(i=1; i<=n-1; i++)    // n numbers sort, only need n-1 times 

        for(j=1; j<=n-i; j++)   // pay attention to this line!!!
        {
            if(a[j]<a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
        
    return 0;


}