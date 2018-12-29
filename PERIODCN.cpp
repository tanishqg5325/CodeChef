#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	int t,l,r;
	cin>>t;
	vector<ll> v;
	for(int i=1;i<=30;i++)
	{
	    for(int j=1;j<=i;j++)
	    {
	        if(i % j) continue;
	        ll num = 0;
	        int a = i/j;
	        for(int b=0;b<a/2;b++)
	        {   
	            for(int k=0;k<j;k++)
	            {
	                num = num << 1; num++;
	            }
	            num = num<<j;
	        }
	        if(a % 2) 
	        {
	            for(int k=0;k<j;k++)
	            {
	                num = num << 1; num++;
	            }
	        }
	        v.push_back(num);
	    }
	}
	int k = v.size();
	while(t--)
	{
	    cin>>l>>r; int ans = 0;
	    if(l > r) {cout<<"0\n"; continue;}
	   for(int i=0;i<k;i++) if(v[i] >= l && v[i] <= r) ans++;
	   cout<<ans<<"\n";
	}
	return 0;
}

