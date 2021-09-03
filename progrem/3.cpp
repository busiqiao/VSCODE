//练习4-7 求e的近似值 (15 分)
#include<stdio.h>
double factorial(int i)
{
    int j;
    double sum=1;
    for(j=1;j<=i;j++)
    {
        sum*=j;
    }

    return sum;
}
int main()
{
    int N;
    int i,j;
    double sum=0;
    scanf("%d",&N);
    for(i=0;i<N+1;i++)
    {
        sum=sum+1/(double)factorial(i);
    }
    printf("%.8lf",sum);

    return 0;
}
