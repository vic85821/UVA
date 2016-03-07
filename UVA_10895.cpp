#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    int row,col;
    while(scanf("%d %d",&row,&col) == 2)
    {
        int matr[row][col];
        int tran[col][row];
        memset(matr,0,sizeof(int)*row*col);

        for(int i=0;i<row;i++)
        {
            int non_zero;
            scanf("%d",&non_zero);
            int position[non_zero];
            for(int j=0;j<non_zero;j++)
            {
                scanf("%d",&position[j]);
            }
            for(int j=0;j<non_zero;j++)
            {
                scanf("%d",&matr[i][position[j]-1]);
            }
        }

        int non_zero_tran[col];
        int position_tran[col],p=0;
        memset(non_zero_tran,0,sizeof(int)*col);
        printf("%d %d\n",col,row);

        for(int j=0;j<col;j++)
        {
            for(int k=0;k<row;k++)
            {
                if(matr[k][j])
                {
                    position_tran[p++] = k+1;
                }
                tran[j][k] = matr[k][j];
            }
            non_zero_tran[j] = p;
            printf("%d",non_zero_tran[j]);

            if(p>0)
            {
                printf(" %d",position_tran[0]);
                for(int k=1;k<p;k++)
                {
                    printf("% d",position_tran[k]);
                }
            }
            puts("");

            if(p>0)
            {
                printf("%d",tran[j][position_tran[0]-1]);
                for(int k=1;k<p;k++)
                {
                    printf(" %d",tran[j][position_tran[k]-1]);
                }
            }
            puts("");
            p=0;
        }
    }
    return 0;
}
