#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    long long a,b,c,d;
    double distance;

    while(scanf("%lld %lld",&a,&b) == 2)
    {
        scanf("%lf",&distance);

        long double Ratio1 = (long double)a/b;
        long double Ratio2;

        for(d=1;;d++)
        {
            c = (long long)(Ratio1*d);

            while(a*d >= c*b)
                c++;

            Ratio2 = (long double)c/d;

            if( Ratio2 - Ratio1 <= distance)
            {
                printf("%lld %lld\n",c,d);
                break;
            }
        }


    }
    return 0;
}
