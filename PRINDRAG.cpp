#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void process(ll s[], ll n, ll index[], ll length, ll p, ll minsum)
{
    ll opsize = 1<<n; ll tempindex[length+1],l,sum;
    for (ll counter = 1; counter < opsize; counter++)
    {
        l=0; sum=0;
        for (ll j = 0; j < n; j++)
        {
            if (counter & (1<<j))
            {
                tempindex[l++]=j; sum += s[j];
            }
            if(l>length) break;
        }
        if(l==length && sum>=p && sum<minsum)
        {
            minsum=sum;
            for(ll j=0;j<length;j++) index[j]=tempindex[j]+1;
        }
        if(minsum==p) return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t,n,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        ll s[n]; ll sum=0;
        for(ll i=0;i<n;i++) {cin>>s[i]; sum += s[i];}
        sort(s,s+n, greater<ll>());
        if(sum+s[0]<2*p)
        {
            ll tmp=0; ll i;
            for(i=0;i<n;i++)
            {
                tmp += s[i];
                if(tmp>=p) break;
            }
            tmp = i;
            ll ans[n];
            for(i=0;i<=(n-1)/2;i++) ans[i] = max(n-tmp-i,(ll)0);
            for(;i<n;i++) ans[i]=ans[n-i-1];
            for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
            cout<<"\n";
        }
        else
        {
            p -= s[0]; ll i,tmp1=0,tmp2=0;
            if(p<=0) { for(ll i=0;i<n;i++) cout<<n<<" "; cout<<"\n"; continue; }
            for(i=1;i<n;i++)
            {
                tmp1 += s[i];
                if(tmp1>=p) break;
            }
            ll length1=i,index[length1],temp[n-1];
            if(length1==n) return 1;
            for(ll i=0;i<n-1;i++) temp[i] = s[i+1];
            for(ll i=0;i<length1;i++) index[i]=i+1;
            process(temp,n-1,index,length1,p,tmp1);
            ll length2=0,temp2=0; bool flag;
            for(i=1;i<n;i++)
            {
                flag=0;
                for(ll j=0;j<length1;j++)
                    if(index[j]==i)
                    {
                        flag=1; break;
                    }
                if(flag) continue;
                temp2 += s[i]; length2++;
                if(temp2>=p) break;
            }
            if(i==n) return 1;
            ll ans[n];
            for(i=0;i<=(n-1)/2;i++)
                ans[i] = max(n-i-length1,(ll)0)+max(i-length2+1,(ll)0);
            for(;i<n;i++) ans[i]=ans[n-i-1];
            for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
