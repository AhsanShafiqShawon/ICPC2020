#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int testCase, n, m, x;
    scanf("%d", &testCase);
    for(int cs=1; cs<=testCase; cs++)
    {
        deque<int>dq;
        scanf("%d%d", &n, &m);
        printf("Case %d:\n", cs);
        for(int i=0; i<m; i++)
        {
            cin>>str;
            if(str=="pushLeft")
            {
                if(dq.size()<n)
                {
                    scanf("%d", &x);
                    dq.push_front(x);
                    printf("Pushed in left: %d\n", x);
                }
                else
                {
                    scanf("%d", &x);
                    printf("The queue is full\n");
                }
            }
            else if(str=="pushRight")
            {
                if(dq.size()<n)
                {
                    scanf("%d", &x);
                    dq.push_back(x);
                    printf("Pushed in right: %d\n", x);
                }
                else
                {
                    scanf("%d", &x);
                    printf("The queue is full\n");
                }
            }
            else if(str=="popRight")
            {
                if(dq.size()>0)
                {
                    int x=dq.back();
                    dq.pop_back();
                    printf("Popped from right: %d\n", x);
                }
                else
                    printf("The queue is empty\n");
            }
            else
            {
                if(dq.size()>0)
                {
                    int x=dq.front();
                    dq.pop_front();
                    printf("Popped from left: %d\n", x);
                }
                else
                    printf("The queue is empty\n");
            }
        }
    }
    return 0;
}
