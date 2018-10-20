#include <bits/stdc++.h>
#define ll long long
using namespace std;

int freq[1000001]{};

struct circle
{
    double x;
    double y;
    double r;
}c[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	double x1,y1,d,r1,r2,kMAx,kMin;
	for(int i=0; i<n; i++) cin>>c[i].x>>c[i].y>>c[i].r;
	for(int i=0; i<n; i++)
	    for(int j=i+1; j<n; j++)
	    {
	        x1 = c[i].x-c[j].x;
	        y1 = c[i].y-c[j].y;
	        d = sqrt(x1*x1 + y1*y1);
	        r1 = c[i].r;
	        r2 = c[j].r;
	        if(d <= r1+r2)
	        {
                if(fabs(r1-r2)<=d) kMin = 0;
                else kMin = ceil(fabs(r1-r2)-d);
	        }
            else kMin = ceil(d-r1-r2);
	        kMAx = floor(d+r1+r2)+1;
	        if(kMin <= 1000000) freq[(int)kMin]++;
            if(kMAx <= 1000000) freq[(int)kMAx]--;
	    }
	for(int i=1; i<=1000000; i++) freq[i] += freq[i-1];
	while(q--)
	{
	    int k;
	    cin>>k;
	    cout<<freq[k]<<"\n";
	}
	return 0;
}
