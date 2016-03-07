#include<cstdio>
#include<iostream>

int main()
{
    int num = 0;
    while(scanf("%d",&num)==1)
    {
        int co = num;
        while(co--)
        {
            int n[3],temp;
            scanf("%d %d %d",&n[0],&n[1],&n[2]);
            for(int i=2; i>0 ; i--)
            {
                for(int j =0; j<i;j++)
                {
                    if(n[j]>n[j+1])
                    {
                        temp = n[j];
                        n[j] = n[j+1];
                        n[j+1] = temp;
                    }
                }

            }
            printf("Case %d: %d\n",num-co,n[1]);
        }
    }
    return 0;
}
