#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

void rever(int a2[], int l, int r)
{
    for(int i=l,j=r;i<j;i++,j--) swap(a2[i], a2[j]);
}

bool isEqual(int a1[], int b1[], int n)
{
    for(int i=0;i<n;i++) if(a1[i] != b1[i]) return 0; return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,m,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int ar[n],b[n]; pii op[m]; p = 0;
        for(int i=0;i<n;i++) cin>>ar[i];
        for(int i=0;i<m;i++) {cin>>op[i].first>>op[i].second; op[i].first--; op[i].second--;}
        for(int i=0;i<n;i++) b[i] = ar[i];
        for(int i=0;i<m;i++) rever(b, op[i].first, op[i].second);
        int fact_m = 1;
        for(int i=2;i<=m;i++) fact_m *= i;
        for(int i=0;i<fact_m;i++)
        {
            int tmp[n];
            for(int i=0;i<n;i++) tmp[i] = ar[i];
            for(int i=0;i<m;i++) rever(tmp, op[i].first, op[i].second);
            if(isEqual(tmp, b, n)) p++;
            next_permutation(op, op+m);
        }
        cout<<p/__gcd(p,fact_m)<<"/"<<fact_m/__gcd(p,fact_m)<<"\n";
    }
	return 0;
}
