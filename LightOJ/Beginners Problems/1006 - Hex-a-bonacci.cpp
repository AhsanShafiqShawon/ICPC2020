#include <bits/stdc++.h>
#define sz 10005
#define mod 10000007
using namespace std;
int dp[sz];
int a, b, c, d, e, f;
int fn( int n )
{
    if( n == 0 )
    {
        if(dp[n]!=-1)
            return dp[n];
        else
        {
            dp[n]=a%mod;
            return dp[n];
        }
    }
    if( n == 1 )
    {
        if(dp[n]!=-1)
            return dp[n];
        else
        {
            dp[n]=b%mod;
            return dp[n];
        }
    }
    if( n == 2 )
    {
        if(dp[n]!=-1)
            return dp[n];
        else
        {
            dp[n]=c%mod;
            return dp[n];
        }
    }
    if( n == 3 )
    {
        if(dp[n]!=-1)
            return dp[n];
        else
        {
            dp[n]=d%mod;
            return dp[n];
        }
    }
    if( n == 4 )
    {
        if(dp[n]!=-1)
            return dp[n];
        else
        {
            dp[n]=e%mod;
            return dp[n];
        }
    }
    if( n == 5 )
    {
        if(dp[n]!=-1)
            return dp[n];
        else
        {
            dp[n]=f%mod;
            return dp[n];
        }
    }
    if(dp[n]!=-1)   return dp[n]%mod;
    else
    {
        dp[n] = fn(n-1)%mod + fn(n-2)%mod + fn(n-3)%mod + fn(n-4)%mod + fn(n-5)%mod + fn(n-6)%mod;
        return dp[n]%mod;
    }
}
int main()
{
    int n, caseno=0, cases;
    scanf("%d", &cases);
    while(cases--)
    {
        memset(dp, -1, sizeof dp);
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) % mod);
    }
    return 0;
}
