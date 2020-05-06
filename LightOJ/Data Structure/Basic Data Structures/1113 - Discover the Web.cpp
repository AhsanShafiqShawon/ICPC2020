#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<string>Back, Forward;
    string str, key;
    int testCase;
    scanf("%d", &testCase);
    for(int cs=1; cs<=testCase; cs++)
    {
        printf("Case %d:\n", cs);
        Back.push("http://www.lightoj.com/");
        while(1)
        {
            cin>>key;
            if(key=="QUIT")     break;
            else if(key=="VISIT")
            {
                cin>>str;
                Back.push(str);
                cout << Back.top() << endl;
                while(!Forward.empty())
                    Forward.pop();
            }
            else if(key=="BACK")
            {
                if(Back.size()>1)
                {
                    string x=Back.top();
                    Forward.push(x);
                    Back.pop();
                    cout << Back.top() << endl;
                }
                else
                    cout << "Ignored" << endl;
            }
            else
            {
                if(!Forward.empty())
                {
                    string x=Forward.top();
                    Back.push(x);
                    Forward.pop();
                    cout << Back.top() << endl;
                }
                else
                    cout << "Ignored" << endl;
            }
        }
        while(!Back.empty())        Back.pop();
        while(!Forward.empty())     Forward.pop();
    }
    return 0;
}
