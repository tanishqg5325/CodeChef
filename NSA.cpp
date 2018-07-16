#include <bits/stdc++.h>
#include <cmath>
#include <string>
typedef long long ll;
using namespace std;

ll ycost(string str, int n)
{
    ll dp[26]{},ans=0;
    for(int i=n-1;i>=0;i--)
    {
        dp[str[i]-'a']++;
        for(int j=str[i]-'a'+1;j<26;j++)
            ans+=dp[j];
    }
    return ans;
}

int main()
{
    int t,n; string str; ll cost,mincost,init_cost;
    cin>>t;
    while(t--)
    {
        cin>>str;
        n = str.size();
        mincost = init_cost = ycost(str,n);
        ll before[26]{},after[26]{};
        for(int i=0;i<n;i++) after[str[i]-'a']++;
        for(int i=0;i<n;i++)
        {
            char c = str[i];
            after[c-'a']--;
            for(char ch='a';ch<='z';ch++)
            {
                str[i]=ch;
                cost = (ll)abs(ch-c) + init_cost;
                if(ch>c)
                {
                    for(char cha=c+1;cha<=ch;cha++) cost -= after[cha-'a'];
                    for(char cha=c;cha<ch;cha++) cost += before[cha-'a'];
                }
                else if(ch<c)
                {
                    for(char cha=ch+1;cha<=c;cha++) cost += after[cha-'a'];
                    for(char cha=ch;cha<c;cha++) cost -= before[cha-'a'];
                }
                if(cost<mincost) mincost=cost;
            }
            str[i]=c;
            before[c-'a']++;
        }
        cout<<mincost<<"\n";
    }
    return 0;
}
