//7-2 简易连连看 (10 分)
#include<iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	char a[2*N][2*N];	
	for(int i=0;i<2*N;i++)
	{
		for(int j=0;j<2*N;j++)
		{
			cin>>a[i][j];
		}
	}
	int K;
	cin>>K;
	int count=0,flag=0,i,j;
	for(i=0;i<K;i++)
	{
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
		if(a[x1-1][y1-1]==a[x2-1][y2-1]&&a[x1-1][y1-1]!='*')
		{
            a[x1-1][y1-1]='*';
			a[x2-1][y2-1]='*';
            flag++;
            if(flag==N*N*2)
            {
                cout<<"Congratulations!";
                return 0;
            }
                for(int i=0;i<2*N;i++)
			    {
				    for(int j=0;j<2*N;j++)
				    {
                        if(j<2*N-1)
					        cout<<a[i][j]<<" ";
                        else cout<<a[i][j];
				    }
				    cout<<endl;
			    }
        }
			
		else{
			cout<<"Uh-oh"<<endl;
			count++;
            if(count==3)
		    {
			    cout<<"Game Over";
			    return 0;
		    }
		}
	}
    return 0;
}