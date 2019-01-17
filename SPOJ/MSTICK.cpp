#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

bool compare(pii &p1, pii &p2)
{
    if(p1.X != p2.X) return p1.X < p2.X;
    return p1.Y < p2.Y;
}

int LIS(vector<int> &v)
{
    if (v.empty()) return 0;
    vector<int> tail;
    int length = 1, n = v.size();
    tail.pb(v[0]);
    for (size_t i = 1;i<n;i++)
    {
        if (v[i] > tail[length - 1]) {tail.pb(v[i]); length++;}
        else if(find(tail.begin(), tail.end(), v[i]) == tail.end())
            *upper_bound(tail.begin(), tail.end(), v[i]) = v[i];
    }
    return length;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n; pii dolls[n];
        for(int i=0;i<n;i++) cin>>dolls[i].X>>dolls[i].Y;
        sort(dolls, dolls + n, compare);
        vector<int> v; for(int i=n-1;i>=0;i--) v.pb(dolls[i].Y);
        cout<<LIS(v)<<"\n";
    }
    return 0;
}
