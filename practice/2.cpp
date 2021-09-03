//7-3 有理数均值 (10 分)
#include<iostream>
using namespace std;

int multiple(int a,int b)//最大公因数
{
    int m,n;
    while (b!=0)
    {
        if(a<b)
        {
            m=a;
            a=b;
            b=m;
        }
        n=a%b;
        a=b;
        b=n;
    }
    return a;    
}
int divisor(int a,int b) //最小公倍数 
{
    int t,m,n;
    m=a*b;
    t=multiple(a,b); //调用求最大公约数的函数 
    n=m/a;
    return(n);
}

int main()
{
    int N;
    cin>>N;
    int fz[N]={0},fm[N]={0};
    for(int i=0;i<N;i++)
        scanf("%d/%d",&fz[i],&fm[i]);
    int i,end;
    for(i=0;i<N;i++)
    {
        int a,b;
        a=divisor(fm[i],fm[i+1]);
        fz[i]=fz[i]*a/fm[i];
        fz[i+1]=fz[i+1]*a/fm[i+1]+fz[i];
        fm[i+1]=a;
    }
    fm[i]*=N;
    end=multiple(fz[i],fm[i]);
    fz[i]/=end;
    fm[i]/=end;
    if(fm[i]==1)cout<<fz[i];
    else cout<<fz[i]<<'/'<<fm[i];

    return 0;
}