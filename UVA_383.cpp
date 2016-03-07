#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>

using namespace std;

map<string,int> waresHouse;
map<string,int>::iterator it;

int shipNumber,routePair,costNumber;

typedef struct{
    int from,to;
}route;


int main()
{
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;++i)
    {
        scanf("%d %d %d",&shipNumber,&routePair,&costNumber);

        for(int j=0;j<shipNumber;++j)
        {
            char temp[3];
            memset(temp,0,sizeof(temp));
            scanf("%s",&temp);
            it = waresHouse.begin();
            waresHouse.insert(it,pair<string,int>(temp,j));
        }

        for(int j=0;j<routePair;++j)
        {
            char temp1[3],temp2[3];
            int index1=0,index2=0;

            memset(temp1,0,sizeof(temp1));
            memset(temp2,0,sizeof(temp2));
            scanf("%s %s",&temp1,&temp2);

            index1 = waresHouse[temp1];
            index2 = waresHouse[temp2];
            printf("%d %d\n",index1,index2);
        }
    }

    return 0;
}
