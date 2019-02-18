#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int t,n,ans; cin>>t;
	while(t--)
	{
	    cin>>n; int ar[n];
	    for(int i=0;i<n;i++) cin>>ar[i];
	    sort(ar, ar+n);
	    ans = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(ar[i] > i) break;
	        ans++;
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}

