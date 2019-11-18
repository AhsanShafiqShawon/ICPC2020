#include <bits/stdc++.h>
#define sz 1005
using namespace std;
int dp[sz][sz];
int nCr(int n, int r)
{
    if(r==1)            return n;
    if(n==r)            return 1;
    if(dp[n][r]!=-1)    return dp[n][r];
    else
    {
        dp[n][r]=nCr(n-1, r)+nCr(n-1, r-1);
        return dp[n][r];
    }
}
int main()
{
    int n, r;
    scanf("%d%d", &n, &r);
    memset(dp, -1, sizeof dp);
    printf("%d\n", nCr(n, r));
    return 0;
}
