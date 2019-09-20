#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;

int N = 1000001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll gcd[N]{}, ans[N]{};
    int n,q,g,k; cin>>n; int ar[n];
    for(int i=0;i<n;i++) cin>>ar[i];
    map<int, ll> tmp1, tmp2;
    for(int i=0;i<n;i++)
    {
        for(auto &j : tmp1)
        {
            g = __gcd(ar[i], j.X);
            if(g < N) gcd[g] += j.Y;
            tmp2[g] += j.Y;
        }
        tmp2[ar[i]]++;
        if(ar[i] < N) gcd[ar[i]]++;
        tmp1 = tmp2; tmp2.clear();
    }
    for(int i=1;i<N;i++)
    {
        if(gcd[i] == 0) continue;
        for(int j=i;j<N;j+=i)
            ans[j] += gcd[i];
    }
    cin>>q;
    while(q--)
    {
        cin>>k;
        cout<<ans[k]<<"\n";
    }
    return 0;
}
