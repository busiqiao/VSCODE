//习题4-2 求幂级数展开的部分和 (20 分)
#include<stdio.h>
#include<math.h>
double prime(int num)
{
    double i,sum=1;
    for(i=1;i<=num;i++)
        sum*=i;
    return sum;
}
int main()
{
    double x,sum=0,tmp;
    scanf("%lf",&x);
    for(int i=0;;i++)
    {
        
        if(tmp<0.00001)break;
        tmp=pow(x,i)/prime(i);
        sum+=tmp;
    }
    printf("%lf",sum);

    return 0;
}