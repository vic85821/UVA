#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

int matr_row;
int matr_col;
int matr_layer;

int dir[6][3]={{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};

typedef struct{
    int x,y,z;
}position;

queue<position> que;

char c[30][30][35];
bool visit[30][30][35];
long long int step[30][30][35];
position p[30][30][35];

void bfs(int i,int j,int k)
{
    visit[k][i][j] = true;
    step[k][i][j] = 0;
    que.push(p[k][i][j]);

    while(!que.empty())
    {
        position temp = que.front();
        que.pop();
        i = temp.x;
        j = temp.y;
        k = temp.z;

        for(int m=0;m<6;m++)
        {
            if(i+dir[m][2]>=0 && i+dir[m][2]< matr_row && j+dir[m][1]>=0 && j+dir[m][1]<matr_col && k+dir[m][0]>=0 && k+dir[m][0]<matr_layer)
            {
                int x = i+dir[m][2];
                int y = j+dir[m][1];
                int z = k+dir[m][0];

                if(visit[z][x][y] == false)
                {
                    step[z][x][y] = step[k][i][j]+1;
                    visit[z][x][y] = true;
                    que.push(p[z][x][y]);
                }
            }
        }
    }
}
int main()
{
    int num1,num2,num3;
    while(scanf("%d %d %d",&num1,&num2,&num3) == 3)
    {
        if(num1 == 0 && num2 == 0 && num3 == 0)
            return 0;

        memset(c, '.' ,sizeof(c));
        memset(visit , false , sizeof(visit));
        memset(step,0,sizeof(step));
        memset(p,0,sizeof(p));

        matr_row = num2;
        matr_col = num3;
        matr_layer = num1;

        int begin_row=0,begin_col=0,begin_layer=0,end_row=0,end_col=0,end_layer=0;

        for(int l=0;l<num1;++l)
        {
            for(int i=0;i<num2;i++)
            {
                if(i==0)
                    getchar();
                gets(c[l][i]);
                for(int j=0;j<num3;j++)
                {
                    p[l][i][j].x = i;
                    p[l][i][j].y = j;
                    p[l][i][j].z = l;
                    if(c[l][i][j] == 'S')
                    {
                        begin_row = i;
                        begin_col = j;
                        begin_layer = l;
                    }
                    else if(c[l][i][j] == '#')
                    {
                        visit[l][i][j] = true;
                    }
                    else if(c[l][i][j] == 'E')
                    {
                        end_row = i;
                        end_col = j;
                        end_layer = l;
                    }
                }
            }
        }
            bfs(begin_row,begin_col,begin_layer);
            if(step[end_layer][end_row][end_col])
                printf("Escaped in %d minute(s).\n",step[end_layer][end_row][end_col]);
            else
                printf("Trapped!\n");

    }


    return 0;
}
