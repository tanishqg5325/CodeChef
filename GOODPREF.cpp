#include <iostream>
#include <string>
#include <math.h>

using namespace std;

long long ciel(float f)
{
    if(floor(f)==f)
        return f;
    return floor(f)+1;
}

int main()
{
    long long t,n,l;
    long long count1,count2,count,ans,k1,k2;
    char c;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>std::noskipws;
        cin>>c;
        while (cin >> c)
        {
            if(c == ' ')
                break;
            s.push_back(c);
        }
        l=s.size();
        cin>>n;
        count1=count2=count=k1=k2=0;
        long long temp1[l],temp2[l];
        for(int j=0;j<l;j++)
        {
            if(s[j]=='a')
                count1++;
            else if(s[j]=='b')
                count2++;
            if(count1>count2)
            {
                count++;
                temp2[k2++]=count1-count2;
            }
            else
                temp1[k1++]=count2-count1;
        }
        if(count1==count2)
            ans=count*n;
        else if(count1>count2)
        {
            ans=count*n;
            for(int i=0;i<k1;i++)
                ans+=max(n-ciel((float)(temp1[i]+1)/(count1-count2)),(long long)0);
        }
        else
        {
            ans=0;
            for(int i=0;i<k2;i++)
                ans+=min(ciel((float)(temp2[i])/(count2-count1)),n);
        }
        cout<<ans<<endl;
    }
    return 0;
}
