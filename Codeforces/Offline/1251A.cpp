#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    string ss;
    vector<char> vc;
    set<char>st;
    set<char>::iterator it;
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        cin >> ss;
        for(int j=0; j<ss.size()-1; j++)
        {
            char chA=ss[j];
            char chB=ss[j+1];
            if(chA==chB)
            {
                ss[j]='.';
                ss[j+1]='.';
            }
        }
        //cout << ss << endl;
        for(int j=0; j<ss.size(); j++)
        {
            char chC=ss[j];
            if(chC!='.')
                st.insert(chC);
        }
        for(it=st.begin(); it!=st.end(); it++)
            cout << *it;
        puts("");
        st.clear();
    }
    return 0;
}
