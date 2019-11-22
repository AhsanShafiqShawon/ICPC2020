#include <bits/stdc++.h>
#define ll long long
#define mod 100000007
using namespace std;
ll dp[51][1005];
int coin[51];
int coinCount[51];
int n, make;
ll CoinChange(int i, int amount)
{
    if(i>=n)
    {
        if(amount==0)           return 1;
        else                    return 0;
    }
    if(amount<0)                return 0;
    if(dp[i][amount]!=-1)       return dp[i][amount];
    ll ret=0;
    //if(amount-coin[i]>=0)       ret1=CoinChange(i, amount-coin[i]);
    //ret2=CoinChange(i+1, amount);
    for(int k=0; k<=coinCount[i]; k++)
        ret=(ret+CoinChange(i+1, amount-coin[i]*k))%mod;
    return dp[i][amount]=ret;
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d%d", &n, &make);
        memset(dp, -1, sizeof dp);
        for(int j=0; j<n; j++)
            scanf("%d", coin+j);
        for(int j=0; j<n; j++)
            scanf("%d", coinCount+j);
        printf("Case %d: %lld\n", i, CoinChange(0, make));
    }
    return 0;
}
