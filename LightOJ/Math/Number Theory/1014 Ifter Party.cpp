#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>divisor;
int main()
{
    int testCase;
    ll P, L;
    scanf("%d", &testCase);
    for(int i=1; i<=testCase; i++)
    {
        scanf("%lld%lld", &P, &L);
        ll limit=sqrt(P-L);
        printf("Case %d: ", i);
        for(ll j=1; j<=limit; j++)
        {
            if((P-L)%j==0)
            {
                if(j>L)                             divisor.push_back(j);
                if(((P-L)/j)>L && ((P-L)/j)!=j)     divisor.push_back((P-L)/j);
            }
        }
        if(divisor.size()>0)
        {
            if(divisor.size()==1)
                printf("%lld\n", divisor[divisor.size()-1]);
            else
            {
                sort(divisor.begin(), divisor.end());
                for(int j=0; j<divisor.size()-1; j++)
                    printf("%lld ", divisor[j]);
                printf("%lld\n", divisor[divisor.size()-1]);
            }
        }
        else
            printf("impossible\n");
        divisor.clear();
    }
    return 0;
}
