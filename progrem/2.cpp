//练习4-6 猜数字游戏 (15 分)
#include<stdio.h>
int main()
{
    int random,N,guess;
    int i;
    scanf("%d %d",&random,&N);
    scanf("%d",&guess);
    for(i=1;;i++)
    {
        if(i>N||guess<=0)
        {
            printf("Game Over");
            break;
        }
        if(guess>random)
            printf("Too big\n");
        if(guess<random)
            printf("Too small\n");
        if(guess==random)
        {
            if(i==1)
                printf("Bingo!");
            if(i!=1&&i<=3)
                printf("Lucky You!");
            if(i<=N&&i>3)
                printf("Good Guess!");
            break;
        }
        scanf("%d",&guess);
    }
    

    return 0;
}