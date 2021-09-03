//7-4 敲笨钟 (10 分)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,i,j,flag=0,end;
    cin>>N;
    char a[100];
    char b[3]={'g','n','o'};
    char c[15]={'q','i','a','o',' ','b','e','n',' ','z','h','o','n','g','.'};
    for(i=0;i<N;i++)
    {
        gets(a);
        for(j=0;a[j];j++){}
        j-=2;
        end=j;
        int count;
        for(count=0;count<3;count++,j--)
        {
            if(a[j]!=b[count])break;
        }
        if(count!=3)
        {
            cout<<"Skipped"<<endl;
            flag=1;
            continue;
        }
        for(;j;j--)
        {
            if(a[j]==',')
            {
                j--;
                for(count=0;count<3;count++,j++)
                {
                    if(a[j]!=b[count])break;
                }
                if(count!=3)
                {
                    cout<<"Skipped"<<endl;
                    flag=1;
                    continue;
                }
            }
        }
        if(flag!=1)
        {
            int flag_1=0,flag_2=0;
            i=end;
            for(i;;i--)
            {
                if(flag_1==3) 
                {
                    flag_2=i-2;
                    break;
                }
                if(a[i]==' ')flag_1++;
            }
            for(int count=0;c[count-1];count++,flag_2++)
            {
                a[flag_2]=c[count];
            }
            puts(a);
        }

    }
    return 0;
}