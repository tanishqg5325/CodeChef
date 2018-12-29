#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
	int t,n,ans,k;
	cin>>t;
	while(t--)
	{
	    cin>>n; int ar[n];
	    for(int i=0;i<n;i++) cin>>ar[i];
	    if(n == 1) {cout<<"1\n"; continue;}
	    vector<int> v;
	    int lar = ar[0]; v.pb(0);
	    for(int i=1;i<n;i++) if(ar[i] >= lar) {v.pb(i); lar = ar[i];}
	    ans = k = v.size();
	    int ans1 = 1; lar = ar[1];
	    for(int i=2;i<n;i++) if(ar[i] >= lar) {ans1++; lar = ar[i];}
	    ans = max(ans,ans1);
	    for(int i=1;i<k-1;i++)
	    {
	        int c = 0; lar = ar[v[i-1]];
	        for(int j=v[i]+1;j<v[i+1];j++)
	        {
	            if(ar[j] >= lar) {c++; lar = ar[j];}
	        }
	        ans = max(ans, k-1+c);
	    }
	    if(k > 1)
	    {
	        int c = 0; lar = ar[v[k-2]];
    	    for(int j=v[k-1]+1;j<n;j++)
    	    {
    	        if(ar[j] >= lar) {c++; lar = ar[j];}
    	    }
    	    ans = max(ans,k-1+c);
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}

