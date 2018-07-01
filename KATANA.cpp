#include <bits/stdc++.h>
using namespace std;

void fastscan(int &number)
{
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number*10 + c - 48;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k=0,ans=0;
    fastscan(n);
    int ar[n],q[n];
    for(int i=0;i<n;i++) fastscan(ar[i]);
    q[0]=ar[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(ar[i]>q[k]) q[++k] = ar[i];
        else if(ar[i]<q[k])
        {
            while(q[k]>ar[i]) {ans++;k--;}
            if(q[k]!=ar[i]) q[++k] = ar[i];
        }
    }
    cout<<ans+k+1<<endl;
    return 0;
}
