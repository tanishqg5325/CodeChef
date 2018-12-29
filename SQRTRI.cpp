#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	int t,a,b,x,y;
	cin>>t;
	while(t--)
	{
	    cin>>a>>b>>x>>y;
	    bool flag = 0;
	    double c1 = (a-b-y)*x*1.0/b + x;
	    double c2 = (x+ b - a)*(a-y-b)*1.0/b + x + b;
	    if(c2 <= c1) flag = 1;
	    c1 = x*y*1.0/b + x;
	    c2 = (x+b-a)*y*1.0/b + x + b;
	    if(c2 <= c1) flag = 1;
	    c1 = (a-x-b)*y*1.0/b + y;
	    c2 = (y+b-a)*(a-x-b)*1.0/b + y + b;
	    if(c2 <= c1) flag = 1;
	    c1 = x*y*1.0/b + y;
	    c2 = (y+b-a)*x*1.0/b + y + b;
	    if(c2 <= c1) flag = 1;
	    if(flag) cout<<"yes\n";
	    else cout<<"no\n";
	}
	return 0;
}

