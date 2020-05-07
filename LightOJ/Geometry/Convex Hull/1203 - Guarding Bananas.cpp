#include <bits/stdc++.h>
#define pi acos(-1)
#define ll long long
using namespace std;
int n;
struct pt
{
    ll x, y;
};
bool cmp(pt a, pt b)
{
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
bool cw(pt a, pt b, pt c)
{
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)<0;
}
bool ccw(pt a, pt b, pt c)
{
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)>0;
}
bool num_equal(pt a, pt b)
{
    return (a.x==b.x) && (a.y==b.y);
}
void convex_hull(vector<pt>&a)
{
    if(a.size()==1)     return;
    sort(a.begin(), a.end(), &cmp);
    a.erase(unique(a.begin(), a.end(), num_equal), a.end());
    pt p1=a[0], p2=a.back();
    vector<pt>up, down;
    up.push_back(p1);
    down.push_back(p1);
    for(int i=1; i<(int)a.size(); i++)
    {
        if(i==a.size()-1 || cw(p1, a[i], p2))
        {
            while(up.size()>=2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if(i==a.size()-1 || ccw(p1, a[i], p2))
        {
            while(down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for(int i=0; i<(int)up.size(); i++)
        a.push_back(up[i]);
    for(int i=down.size()-2; i>0; i--)
        a.push_back(down[i]);
}
ll dist(pt a, pt b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
double res(pt a, pt b, pt c)
{
    long double ab = dist(a, b);
    long double bc = dist(b, c);
    long double ac = dist(a, c);
    long double angle=(ab+bc-ac)/(2.0*sqrtl(ab)*sqrtl(bc));
    return acos(angle);
}
vector<pt>a;

int main()
{
    int testCase;
    scanf("%d", &testCase);
    for(int cs=1; cs<=testCase; cs++)
    {
        scanf("%d", &n);
        a.resize(n);
        double mn=400.0;
        for(int i=0; i<n; i++)
            scanf("%lld%lld", &a[i].x, &a[i].y);
        convex_hull(a);
        int sz=a.size();
        for(int i=0; i<sz; i++)
        {
            int j=(i+1)%sz;
            int k=(i+2)%sz;
            double x=res(a[i], a[j], a[k]);
            double y=(x/pi)*180.0;
            mn=min(mn, y);
        }
        if(n<3 || fabs(mn-400)<=1e-9)
            printf("Case %d: 0\n", cs);
        else
            printf("Case %d: %.6f\n", cs, mn);
    }
    return 0;
}
