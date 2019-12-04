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
    ll x, y, n;
    while(scanf("%lld%lld%lld", &x, &y, &n)==3)
        printf("%lld\n", modex(x, y, n));
    return 0;
}
