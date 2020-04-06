#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
#define MOD 1000000007
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define base 31

int findLPS(string &s)
{
    int n = s.size();
    ll hF = 0;
    ll hR = 0;
    ll po = 1;
    int lps = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        hF = ((hF * base) + (s[i] - 'a')) % MOD;
        hR = (((s[i] - 'a') * po) + hR) % MOD;
        po = (po * base) % MOD;
        if(hR == hF) lps = max(lps, n - i);
    }
    return lps;
}

int main()
{
    string s;
    cin >> s;
    cout << findLPS(s) << "\n";
    return 0;
}
