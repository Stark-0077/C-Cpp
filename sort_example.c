#include<stdio.h>

// inputs: two lines
// line 1: the number of student
// line 2: the ISBN of books

// outputs: two lines
// line 1: the books needed to buy
// line 2: order the ISBN from small to large

// way 1' sort first, then delete the repeated one
int a[101],n;               // global variables

int quicksort(int left,int right)
{
    if(left > right) return 0;
    int temp;                   //benchmark number
    int i,j;                    // two "poniter"
    int t;                     // used for swaping
    i = left;
    j = right;
    temp = a[i];
    while(i!=j)
    {
        while(a[j]<=temp && i<j)
            j--;
        while(a[i]>=temp && i<j)
            i++;
        if(i<j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[left] = a[i];                // pay attention to these two line!!!
    a[i] = temp;
    quicksort(left,i-1);
    quicksort(i+1,right);

}

int main()
{
    int i;
    scanf("%d",&n);          // read the student numbers
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);    //read the ISBN number one by one
    }
    quicksort(1,n);

    for(i=1;i<=n;i++)
    printf("%d ",a[i]);

    printf("\n");

    printf("%d ",a[1]);
    for (i=2;i<=n;i++)
    {
        if(a[i-1]!=a[i])
        {
            printf("%d ",a[i]);
        }
    }
    return 0 ;
}