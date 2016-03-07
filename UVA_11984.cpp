#include<iostream>
#include<cstdio>
 using namespace std;

 int main()
 {
    int num;
    while(scanf("%d",&num) == 1)
    {
        for(int i=0;i<num;++i)
        {
            float C,F;
            scanf("%f %f",&C,&F);
            float ans = 0;
            ans = ((C*9/5)+F )* 5 / 9;

            printf("Case %d: %.2f\n",i+1,ans);
        }
    }
 }
