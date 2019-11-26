///It's a solution of problem UVA 10104 (Euclid Problem)
#include <bits/stdc++.h>
using namespace std;
int A, B, X, Y, D;
int ExtendedEuclid(int A, int B, int &X, int &Y)    ///Why we use &X and &Y
{
    int x1, y1;
    if(A==0)
    {
        X=0;
        Y=1;
        return B;
    }
    D=ExtendedEuclid(B%A, A, x1, y1);               ///Simulation of this function required
    X=y1-(B/A)*x1;
    Y=x1;
    return D;
}
int main()
{
    while(scanf("%d%d", &A, &B)==2)
    {
        D=ExtendedEuclid(A, B, X, Y);
        if(A==B)
        {
            X=0;
            Y=1;
        }
        printf("%d %d %d\n", X, Y, D);
    }
    return 0;
}
