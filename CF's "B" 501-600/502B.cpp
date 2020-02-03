#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, zero=0, one=0, zz=0, oz=0;
    scanf("%lld", &n);
    string a, b;
    cin>>a>>b;
    for(int i=0; i<n; i++)
    {
        if(a[i]=='0')                   zero++;
        if(a[i]=='1')                   one++;
        if(a[i]=='0' && b[i]=='0')      zz++;
        if(a[i]=='1' && b[i]=='0')      oz++;
    }
    printf("%lld\n", zero*oz+one*zz-zz*oz);
    return 0;
}
