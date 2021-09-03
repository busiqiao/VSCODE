//习题4-1 求奇数和 (15 分)
#include <stdio.h>

int main()
{
    int N;
    double sum = 0;
    int num;
    for (int i = 0; ; i++)
    {
        scanf("%d", &num);
        if (num <= 0)
            break;
        if (num % 2 != 0)
            sum += num;
    }
    printf("%.0lf", sum);

    return 0;
}