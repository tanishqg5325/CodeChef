#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int LIS(vector<int> &v)
{
    if (v.empty()) return 0;
    vector<int> tail;
    int length = 1, n = v.size();
    tail.pb(v[0]);
    for (size_t i = 1;i<n;i++)
    {
        if (v[i] < tail[0]) tail[0] = v[i];
        else if (v[i] >= tail[length - 1]) {tail.pb(v[i]); length++;}
        else *upper_bound(tail.begin(), tail.end(), v[i]) = v[i];
    }
    return length;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int c,n; cin>>c>>n;
    pii cards[c*n];
    for(int i=0;i<c*n;i++) cin>>cards[i].X>>cards[i].Y;
    int perm[c+1]; for(int i=1;i<=c;i++) perm[i] = i;
    int ans = n*c;
    do {
        vector<int> v;
        for(int i=0;i<c*n;i++)
            v.pb((perm[cards[i].X] - 1) * n + cards[i].Y);
        ans = min(ans, n*c - LIS(v));
    }while(next_permutation(perm+1, perm+c+1));
    cout<<ans<<"\n";
    return 0;
}
