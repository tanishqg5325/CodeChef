#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int t,n; ll tmp,ans; cin>>t;
	while(t--)
	{
	    cin>>n;
	    ll ar[n],maxEnd[n],minEnd[n], maxStart[n], minStart[n];
	    for(int i=0;i<n;i++) cin>>ar[i];
	    tmp = maxEnd[0] = ar[0];
	    for(int i=1;i<n;i++)
	    {
	        tmp = ar[i] + max(tmp, (ll)0);
	        maxEnd[i] = max(maxEnd[i-1], tmp);
	    }
	    tmp = minEnd[0] = ar[0];
	    for(int i=1;i<n;i++)
	    {
	        tmp = ar[i] + min(tmp, (ll)0);
	        minEnd[i] = min(minEnd[i-1], tmp);
	    }
	    tmp = maxStart[n-1] = ar[n-1];
	    for(int i=n-2;i>=0;i--)
	    {
	        tmp = ar[i] + max(tmp, (ll)0);
	        maxStart[i] = max(maxStart[i+1], tmp);
	    }
	    tmp = minStart[n-1] = ar[n-1];
	    for(int i=n-2;i>=0;i--)
	    {
	        tmp = ar[i] + min(tmp, (ll)0);
	        minStart[i] = min(minStart[i+1], tmp);
	    }
	    ans = abs(ar[0] - ar[1]);
	    for(int i=1;i<n;i++)
	    {
	        ans = max(ans, maxStart[i] - minEnd[i-1]);
	        ans = max(ans, maxEnd[i-1]- minStart[i]);
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}

