#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int add(char a[],char b[])
{
    int c[12],temp,Count = 0;
    for(int i=0;i<12;++i)
    {
        c[i] = a[i] + b[i];
        if(c[i] != 0)
            c[i] = c[i] - 96;
    }

    for(int i=0;i<11;++i)
    {
        printf("%d\n",c[i]);
        temp = c[i]/10;
        if(temp)
        {
            Count++;
            c[i+1] += temp;
        }
        c[i] = c[i]%10;
    }
    return Count;
}


int main()
{
    freopen("123.txt","w",stdout);
    char *a,*b,a_invers[12],b_invers[12],temp;

    memset(a_invers,0,sizeof(a_invers));
    memset(b_invers,0,sizeof(b_invers));

    while(scanf("%s %s",&a,&b) == 2)
    {
        if(a[0] == '0' && b[0] == '0')
            break;

        for(int i=0;i<12;++i)
        {
            a_invers[i] = a[strlen(a)-1-i];
        }

        for(int i=0;i<12;++i)
        {
            b_invers[i] = b[strlen(b)-1-i];
        }

        int number = add(a,b);
        if(number > 1)
            printf("%d carry operations.\n",number);
        else if(!number)
            printf("No carry operation.\n");
        else
            printf("1 carry operation.\n");

        memset(a_invers,0,sizeof(a_invers));
        memset(b_invers,0,sizeof(b_invers));
    }
    return 0;


}
