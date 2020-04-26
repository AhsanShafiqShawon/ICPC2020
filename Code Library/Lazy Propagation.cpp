#include <bits/stdc++.h>
#define sz 100005
#define ll long long
using namespace std;
ll arr[sz];
ll tree[3*sz];
ll Lazy[3*sz];
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int Left=2*node;
    int Right=2*node+1;
    int mid=(b+e)/2;
    init(Left, b, mid);
    init(Right, mid+1, e);
    tree[node]=tree[Left]+tree[Right];
}

void update(int node, int b, int e, int i, int j, int x)
{
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    if(Lazy[node])
    {
        tree[node]+=Lazy[node]*(e-b+1);
        if(b!=e)
        {
            Lazy[Left]+=Lazy[node];
            Lazy[Right]+=Lazy[node];
        }
        Lazy[node]=0;
    }
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node]+=((e-b+1)*x);
        if(b!=e)
        {
            Lazy[Left]+=x;
            Lazy[Right]+=x;
        }
        return;
    }

    update(Left, b, mid, i, j, x);
    update(Right, mid+1, e, i, j, x);
    tree[node]=tree[Left]+tree[Right];
}
ll query(int node, int b, int e, int i, int j)
{
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    if(i>e || j<b)
        return 0;
    if(Lazy[node])
    {
        tree[node]+=Lazy[node]*(e-b+1);
        if(b!=e)
        {
            Lazy[Left]+=Lazy[node];
            Lazy[Right]+=Lazy[node];
        }
        Lazy[node]=0;
    }
    if(b>=i && e<=j)
        return tree[node];

    ll p1=query(Left, b, mid, i, j);
    ll p2=query(Right, mid+1, e, i, j);
    return p1+p2;
}
int main()
{
    int testCase;
    int n, q;
    int token, x, y, v;
    scanf("%d", &testCase);
    for(int cs=1; cs<=testCase; cs++)
    {
        scanf("%d%d", &n, &q);
        printf("Case %d:\n", cs);
        memset(arr, 0, sizeof arr);
        memset(tree, 0, sizeof tree);
        memset(Lazy, 0, sizeof Lazy);
        for(int i=0; i<q; i++)
        {
            scanf("%d", &token);
            if(token==0)
            {
                scanf("%d%d%d", &x, &y, &v);
                update(1, 0, n-1, x, y, v);
            }
            else
            {
                scanf("%d%d", &x, &y);
                ll ans=query(1, 0, n-1, x, y);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
