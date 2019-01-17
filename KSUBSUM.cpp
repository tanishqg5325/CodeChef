#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> merge(vector<int> &highest_k, vector<int> &v, int k)
{
    vector<int> ans;
    int a = 0,i=0,j=0,a1 = highest_k.size(),a2 = v.size();
    while(a < k && i < a1 && j < a2)
    {
        if(highest_k[i] > v[j]) {ans.pb(highest_k[i]); i++;}
        else {ans.pb(v[j]); j++;}
        a++;
    }
    while(a < k && i < a1) {ans.pb(highest_k[i]); a++; i++;}
    while(a < k && j < a2) {ans.pb(v[j]); a++; j++;}
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,k1,k2,k;
    cin>>T;
    while(T--)
    {
        cin>>n>>k1>>k2>>k;
        int ar[n+1],sum[n+1]{}; for(int i=1;i<=n;i++) {cin>>ar[i]; sum[i] = sum[i-1] + ar[i];}
        multiset<int> lowest_prefix;
        vector<int> highest_k;
        lowest_prefix.insert(sum[0]);
        for(int i=1;i<=n;i++)
        {
            vector<int> v;
            for(int j : lowest_prefix) v.pb(sum[i] - j);
            highest_k = merge(highest_k, v, k);
            if(lowest_prefix.size() < k) lowest_prefix.insert(sum[i]);
            else if(sum[i] < *(lowest_prefix.rbegin()))
            {
                auto it = lowest_prefix.end(); it--;
                lowest_prefix.erase(it);
                lowest_prefix.insert(sum[i]);
            }
        }
        int cnt = 1;
        for(int i : highest_k)
        {
            if(cnt == k1 || cnt == k2 || cnt == k) cout<<i<<" ";
            cnt++;
        }
        cout<<"\n";
    }
    return 0;
}
