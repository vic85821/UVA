#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

int dir[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
int matr_size;

int image[30][30];
bool visit[30][30];

void dfs(int i,int j)
{
    for(int k=0;k<8;k++)
    {
        if(i+dir[k][1]>=0 && i+dir[k][1]< matr_size && j+dir[k][0]>=0 && j+dir[k][0]<matr_size)
        {
            if(image[i+dir[k][1]][j+dir[k][0]] == 1 && visit[i+dir[k][1]][j+dir[k][0]] == false)
            {
                visit[i+dir[k][1]][j+dir[k][0]] = true;
                dfs(i+dir[k][1],j+dir[k][0]);
            }
        }
    }
}

int main()
{
    int num,number = 0;
    while(scanf("%d",&num)== 1)
    {
        memset(image, 0, sizeof(int)*num*num );
        memset(visit, false, sizeof(int)*num*num );
        matr_size = num;
        number++ ;
        getchar();
        int total = 0;

        for(int i=0;i<num;++i)
        {
            char c[30];
            fgets(c,30,stdin);
            for(int j=0;j<num;j++)
            {
                image[i][j] = c[j] - '0';
            }
        }
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
            {
                if(image[i][j] == 1 && visit[i][j] == false)
                {
                    dfs(i,j);
                    total++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",number,total);
        total =0;


    }

    return 0;
}
