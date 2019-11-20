#include <bits/stdc++.h>
using namespace std;
int make;
int dp[6][7500], arr[7500];
int coin[]={1, 5, 10, 25, 50};
int CoinChange(int i, int amount)
{
    if(i>=5)
    {
        if(amount==make)        return 1;
        else                    return 0;
    }
    if(dp[i][amount]!=-1)       return dp[i][amount];
    int ret1=0, ret2=0;
    if(amount+coin[i]<=make)    ret1=CoinChange(i, amount+coin[i]);
    ret2=CoinChange(i+1, amount);
    return dp[i][amount]=ret1+ret2;
}
int main()
{

    for(int i=0; i<=7490; i++)
    {
        memset(dp, -1, sizeof dp);
        make=i;
        arr[i]=CoinChange(0, 0);
    }
    while(cin>>make)
        printf("%d\n", arr[make]);
    return 0;
}
