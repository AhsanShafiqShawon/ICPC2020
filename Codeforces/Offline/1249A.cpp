#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q, n, A[105], cnt;
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        cnt=0;
        scanf("%d", &n);
        for(int j=0; j<n; j++)
            scanf("%d", A+j);
        sort(A, A+n);
        for(int j=0; j<n-1; j++)
        {
            if((A[j+1]-A[j])==1)
                cnt++;
        }
        if(cnt==0)
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}
