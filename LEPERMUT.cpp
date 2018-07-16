#include <iostream>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++) cin>>ar[i];
        int loc_inv=0,inv=0;
        for(int i=0;i<n-1;i++) if(ar[i]>ar[i+1]) loc_inv++;
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(ar[i]>ar[j])
                    inv++;
        if(loc_inv == inv) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
