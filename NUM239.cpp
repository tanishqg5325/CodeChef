#include <iostream>
using namespace std;

int main()
{
    int t,l,r,ans,l1,r1;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        l1 = l+10-(l%10);
        r1 = r - (r%10);
        ans = (r1-l1)*3/10;
        if(r%10==9) ans+=3;
        else if(r%10>=3) ans+=2;
        else if(r%10>=2) ans+=1;
        if(l%10<=2) ans+=3;
        else if(l%10<=3) ans+=2;
        else ans++;
        cout<<ans<<endl;
    }
    return 0;
}
