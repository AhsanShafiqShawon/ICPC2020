#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
void multiply(ll A[2][2], ll Copy[2][2])
{
    ll x = ((A[0][0]*Copy[0][0])%mod + (A[0][1]*Copy[1][0])%mod)%mod;
    ll y = ((A[0][0]*Copy[0][1])%mod + (A[0][1]*Copy[1][1])%mod)%mod;
    ll w = ((A[1][0]*Copy[0][0])%mod + (A[1][1]*Copy[1][0])%mod)%mod;
    ll z = ((A[1][0]*Copy[0][1])%mod + (A[1][1]*Copy[1][1])%mod)%mod;
    A[0][0]=x;
    A[0][1]=y;
    A[1][0]=w;
    A[1][1]=z;
}
void power(ll A[2][2], int n)       ///What is n?
{
    if(n==0 || n==1)
        return;
    ll Copy[2][2]={{1, 1}, {1, 0}};
    power(A, n/2);
    multiply(A, A);
    if(n%2!=0)
        multiply(A, Copy);
}
ll fib(int n)
{
    ll A[2][2]={{1, 1}, {1, 0}};
    if(n==0)
        return 0;
    power(A, n-1);          ///Why n-1
    return A[0][0]%mod;
}
using namespace std;

int main()
{
    ll n;
    while(cin>>n)
        printf("%lld\n", fib(n));
    return 0;
}
