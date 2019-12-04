#include <bits/stdc++.h>
#define sz 99999999
#define ll long long
using namespace std;
bool isPrime[sz];
vector<ll>vc;
bitset<sz>bs;
void Sieve(ll n)
{
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2; i<sz; i++)
    {
        if(bs[i])
        {
            for(ll j=i*i; j<sz; j+=i)
                bs[j]=0;
        vc.push_back(i);
        }
    }
    for(int i=0; i<vc.size(); i+=100)
        printf("%lld\n", vc[i]);
}
int main()
{
    Sieve(sz);
    return 0;
}
