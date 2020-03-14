///No binary search, just the formula sin(theta/2)=r/R-r, where theta=360/n

#include <bits/stdc++.h>
#define pi acos(-1)
using namespace std;
int main()
{
    int testCase;
    double R, n;
    scanf("%d", &testCase);
    for(int i=1; i<=testCase; i++)
    {
        cin>>R>>n;
        double theta=(360/n)*(pi/180.0);
        cout << setprecision(10);
        cout << "Case " << i << ": " << (R*sin(theta/2.0))/(1+sin(theta/2.0)) << endl;
    }
    return 0;
}
