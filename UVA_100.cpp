#include<iostream>
#include<cstdio>

int count1(int num)
{
    int cou = 1;
    while(num!=1)
    {
        cou++;
        if(num%2 == 1)
            num = 3*num+1;
        else
            num = num/2;
    }
    return cou;
}

int main()
{
    int num1,num2,n1,n2;
    while(scanf("%d %d",&n1,&n2)==2)
    {
        if(n1>n2)
        {
            num1 = n2;
            num2 = n1;
        }
        else
        {
            num1 = n1;
            num2 = n2;
        }
        int maxnum = 0,ans;
        for(int i=0;i<num2-num1+1;++i)
        {
            ans = count1(i+num1);
            if(ans > maxnum)
            {
                maxnum = ans;
            }
        }
        printf("%d %d %d\n",n1,n2,maxnum);
    }
}
