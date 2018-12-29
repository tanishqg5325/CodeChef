#include <bits/stdc++.h>
#define pii pair<int,int>
#define MAX_N 100001
using namespace std;

int dist_prime[MAX_N]; bool isPrime[MAX_N];

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i=0;i<MAX_N;i++) isPrime[i] = 1;
    for(int i=2;i<MAX_N;i++)
    {
        if(isPrime[i])
        {
            dist_prime[i]++;
            for(int j=2*i;j<MAX_N;j+=i)
            {
                isPrime[j] = 0;
                dist_prime[j]++;
            }
        }
    }
    int t,n,ans,a1;
    cin>>t;
    while(t--)
    {
        cin>>n; int ar[n]; int tmp[MAX_N]{};
        for(int i=0;i<n;i++) {cin>>ar[i]; tmp[ar[i]]++;}
        ans = 0;
        for(int i=2;i<MAX_N;i++)
        {
            a1 = 0;
            for(int j=i;j<MAX_N;j+=i) a1 += tmp[j];
            ans = max(ans, a1*dist_prime[i]);
        }
        cout<<ans<<"\n";
    }
	return 0;
}
