#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, r;
    string ss;
    char a, b;
    scanf("%d", &t);
    while(t--)///6
    {
        char alpha[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        cin>>ss;
        scanf("%d", &r);
        for(int i=0; i<r; i++)///6*10000
        {
            cin>>a>>b;
            for(int j=0; j<26; j++)///6*10000*26
            {
                if(alpha[j]==b)
                    alpha[j]=a;
            }
        }
        for(int i=0; i<ss.size(); i++)///1000000*6
        {
            if(ss[i]>='A' && ss[i]<='Z')
                cout <<alpha[ss[i]-'A'];
            else
                cout <<"_";
        }
        printf("\n");
    }
    return 0;
}
