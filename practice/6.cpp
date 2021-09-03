#include<bits/stdc++.h>
using namespace std;

typedef struct Node * List;
struct Node{
	int point_1;
	int key;
	int point_2;
	List Next;
};

int main()
{
	int point0,N;
	cin>>point0>>N;
	List L[N];
	List M;
	List Q=(List)malloc(sizeof(struct Node));
	List p,q,r;
	r=Q;
	for(int i=0;i<N;i++)
	{
		L[i]=(List)malloc(sizeof(struct Node));
		cin>>L[i]->point_1>>L[i]->key>>L[i]->point_2;
		L[i]->Next=NULL;
	}
	for(int i=0;i<N;i++)
	{
		if(L[i]->point_1==point0)
		{
			M=L[i];
			p=M;
			break;
		}
	}
	int count=N-1;
	for(int j=0;count||p->point_2!=-1;)
	{
		if(p->point_2==L[j]->point_1)
		{
			p->Next=L[j];
			p=L[j];
			count--;
			j=0;
		}
		else j++;
	}
	q=p=M;
	for(int i=0;q->Next!=NULL;i++)
	{
		for(int j=0;p->Next!=NULL;j++)
		{
			if(abs(q->key)==abs(p->Next->key))
			{
				List tmp=(List)malloc(sizeof(struct Node));
				tmp->point_1=p->point_1;
				tmp->key=p->key;
				tmp->point_2=p->point_2;

				r->Next=tmp;
				r=tmp;
				r->Next=NULL;
				p->point_2=p->Next->point_2;
				p->Next=p->Next->Next;
				continue;	
			}
			else p=p->Next;
		}
		
		q=q->Next;
		p=q;
	}
	while(M)
	{
		printf("%05d %d %05d\n",M->point_1,M->key,M->point_2);
		M=M->Next;
	}
	Q=Q->Next;
	while(Q)
	{
		printf("%05d %d %05d\n",Q->point_1,Q->key,Q->point_2);
		Q=Q->Next;
	}
	
	return 0;
}