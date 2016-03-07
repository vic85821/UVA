#include<stdio.h>
#include<algorithm>

using namespace std;

typedef struct
{
    int time,fine,order;
    float Ratio;
}people;

bool cmp(people a,people b)
{
    return a.Ratio > b.Ratio;
}

int main()
{
    int num;
    while(scanf("%d",&num) == 1)
    {
        for(int j=0;j<num;++j)
        {
            int number;
            scanf("%d",&number);
            people List[number];
            for(int i=0;i<number;++i)
            {
                scanf("%d %d",&List[i].time,&List[i].fine);
                List[i].Ratio = (float)List[i].fine / (float)List[i].time;
                List[i].order = i+1;
            }
            sort(List,List+number,cmp);
            for(int i=0;i<number;++i)
            {
                printf("%d",List[i].order);
                if(i!=number-1)
                    printf(" ");
            }
            printf("\n");
            if(j!=num-1)
                printf("\n");
        }
    }
}
