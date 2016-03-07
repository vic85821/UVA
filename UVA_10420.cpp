#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef struct
{
    char name[80];
    long long int number;
	int index;
}country;

bool cmp(country a,country b)
{
    for(int i=0;i<75;++i)
    {
        if(a.name[i] != b.name[i])
            return a.name[i]<b.name[i];
    }
}

int main()
{
    int num;
    while(scanf("%d",&num) == 1)
    {
        getchar();
        country c[2100];
        int total = 0;
        char temp[80];
        char *country;
        bool check = false;
        for(int i=0;i<num;++i)
        {
            fgets(temp,76,stdin);
            country = strtok(temp," ");
            if(total)
            {
                for(int j=0;j<total;++j)
                {
                    if(!strcmp(c[j].name,country))
                    {
                        c[j].number++;
                        check = true;
                        break;
                    }
                }
                if(!check)
                {
                    strcpy(c[total].name , country);
                    c[total].index = total;
                    c[total].number=1;
                    total++;
                    check = false;
                }
            }
            else
            {
                strcpy(c[total].name , country);
                c[total].index = total;
                c[total].number=1;
                total++;
            }

        }
        sort(c,c+total,cmp);

        for(int i=0;i<total;++i)
        {
            printf("%s %lld\n",c[i].name,c[i].number);
        }
    }

    return 0;
}
