#include <bits/stdc++.h>
#define sz 1000005
#define ll long long
using namespace std;
ll phi[sz];
void Totient()
{
    for(int i=1; i<=sz; i++)
        phi[i]=i;                           ///Initializing the whole array
    for(int i=2; i<=sz; i++)
    {
        if(phi[i]==i)                       ///If the index is untouched
        {
            phi[i]=i-1;                     ///We encounter with a prime, so phi of a prime is less than ONE of itself
            for(int j=i+i; j<=sz; j+=i)     ///Sieve is in action!!!
                phi[j]=(phi[j]/i)*(i-1);    ///Contributing in every multiple
        }
    }
}
int main()
{
    Totient();
    for(int i=1; i<=10; i++)
        printf("%lld ", phi[i]);
    return 0;
}
