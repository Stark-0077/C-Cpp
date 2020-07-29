#include<stdio.h>
int main()
{
    int a[10][10], b[10][10], n , m ;
    //row column(row) column
    scanf("%d%d",&n,&m);
    int i,j;
 
    // read  matrix
    for(i = 1; i<=n;i++)
        for(j = 1; j<=m; j++)
            scanf("%d",&a[i][j]);

    // transpose matrix
    for(j = 1; j<=m; j++)
        for(i = 1; i<=n; i++)
        {
            b[j][i] = a[i][j];
        }

    for(i = 1;i<=n; i++)
    {   printf("\n");
        for(j = 1; j<=m; j++)
            printf("%d ",b[i][j]);
    }
    return 0;
}
