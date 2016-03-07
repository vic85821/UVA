#include<iostream>
#include<cstring>
#include<cstdio>

int calculateLove(char *s)
{
    int len = strlen(s);
    int ans = 0;
    for(int i=0;i<len;++i)
    {
        if(s[i]<='z' && s[i]>='a')
            ans += s[i]-'a'+1;
        if(s[i]<='Z' && s[i]>='A')
            ans += s[i]-'A'+1;
    }

    int ans2 = 0;
    do{
        while(ans>9)
        {
            ans2 += ans%10;
            ans/=10;
        }
        ans2 += ans;
        if(ans2 > 9)
        {
            ans = ans2;
            ans2 = 0;
        }
        else
            return ans2;
    }while(1);
}

int main()
{
    char s1[30],s2[30];
    while(fgets(s1,sizeof(s1),stdin)!=0)
    {
        fgets(s2,sizeof(s2),stdin);

        int s1_ans = calculateLove(s1);
        int s2_ans = calculateLove(s2);
        if(s1_ans > s2_ans)
        {
            printf("%.2f %%\n",(float)s2_ans/s1_ans*100);
        }
        else
        {
            printf("%.2f %%\n",(float)s1_ans/s2_ans*100);
        }
    }
    return 0;
}
