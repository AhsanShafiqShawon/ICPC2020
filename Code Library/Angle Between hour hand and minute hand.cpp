#include <bits/stdc++.h>
using namespace std;
vector<char>vc;
int main()
{
    double h, m;
    cin>>h>>m;
    cout<<fixed<<setprecision(10)<<180-abs(180-abs(m*6-(h*30+m*0.5)))<<endl;
    return 0;
}
