#include <bits/stdc++.h>
#define sz 100005
#define ll long long
using namespace std;
int main()
{
    ll n, A[sz], sumA=0, sumB=0;
    scanf("%lld", &n);
    for(ll i=0; i<n; i++)
        scanf("%lld", A+i);
    sort(A, A+n);
    for(int j=0; j<n/2; j++)
        sumA=sumA+A[j];
    for(int j=n/2; j<n; j++)
        sumB=sumB+A[j];
    printf("%lld\n", sumA*sumA+sumB*sumB);
    return 0;
}
