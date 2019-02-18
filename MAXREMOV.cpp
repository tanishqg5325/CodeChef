#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int t,n,k,ans; cin>>t;
	while(t--)
	{
	    cin>>n>>k;
	    int c[100005]{},l[n],r[n]; int maxi = 0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>l[i]>>r[i];
	        c[l[i]]++; c[r[i]+1]--;
	        maxi = max(maxi, r[i]);
	    }
	    for(int i=1;i<=maxi;i++) c[i] += c[i-1];
	    int k_[maxi+1],k_1[maxi+1]; k_[0] = k_1[0] = 0;
	    for(int i=1;i<=maxi;i++)
	    {
	        k_[i] = k_[i-1]; k_1[i] = k_1[i-1];
	    	if(c[i] == k) k_[i]++;
	    	else if(c[i] == k+1) k_1[i]++;
	    }
	    ans = 0;
	    int temp = k_[maxi];
	    for(int i=0;i<n;i++)
	        ans = max(ans, temp + k_1[r[i]] - k_1[l[i]-1] + k_[l[i]-1] - k_[r[i]]);
	    cout<<ans<<"\n";
	}
	return 0;
}
