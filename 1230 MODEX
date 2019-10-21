#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll modex(ll x, ll y, ll n)
{
    x%=n;
    ll res=1;
    while(y>0)
    {
        if(y&1)
            res=res*x%n;
        x=x*x%n;
        y>>=1;
    }
    return res;
}
int main()
{
    ll c, x, y, n;
    scanf("%lld", &c);
    for(ll i=1; i<=c; i++)
    {
        scanf("%lld%lld%lld", &x, &y, &n);
        printf("%lld\n", modex(x, y, n));
    }
    return 0;
}
