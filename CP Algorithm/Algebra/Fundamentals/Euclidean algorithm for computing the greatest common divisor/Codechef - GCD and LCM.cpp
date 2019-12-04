#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t, a, b;
    scanf("%lld", &t);
    for(ll i=0; i<t; i++)
    {
        scanf("%lld%lld", &a, &b);
        printf("%lld %lld\n", __gcd(a, b), (a/__gcd(a, b))*b);
    }
    return 0;
}
