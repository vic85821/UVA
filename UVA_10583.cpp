#include<iostream>
#include<cstdio>

using namespace std;

typedef struct NODE
{
    int value,parent;
}node;

int Find(node tree[],int p)
{
    return (tree[p].parent == tree[p].value) ? p : tree[p].parent = Find(tree,tree[p].parent);
}


void Union(node tree[],int x,int y)
{
    tree[Find(tree,x)].parent = Find(tree,y);
}

int main()
{
    int range,num,time = 1;
    while(scanf("%d %d",&range,&num) == 2 && (range && num))
    {
        node tree[range];

        for(int i=1;i<range+1;i++)
        {
            tree[i].value = i;
            tree[i].parent = i;
        }

        int t1,t2,Count=0;

        for(int i=0;i<num;i++)
        {
            scanf("%d %d",&t1,&t2);
            Union(tree,t1,t2);
        }

        for(int i=1;i<range+1;i++)
        {
            if(tree[i].parent == tree[i].value)
                Count++;
        }

        printf("Case %d: %d\n",time++,Count);
    }

}
