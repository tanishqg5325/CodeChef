#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;

int findMax(vector<int> &ar)
{
    int n = ar.size(),maxSum = 0,endSum = 0;
    for(int i=0;i<n;i++)
    {
        endSum = max(endSum+ar[i],0);
        maxSum = max(maxSum,endSum);
    }
    return maxSum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int q,k,b,C,c,d,ans=0;
    cin>>q>>k; list<pii> dishes;
    while(q--)
    {
        cin>>b;
        if(b == 1)
        {
            cin>>C>>d; c = C ^ ans;
            dishes.insert(dishes.begin(), mp(c,d));
        }
        else if(b == 2)
        {
            cin>>C>>d; c = C ^ ans;
            dishes.pb(mp(c,d));
        }
        else
        {
            cin>>C; c = C ^ ans; vector<int> v;
            for(list<pii>::iterator i = dishes.begin(); i != dishes.end(); i++)
                if((*i).first >= c-k && (*i).first <= c+k) v.pb((*i).second);
            ans = findMax(v);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
