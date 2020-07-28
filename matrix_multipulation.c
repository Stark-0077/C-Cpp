#include<stdio.h>

int main()
{
    int a[10][10], b[10][10], c[10][10], n , m , q;
    //row column(row) column
    scanf("%d%d%d",&n,&m,&q);
    int i,j,k;
    int sum;
    // read the first matrix
    for(i = 1; i<=n;i++)
        for(j = 1; j<=m; j++)
            scanf("%d",&a[i][j]);

    // read the second matrix
    for(i = 1; i<=m; i++)
        for(j = 1; j<=q; j++)
            scanf("%d",&b[i][j]);
    
    //show the input matrix
    printf("first matrix:");
    printf("\n");
    for(i = 1;i<=n; i++)
    {   printf("\n");
        for(j = 1; j<=m; j++)
            printf("%d ",a[i][j]);
    }
    printf("\n");
    printf("second matrix:");
    printf("\n");
    for(i = 1; i<=m; i++)
    {   printf("\n");
        for(j = 1; j<=q; j++)
            printf("%d ",b[i][j]);
    }

    printf("\n");
    // matrix multipulation
    for(i=1; i <= n; i++)
    {
        for(j = 1; j<=q; j++)
        {
            sum = 0;
            for(k = 1; k<=m; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}
