#include <bits/stdc++.h>
#define sz 200010
using namespace std;
int main()
{
    int q, n, A[sz], cnt, k, res[sz], x;
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        k=0;
        scanf("%d", &n);
        for(int j=1; j<=n; j++)
            scanf("%d", A+j);
        memset(res, -1, sizeof res);
        for(int j=1; j<=n; j++)
        {
            cnt=1, x=j;
            while(A[x]!=j)
            {
                x=A[x];
                cnt++;
            }
            res[k++]=cnt;
        }
        for(int p=0; p<n; p++)
            printf("%d ", res[p]);
        printf("\n");
    }
    return 0;
}
