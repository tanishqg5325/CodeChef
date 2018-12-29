#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n; string str; bool flag;
	cin>>t;
	while(t--)
	{
	    cin>>str; n = str.size(); flag = 1;
	    for(int i=0;i<n-1;i+=2)
	    {
	        if(str[i] == 'A' && str[i+1] == 'B') continue;
	        if(str[i] == 'B' && str[i+1] == 'A') continue;
	        flag = 0;
	        break;
	    }
	    if(flag) cout<<"yes\n";
	    else cout<<"no\n";
	}
	return 0;
}

