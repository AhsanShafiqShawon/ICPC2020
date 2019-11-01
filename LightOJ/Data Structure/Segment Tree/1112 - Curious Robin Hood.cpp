#include <bits/stdc++.h>
#define sz 100005
using namespace std;
int arr[sz];
int tree[3*sz];
int x;
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left, b, mid);
    init(Right, mid+1, e);
    tree[node]=tree[Left]+tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if(x==1 && b >= i && e <= i)
    {
        tree[node]=0;
        return;
    }
    if (x==2 && b >= i && e <= i) {
        tree[node] = tree[node]+newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
int main()
{
    int t, n, q, L, R, value;
    scanf("%d", &t);
    for(int i=1; i<=t; i++)
    {
        printf("Case %d:\n", i);
        scanf("%d%d", &n, &q);
        for(int j=1; j<=n; j++)
            scanf("%d", arr+j);
        init(1, 1, n);
        for(int j=0; j<q; j++)
        {
            scanf("%d", &x);
            if(x==1)
            {
                scanf("%d", &L);
                printf("%d\n", query(1, 1, n, L+1, L+1));
                update(1, 1, n, L+1, 0);
            }
            else if(x==2)
            {
                scanf("%d%d", &L, &value);
                update(1, 1, n, L+1, value);
            }
            else
            {
                scanf("%d%d", &L, &R);
                printf("%d\n", query(1, 1, n, L+1, R+1));
            }
        }
    }
    return 0;
}
