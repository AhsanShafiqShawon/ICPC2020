#include <bits/stdc++.h>
#define ll unsigned long long
#define sz 5000005
using namespace std;
ll value[sz], sum;
void Phi()
{
    for(int i=1; i<=sz; i++)
        value[i]=i;
    for(int p=2; p<=sz; p++)
    {
        if(value[p]==p)
        {
            value[p]=p-1;
            for(int i=2*p; i<=sz; i+=p)
                value[i]=(value[i]/p)*(p-1);
        }
    }
}
int main()
{
    Phi();
    int tc;
    ll a, b;
    sum=0;
    for(int i=2; i<=sz; i++)
    {
        sum=sum+value[i]*value[i];
        value[i]=sum;
    }
    scanf("%d", &tc);
    for(int s=1; s<=tc; s++)
    {
        scanf("%llu%llu", &a, &b);
        if(a==2)
            printf("Case %d: %llu\n", s, value[b]);
        else
            printf("Case %d: %llu\n", s, value[b]-value[a-1]);
    }
    return 0;
}
