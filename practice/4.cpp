#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

Position Find( List L, ElementType X )
{
	Position p;
	p=L;
	if(!p)return ERROR;
    if(p->Data==X)
    {
        return L;
    }
	while(p)
	{
		if(p->Data==X)return p;
		p=p->Next;
	}
	if(!p)return ERROR;
	
}
List Insert( List L, ElementType X, Position P )
{
	List p,q,head;
	head=L;
    p=head;
	q=(Position)malloc(sizeof(struct LNode));
    q->Data=X;
    q->Next=NULL;
	if(L==P)//首部插入
	{
		if(!L)
		{
			head=q;
			return head;
		}
		else
		{
			q->Next=head;
			head=q;
			return head;
		}		
	}
    if(!P)//尾部插入
    {
        while (p->Next)p=p->Next;
    	p->Next=q;
    	return head;
	}
    while(p->Next)//中间插入
    {
        if(p->Next->Data==P->Data)
        {
            q->Next=p->Next;
            p->Next=q;
            return head;
        }
        p=p->Next;
    }
    
    printf("Wrong Position for Insertion\n");
    return ERROR;
	
}
List Delete( List L, Position P )
{
	List q,head;
	head=L;
    if(P==L)
    {
        head=head->Next;
        return head;
    }
    q=L;
    while (q)
    {
        if(q->Next==P)
        {
            q->Next=q->Next->Next;
            return head;
        }
        q=q->Next;
    }
	printf("Wrong Position for Deletion\n");
    return ERROR;
}