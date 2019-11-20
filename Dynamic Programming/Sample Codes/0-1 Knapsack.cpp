#include <bits/stdc++.h>
#define sz 1005
using namespace std;
int dp[sz][sz], weight[sz], price[sz];
int n, capacity;
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
        scanf("%d%d", &n, &capacity);
        for(int j=0; j<n; j++)
            scanf("%d%d", price+j, weight+j);
        printf("%d\n", sack(capacity, weight, price, n));
    return 0;
}
