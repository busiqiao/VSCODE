//练习4-10 找出最小值 (20 分)
#include<stdio.h>

int main()
{
    int N;
    int num,min,tmp;
    scanf("%d %d",&N,&min);
    for(int i=0;i<N-1;i++)
    {
        scanf("%d",&tmp);
        if(tmp<min)
        {
            min=tmp;
        }
    }
    printf("min = %d",min);

    return 0;
}