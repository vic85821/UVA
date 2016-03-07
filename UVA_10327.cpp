#include<iostream>
#include<cstdio>

int main()
{
    int num;
    while(scanf("%d",&num) == 1)
    {
        int n[num],temp,step=0;
        for(int i=0;i<num;i++)
        {
            scanf("%d",&n[i]);
        }

        for(int i=num-1;i>0;i--)
        {
            for(int j=0;j<i;j++)
            {
                if(n[j+1]<n[j])
                {
                    temp = n[j+1];
                    n[j+1] = n[j];
                    n[j] = temp;
                    step++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",step);
    }
}
