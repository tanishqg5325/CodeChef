#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed; cout<<setprecision(8);
    int n,k; cin>>n>>k;
    int ar[n][k]; int sum[n]{}; double ans[k];
    for(int i=0;i<n;i++) for(int j=0;j<k;j++) {cin>>ar[i][j]; sum[i] += ar[i][j];}
    for(int i=0;i<k;i++) ans[i] = 1.0 * ar[0][i] / sum[0];
    for(int i=1;i<n;i++)
        for(int j=0;j<k;j++)
            ans[j] = (ans[j] * (ar[i][j]+1.0)/(sum[i]+1)) + (1-ans[j]) * (ar[i][j]*1.0)/(sum[i]+1);
    for(int i=0;i<k;i++) cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
