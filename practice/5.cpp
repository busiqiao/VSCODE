#include<bits/stdc++.h>
using namespace std;

typedef struct Node *PtrToNode;
struct Node{
	long long int x;
	long long int z;
	PtrToNode Next;
};
typedef PtrToNode List;

int main()
{
	List L;
	List p=(List)malloc(sizeof(struct Node));
	L=p;
	long long int a,b;
	while(cin>>a>>b)
	{
		p->x=a;
		p->z=b;
		List t=(List)malloc(sizeof(struct Node));
		p->Next=t;
		p=t;
		p->Next=NULL;
        if(a==0||b==0)break;
	}	
	p=L;
	while(p->z)
	{
		p->x*=p->z;
		p->z--;
		p=p->Next;
	}
	p->x=0;
	p=L;
	while(p->z)
	{
		cout<<p->x<<" "<<p->z<<" ";
		p=p->Next;
	}
	cout<<p->x<<" "<<p->z;
	return 0;
}