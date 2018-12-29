#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n; int ar[n];
	    for(int i=0;i<n;i++) cin>>ar[i];
	    sort(ar,ar+n);
	    ll ans = 0;
	    for(int i=0;i<n/2;i++) ans -= ar[i];
	    for(int i=n/2;i<n;i++) ans += ar[i];
	    cout<<ans<<"\n";
	}
	return 0;
}

