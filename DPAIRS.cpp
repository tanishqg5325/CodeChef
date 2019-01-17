#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    pii a[n],b[m];
    for(int i=0;i<n;i++) {cin>>a[i].X; a[i].Y = i;}
    for(int i=0;i<m;i++) {cin>>b[i].X; b[i].Y = i;}
    sort(a,a+n); sort(b,b+m);
    for(int i=0;i<m;i++)
        cout<<a[0].Y<<" "<<b[i].Y<<"\n";
    for(int i=1;i<n;i++)
        cout<<a[i].Y<<" "<<b[m-1].Y<<"\n";
    return 0;
}
