#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
    int input,total = 0;
    int List[20000];
    while(scanf("%d",&List[total]) == 1)
    {
        total++;
        sort(List,List+total);
        if(total%2)
        {
            printf("%d\n",List[total/2]);
        }
        else
        {
            printf("%d\n",(List[total/2]+List[(total/2) - 1])/2);
        }

    }

    return 0;
}
