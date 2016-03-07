#include<iostream>
#include<cstdio>

using namespace std;

int main()
{

    long long int a,b;

    while(scanf("%lld %lld",&a,&b)==2)
    {
        printf("%lld\n",(b>a)?(b-a):(a-b));
    }
    return 0;
}
