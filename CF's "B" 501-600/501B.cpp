#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, j=0;
    vector<int>ans;
    string s, t;
    cin>>n>>s>>t;
    for(int i=0; i<n; i++)
    {
        if(s[i]==t[j])
        {
            j++;
            continue;
        }
        for(int k=i; k<n; k++)
        {
            if(s[k]==t[j])
            {
                for(int f=k-1; f>=i; f--)
                {
                    swap(s[f], s[f+1]);
                    ans.push_back(f);
                }
                j++;
                break;
            }
        }
    }
    if(s==t)
    {
        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); i++)
            cout << ans[i]+1 << " ";
    }
    else
        cout << -1 << endl;
    return 0;
}
