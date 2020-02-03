#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int arr[1005], res[1005];
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", arr+i);
    for(int i=1; i<=n; i++)
    {
        memset(res, 0, sizeof res);
        int x=i;
        while(1)
        {
            res[x]++;
            if(res[x]==2)
            {
                printf("%d ", x);
                break;
            }
            x=arr[x];
        }
    }
    return 0;
}
