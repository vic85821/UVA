#include<iostream>
#include<cmath>
#include<cstdio>


using namespace std;

int main()
{
    double n,p;
    while(scanf("%lf %lf",&n,&p) == 2)
    {
        printf("%.0f\n",pow(p,1/n));
    }
    return 0;
}
