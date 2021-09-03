#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
typedef int TElemType;
typedef struct BiNode{
    TElemType data;
    struct BiNode *lchild, *rchild;
}BiNode, *BiTree;
BiTree Build(int *in, int *post, int n){ /// in是中序遍历结果, post是后序遍历结果
    if(n <= 0) return NULL;
    int *p = in;
    while(p){
        if(*p == *(post + n - 1))
            break;
        p++;
    }
    BiTree T = new BiNode;
    T->data = *p;
    int len = p - in;
    T->lchild = Build(in, post, len);
    T->rchild = Build( p + 1, post + len, n - len - 1);
    return T;
}

void PreOrder(BiTree T){
    if(T){
        printf(" %d", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
    return ;
}

int main()
{
    int n;
    int pre[110], in[110];
    BiTree T;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &in[i]); //后序遍历
    }
    for(int i=0; i<n; i++){
        scanf("%d", &pre[i]); //中序遍历
    }
    T = Build(pre, in, n);
    printf("Preorder:");
    PreOrder(T);
    return 0;
}

