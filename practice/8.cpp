#include<bits/stdc++.h>
using namespace std;

int flag=0;
int a[100]={0};
typedef struct TNode* Tree;
struct TNode{
	int data;
	Tree Left,Right;
};

Tree CreatTree(Tree BT)
{
	int da;
	cin>>da;
	if(da!=-100000)
	{
		BT->data=da;
		BT->Left=new TNode;
		CreatTree(BT->Left);
		BT->Right=new TNode;
		CreatTree(BT->Right);
	}
	
	return BT;
}

int SumTree(Tree BT)
{
	int m,n;
	if(BT!=NULL)
	{
		m=SumTree(BT->Left);
		n=SumTree(BT->Right); 
		a[flag]=a[flag]+m+n;
		flag++;
	}
	return BT->data;
}

int main()
{
	Tree A=new TNode;
	A=CreatTree(A);
	CreatTree(A);
	int max=0;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	cout<<max<<endl;
	
	return 0;
}