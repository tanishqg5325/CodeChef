#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t,n,k,tmp;
    long long ans;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>str;
        tmp=1;ans=0;
        for(int i=1;i<k;i++) if(str[i]!=str[i-1]) tmp++;
        for(int i=k;i<n;i++)
        {
            ans+=tmp;
            if(str[i-k]!=str[i-k+1]) tmp--;
            if(str[i]!=str[i-1]) tmp++;
            else ans--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
