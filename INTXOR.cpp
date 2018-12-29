#include <bits/stdc++.h>
using namespace std;

int ask(int i, int j, int k)
{
    int ans;
    cout<<"1 "<<i<<" "<<j<<" "<<k<<endl;
    cin>>ans;
    return ans;
}

int main()
{
    int T,n,ver;
    cin>>T;
    while(T--)
    {
        cin>>n; int a[n+1];
        int a123 = ask(1,2,3);
        int a124 = ask(1,2,4);
        int axy = a123 ^ a124;
        for(int i=5;i<=n;i++)
        {
            int j = i;
            if(i%2 == 0) j--;
            a[i] = ask(j-2,j-1,i) ^ axy;
            if(i%2 == 0) axy = a[i] ^ a[i-1];
        }
        a[1] = ask(n-1,n,1) ^ a[n-1] ^ a[n];
        if(n%2 == 0) a[2] = ask(n-1,n,2) ^ a[n-1] ^ a[n];
        else a[2] = ask(n-2,n,2) ^ a[n-2] ^ a[n];
        a[3] = a123 ^ a[1] ^ a[2];
        a[4] = a124 ^ a[1] ^ a[2];
        cout<<"2 ";
        for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
        cin>>ver;
        if(ver == -1) return 0;
    }
    return 0;
}
