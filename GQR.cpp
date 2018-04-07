#include <iostream>

using namespace std;

int gcd(int m, int n)
{
    if(m%n==0)
        return n;
    else
        return gcd(n,m%n);
}

int main()
{
    int n,q,l,r;
    cin>>n>>q;
    int ar[n];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    int hcf[n][n];
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            hcf[j][i]=gcd(ar[i],ar[j]);
    int res[n][n];
    for(int i=0;i<n-1;i++)
        res[i][i+1]=hcf[i][i+1];
    for(int i=2;i<n;i++)
        for(int j=0;j<n-i;j++)
            res[j][j+i]=max(res[j][j+i-1],max(res[j+1][j+i],hcf[j][j+i]));

    while(q--)
    {
        cin>>l>>r;
        cout<<res[l-1][r-1]<<endl;
    }
    return 0;
}
