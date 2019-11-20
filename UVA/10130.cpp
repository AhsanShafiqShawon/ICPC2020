#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
vector<int>vc;
int sack(int x, int weight[], int price[], int n)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=x; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(weight[i-1]<=j)
                dp[i][j]=max(price[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][x];
}

int main()
{
    int t, n, weight[1005], price[1005], g, x, sum;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        //memset(dp, 0, sizeof dp);
        sum=0;
        scanf("%d", &n);
        for(int j=0; j<n; j++)
            scanf("%d%d", price+j, weight+j);
        scanf("%d", &g);
        for(int j=0; j<g; j++)
        {
            scanf("%d", &x);
            vc.push_back(sack(x, weight, price, n));
        }
        for(int j=0; j<vc.size(); j++)
            sum+=vc[j];
        printf("%d\n", sum);
        vc.clear();
    }
    return 0;
}
