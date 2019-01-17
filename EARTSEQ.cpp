#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> ans;

void sieve()
{
    int pn = 2500; bool isPrime[pn];
    for (int i=2;i<pn;i++) isPrime[i] = 1;
    for (int i=2;i*i<pn;i++)
        if (isPrime[i])
            for (int j=i*i;j<pn;j+=i)
                isPrime[j] = 0;
    vector<int> primes; primes.pb(2);
    for(int i=3;i<pn;i+=2) if(isPrime[i]) primes.pb(i);

	set<int, greater<int>> seq[pn];
	ans.pb(2); ans.pb(3); ans.pb(5);
	seq[2].insert(5); seq[5].insert(2);
	int last = 5, max_p = 5; set<int>::iterator j;
	for(int i=0;i<49997;i++)
	{
	    if(!seq[last].empty())
	    {
	        j = seq[last].begin();
	        seq[last].erase(j);
	        seq[*j].erase(last);
	        last = *j;
	    }
	    else
	    {
	        max_p = *upper_bound(primes.begin(), primes.end(), max_p);
	        for(int a = 0; primes[a] != max_p;a++)
	        {
	            if(primes[a] == last) continue;
	            seq[primes[a]].insert(max_p);
	            seq[max_p].insert(primes[a]);
	        }
	        last = max_p;
	    }
	    ans.pb(last);
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    sieve(); int p1 = 2473,p2 = 2477;
    int T,n; cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n-3;i++) cout<<ans[i] * ans[i+1]<<" ";
        cout<<ans[n-3] * p1<<" "<<p1 * p2<<" "<<p2 * ans[0]<<"\n";
    }
    return 0;
}
