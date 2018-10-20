#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,k; int ans,temp; string str;
    cin>>t;
    while(t--)
    {
        cin>>n; ans=0; unordered_map<string,int> h;
        while(n--)
        {
            cin>>str;
            if(h[str]) {ans += (h[str]/2); continue;}
            temp = 2; int k = str.size(); bool hand;
            if(str[0] == 'd' || str[0] == 'f') hand=0; else hand = 1;
            for(int i=1;i<k;i++)
            {
                if(str[i] == 'd' || str[i] == 'f')
                {
                    if(hand) temp += 2; else temp += 4;
                    hand = 0;
                }
                else
                {
                    if(hand) temp += 4; else temp += 2;
                    hand = 1;
                }
            }
            ans += temp;
            h[str] = temp;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
