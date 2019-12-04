#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
    int testCase;
    scanf("%d", &testCase);
    for(int i=1; i<=testCase; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        if(c%__gcd(a, b)==0)
            printf("Case %d: Yes\n", i);
        else
            printf("Case %d: No\n", i);
    }
    return 0;
}
