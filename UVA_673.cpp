#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>

using namespace std;
int main()
{
    int num;
    while(scanf("%d",&num)==1)
    {
        getchar();
        for(int i=0;i<num;++i)
        {
            stack<char> s;
            char c[200];
            gets(c);
            int len = strlen(c);
            if(len == 0)
            {
                printf("Yes\n");
                continue;
            }
            char top;
            int correct = 0;
            for(int j=0;j<len;++j)
            {
                if(c[j] == '(' || c[j] == '[')
                {
                    s.push(c[j]);
                }
                else if(c[j] == ')')
                {
                    if(s.empty())
                    {
                        correct = 1;
                        break;
                    }
                    if(s.top() != '(')
                    {
                        correct = 1;
                        break;
                    }
                    else
                        s.pop();
                }
                else if(c[j] == ']')
                {
                    if(s.empty())
                    {
                        correct = 1;
                        break;
                    }
                    if(s.top() != '[')
                    {
                        correct = 1;
                        break;
                    }
                    else
                        s.pop();
                }
            }
            if(correct == 1)
                printf("No\n");
            else if(s.empty())
                printf("Yes\n");
            else
                printf("No\n");
            correct = 0;
        }
    }
    return 0;
}
