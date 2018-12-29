#include <bits/stdc++.h>
typedef long long ll;
#define MAX_N 10001
using namespace std;

bool isPrime[MAX_N];
int levy[MAX_N];

void sieve()
{
    for (int i=2;i < MAX_N;i++) isPrime[i] = 1;
    for (int i=2;i*i < MAX_N;i++)
        if (isPrime[i])
            for (int j=i*i;j < MAX_N;j+=i)
                isPrime[j] = false;
}

void ans()
{
    for(int i=2;i<MAX_N;i++)
        if(isPrime[i])
            for(int j=2*i+2;j<MAX_N;j++)
                if(isPrime[j-2*i])
                    levy[j]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    sieve(); ans();
    int t,n; cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<levy[n]<<"\n";
    }
    return 0;
}
