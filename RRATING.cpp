#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,a,x,nl=0,nr=0;
    cin>>n;
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    while(n--)
    {
        cin>>a;
        if(a == 1)
        {
            cin>>x;
            if(nl == 2*nr+2)
            {
                if(x>=left.top()) right.push(x);
                else
                {
                    right.push(left.top());
                    left.pop();
                    left.push(x);
                }
                nr++;
            }
            else
            {
                if(nl < 2 || x <= right.top()) left.push(x);
                else
                {
                    left.push(right.top());
                    right.pop();
                    right.push(x);
                }
                nl++;
            }
        }
        else
        {
            if(!right.empty()) cout<<right.top()<<"\n";
            else cout<<"No reviews yet\n";
        }
    }
    return 0;
}
