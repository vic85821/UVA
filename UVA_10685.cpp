#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int range;

typedef struct NODE
{
    int value,parent;
    int Rank;
    string s;
}node;

int Find(node tree[],string s)
{
    int i;
    for(i=1;i<range+1;i++)
    {
        if(tree[i].s == s)
            break;
    }
    return (tree[i].parent == tree[i].value) ? i : tree[i].parent = Find(tree,tree[tree[i].parent].s);
}

void Union(node tree[],string x,string y)
{
    int target = Find(tree,y);
    int subj = Find(tree,x);
    tree[subj].parent = target;
    if(target != subj)
        tree[target].Rank = tree[subj].Rank + tree[target].Rank;
}

bool cmp(node a,node b)
{
    return (a.Rank>=b.Rank);
}

int main()
{
    int num;


    while(scanf("%d %d",&range,&num) == 2 && (range || num))
    {
        node tree[range+1];

        for(int i=1;i<range+1;i++)
        {
            cin>>tree[i].s;
            tree[i].Rank = 1;
            tree[i].value = i;
            tree[i].parent = i;
        }

        string t1,t2;
        int Max=0;

        for(int i=0;i<num;i++)
        {
            cin>>t1>>t2;
            Union(tree,t1,t2);
        }

        if(range>0)
            sort(tree+1,tree+range+1,cmp);


        printf("%d\n",tree[1].Rank);
        return 0;
    }

}
