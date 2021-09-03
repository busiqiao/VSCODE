//练习4-11 统计素数并求和 (20 分)
#include <stdio.h>
#include <math.h>
int prime(int num)
{
    int i, tmp;
    tmp = (int)sqrt(num);
    for (i = 2; i <= tmp; i++)
        if (num % i == 0)
            return 0;
    return 1;
}
int main()
{
    int M, N;
    int sum = 0, count = 0;
    scanf("%d %d", &M, &N);
    for (int i = M; i <= N && M != 0; i++)
    {
        if(i==1)continue;
        if (prime(i))
        {
            sum += i;
            count++;
        }
    }
    printf("%d %d", count, sum);

    return 0;
}