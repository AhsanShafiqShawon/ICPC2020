#include <bits/stdc++.h>
#define sz 100005
using namespace std;
int dp[sz];
int fib(int n)
{
    if(n==0)        return 0;
    if(n==1)        return 1;
    if(dp[n]!=-1)   return dp[n];
    else
    {
        dp[n]=fib(n-1)+fib(n-2);
        return dp[n];
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    memset(dp, -1, sizeof dp);
    printf("%d\n", fib(n));
    return 0;
}
