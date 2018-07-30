#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int t; string m,n;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        int n1=m.size(),n2=n.size(),ans1=0,ans2=0;
        for(int i=0;i<n1;i++) ans1 = (ans1 + m[i] - '0') % 3;
        for(int i=0;i<n2;i++) ans2 = (ans2 + n[i] - '0') % 3;
        cout<<(ans1*ans2)%3<<endl;
    }
    return 0;
}
