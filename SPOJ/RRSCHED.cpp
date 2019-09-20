#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

int find_cf(int idx, int tree[])
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, int tree[], int MaxIdx)
{
    while(idx <= MaxIdx)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n; pli task[n+1]; ll ans[n+1]; int bit[n+1]{};
    for(int i=1;i<=n;i++) {cin>>task[i].X; task[i].Y = i;}
    sort(task+1, task+n+1);
    ll past_time = 1, done_time = n; int left = n;
    for(int i=1;i<=n;i++)
    {
        ans[task[i].Y] = done_time + (task[i].X - past_time - 1) * left + task[i].Y - find_cf(task[i].Y, bit);
        done_time += (task[i].X - past_time) * left;
        past_time = task[i].X; left--;
        update(task[i].Y, 1, bit, n);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
    return 0;
}
