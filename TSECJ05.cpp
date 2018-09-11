#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,k,x,nl;
    cin>>t;
    while(t--)
    {
        priority_queue<int, vector<int>, greater<int>> left;
        priority_queue<int, vector<int>, less<int>> right;
        cin>>k>>n; nl=0;
        while(n--)
        {
            cin>>x;
            if(nl<k-1) {left.push(x); cout<<"-1 "; nl++;}
            else if(nl == k-1){left.push(x); nl++; cout<<left.top()<<" ";}
            else
            {
                if(x<left.top()) right.push(x);
                else
                {
                    right.push(left.top());
                    left.pop();
                    left.push(x);
                }
                cout<<left.top()<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
