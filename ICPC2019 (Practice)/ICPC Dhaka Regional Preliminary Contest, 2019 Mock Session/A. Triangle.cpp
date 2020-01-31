#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a!=b && b!=c && a!=c)
        printf("Bad Triangle\n");
    else if(a==b && b==c)
        printf("Equilateral Triangle\n");
    else
        printf("Isosceles Triangle\n");
    return 0;
}
