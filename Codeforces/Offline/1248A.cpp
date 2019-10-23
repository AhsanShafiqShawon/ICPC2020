#include <bits/stdc++.h>
#define sz 100005
#define ll long long
using namespace std;
int main()
{
    ll t, n, m, A[sz], B[sz], cntA, cntB;
    scanf("%lld", &t);
    for(ll i=1; i<=t; i++)
    {
        cntA=0, cntB=0;
        scanf("%lld", &n);
        for(ll j=0; j<n; j++)
        {
            scanf("%lld", A+j);
            if(A[j]&1)
                cntA++;
        }
        scanf("%lld", &m);
        for(int j=0; j<m; j++)
        {
            scanf("%lld", B+j);
            if(B[j]&1)
                cntB++;
        }
        printf("%lld\n",cntA*cntB+(cntA-n)*(cntB-m));
    }
    return 0;
}
