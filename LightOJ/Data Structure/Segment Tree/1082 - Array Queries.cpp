#include <bits/stdc++.h>
using namespace std;
#define mx 100001
int arr[mx];
int tree[mx * 3];
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    //printf("%d %d\n", tree[Left], tree[Right]);
    //printf("%d\n", min(tree[Left], tree[Right]));
    tree[node] = min(tree[Left], tree[Right]);
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 200000;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    //printf("%d %d\n", p1, p2);
    return min(p1, p2);
}
int main()
{
    int t, n, q, l, r;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        //memset(tree, mx, sizeof tree);
        scanf("%d%d", &n, &q);
        for(int j=1; j<=n; j++)
            scanf("%d", arr+j);
        init(1, 1, n);
        printf("Case %d:\n", i);
        for(int k=0; k<q; k++)
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}
