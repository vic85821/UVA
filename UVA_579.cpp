#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

int main()
{
    char c[10];
    while(fgets(c,sizeof(c),stdin))
    {
        char* hour = strtok(c,":");
        char* minute = strtok(NULL,":");
        int h = atoi(hour);
        int m = atoi(minute);
        if(h == 0 && m == 0)
            return 0;
        float min_degree = (float)m * 6;
        float hour_degree = (float)h * 30 + m * 0.5;

        float ans = 0;
        if(min_degree > hour_degree)
            ans = min_degree - hour_degree;
        else
            ans = hour_degree - min_degree;

        if(ans>180)
            printf("%.3f\n",(float)360-ans);
        else
            printf("%.3f\n",ans);
    }
    return 0;
}
