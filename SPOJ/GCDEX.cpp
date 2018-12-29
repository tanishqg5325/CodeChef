#include <bits/stdc++.h>
typedef long long ll;
#define MAX_N 1000001
using namespace std;

bool isPrime[MAX_N];
ll eulerPhi[MAX_N], sumGCD[MAX_N];

void sieve()
{
    for (int i=2;i < MAX_N;i++) isPrime[i] = 1;
    for (int i=2;i*i < MAX_N;i++)
        if (isPrime[i])
            for (int j=i*i;j < MAX_N;j+=i) 
                isPrime[j] = false;
}

void eulerSieve()
{
    for (int i=1;i < MAX_N;i++) eulerPhi[i] = i;
    for (int i = 2; i < MAX_N; i++)
        if (isPrime[i])
            for (int j=i;j<MAX_N;j+=i)
                    eulerPhi[j] -= eulerPhi[j] / i;
}

void ans()
{
    for(int i=1;i<MAX_N;i++)
        for(int j=2*i;j<MAX_N;j+=i)
            sumGCD[j] += i * eulerPhi[j/i];
    for(int i=2;i<MAX_N;i++) sumGCD[i] += sumGCD[i-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    sieve(); eulerSieve(); ans();
    int n; cin>>n;
    while(n)
    {
        cout<<sumGCD[n]<<"\n";
        cin>>n;
    }
    return 0;
}

