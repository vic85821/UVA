#include<iostream>
#include<cstdio>

int num_size;
long long int step=0;
way temp[num_size];


void mergelist(long long int list1[],int low,int high)
{
    int ans[num_size],i,j,k = low;
    int mid = (low + high)/2;
    for(i=low,j=mid+1 ; i<=mid || j<=high ; )
    {
        if(i>mid)
        {
            ans[k++] = list1[j++];
        }
        else if(j>high)
        {
            ans[k++] = list1[i++];
        }
        else if(list1[i] > list1[j])
        {
            step += j-k;
            ans[k++] = list1[j++];
        }
        else
        {
            ans[k++] = list1[i++];
        }
    }
    k=low;
    for(int i=low;i<=high;i++) list1[i] = ans[k++];

}

void mergesort(long long int list1[],int low,int high)
{
    if(high>low)
    {
        mergesort(list1,low,(low+high)/2);
        mergesort(list1,(low+high)/2 + 1,high);
        mergelist(list1,low,high);
    }
}

int main()
{
    int num;
    while(scanf("%d",&num) == 1 && num)
    {
        step = 0;
        long long int n[num];
        num_size = num;
        for(int i=0;i<num;i++)
        {
            scanf("%lld",&n[i]);
        }
        mergesort(n,0,num-1);

        printf("%lld\n",step);
    }
}
