#include <bits/stdc++.h>
#define sz 1000000
using namespace std;
bool isPrime[sz+5];
vector<int>prime;
void sieve()
{
    isPrime[1]=1;
    for(int i=2; i*i<=sz; i++)
    {
        for(int j=i+i; j<=sz; j+=i)
        {
            if(isPrime[j]==0)
                isPrime[j]=1;
        }
    }
    for(int i=1; i<=sz; i++)
    {
        if(isPrime[i]==0)
            prime.push_back(i);
    }
}
int main()
{
    sieve();
    for(int i=0; i<prime.size(); i++)
        printf("%d ", prime[i]);
    return 0;
}
