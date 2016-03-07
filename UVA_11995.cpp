#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>

using namespace std;
int main()
{
    int num;
    while(scanf("%d",&num) == 1)
    {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pri_q;
        bool isStack = true;
        bool isQueue = true;
        bool isPriority_queue = true;
        for(int i=0;i<num;i++)
        {
            int mode,value;
            scanf("%d",&mode);
            scanf("%d",&value);
            if(mode == 1)
            {
                s.push(value);
                q.push(value);
                pri_q.push(value);
            }
            else if(mode == 2)
            {
                if(!s.empty() && isStack)
                {
                    if(s.top() != value)
                        isStack = false;
                    else
                        s.pop();
                }
                else
                    isStack = false;

                if(!q.empty() && isQueue)
                {
                    if(q.front() !=value )
                        isQueue = false;
                    else
                        q.pop();
                }
                else
                    isQueue = false;

                if(!pri_q.empty() && isPriority_queue)
                {
                    if(pri_q.top() !=value )
                        isPriority_queue = false;
                    else
                        pri_q.pop();
                }
                else
                    isPriority_queue = false;
            }
        }

        if(isStack)
        {
            if(isQueue || isPriority_queue)
                printf("not sure\n");
            else
                printf("stack\n");
        }
        else if(isQueue)
        {
            if(isPriority_queue)
                printf("not sure\n");
            else
                printf("queue\n");
        }
        else if(isPriority_queue)
        {
            printf("priority queue\n");
        }
        else
            printf("impossible\n");
    }
    return 0;
}
