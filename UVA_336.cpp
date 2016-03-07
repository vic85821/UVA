#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

typedef struct{
    int from,to;
    bool check;
}path;

queue<int> que;
int path_num;
map<int,int> city;
map<int,int>::iterator it;

path nw[500];
bool check[500];

void bfs(int temp)
{
    que.push(temp);
    while(!que.empty())
    {
        temp = que.front();
        que.pop();

        for(int i=0;i<path_num;++i)
        {
            if(check[i]==false && (nw[i].from == temp || nw[i].to == temp))
            {
                if(nw[i].from == temp)
                {
                    if(nw[i].to != temp)
                    {
                        city.find(nw[i].to)->second = (city.find(nw[i].to)->second == 0)? city.find(temp)->second+1 :city.find(nw[i].to)->second;
                        que.push(nw[i].to);
                    }
                }
                else if(nw[i].to == temp)
                {
                    city.find(nw[i].from)->second = (city.find(nw[i].from)->second == 0)? city.find(temp)->second+1 :city.find(nw[i].from)->second;
                    que.push(nw[i].from);
                }
                check[i] = true;
            }
        }
    }
}

int main()
{
    int num,Case = 0;
    while(scanf("%d",&num) == 1 && num)
    {
        path_num = num;
        for(int i=0;i<num;++i)
        {
            scanf("%d %d",&nw[i].from,&nw[i].to);

            it = city.begin();
            it = city.find(nw[i].from);
            if(it == city.end())
                city.insert(it,pair<int,int>(nw[i].from,0));

            it = city.begin();
            it = city.find(nw[i].to);
            if(it == city.end())
                city.insert(it,pair<int,int>(nw[i].to,0));

            nw[i].check = false;
        }

        int from,dis,count=0;
        while(scanf("%d %d",&from,&dis))
        {
            if(from ==0 && dis == 0)
                break;
            bfs(from);
            memset(check,false,sizeof(nw));
            for(it=city.begin();it!=city.end();++it)
            {
                if(it->second > dis)
                    count++;
                else if(it->second == 0 && it->first != from)
                    count++;
            }

            for(it=city.begin();it!=city.end();++it)
            {
                it->second = 0;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++Case,count,from,dis);
            count = 0;
        }
        city.clear();
    }
    return 0;
}
