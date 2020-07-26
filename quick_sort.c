#include<stdio.h>

int a[101],n;


void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right) return;    // expection

    temp = a[left];     //select left most number as "benchmark"
    i = left;           // i start form the leftmost
    j = right;          // j start form the rightmost

    while(i!=j)             // when i,j not meet each other
    {
        while(a[j]>=temp && i<j)   // from right most number, begin
            j--;                    // until find the number >= "benchmark" number
        

        while(a[i]<=temp && i<j)   // then left number
            i++;
        
        if(i<j)                  
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[left] = a[i];
    a[i] = temp;

    quicksort(left,i-1);
    quicksort(i+1,right);
}

int main()
{
    
    int i,j,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    quicksort(1,n);

    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    
    return 0;
}