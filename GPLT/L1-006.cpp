//L1-006 连续因子 (20 分)
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    LL N;
    cin>>N;
    LL prd;
    int sq_n=sqrt(N);//连续因子的乘积中最大因子不可能比他的根号大
    int flag=0,start,len;//flag标志是否为符合条件的连续因子；start为连续因子的开始因子；len为因子长度
    for(len=12;len>=1;len--)//len=12由于13的阶乘已经大于2^31
    {
        for(start=2;start<=sq_n;start++)
        {
            prd=1;
            for(int i=start;i<start+len;i++)//这里的i<start+len是因为i从开始值每次+1到len次之后最大不能超过start+len
                //这里的循环条件？           
                prd*=i;
            if(N%prd==0)//这里的判断条件？
            {
                flag=1;
                break;
            }
        }
        if(flag)break;
    }
    if(!flag)
        cout<<1<<endl<<N;
    else
    {
        cout<<len<<endl<<start;
        for(int i=start+1;i<start+len;i++)
            cout<<'*'<<i;
    }

    return 0;
}