//L1-009 N个数求和 (20 分)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[100]={0},b[100]={0},flag,tmp;
    string num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        for(int j=0;num[j];j++)
        {
            if(num[j]=='/')
            {
                flag=j;
                break;
            } 
            if(num[j]=='-')
            {
                j++;
                num[j]=-num[j];
            }
            tmp=num[j]-'0';
            a[i]=a[i]*10+tmp;         
        }
        for(int q=flag+1;num[q];q++)
        {
            tmp=num[q]-'0';
            b[i]=b[i]*10+tmp;
        }               
    }
    

}