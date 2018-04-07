#include <iostream>

using namespace std;

int main()
{
    long long t,n,k,min,max;
    long long ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long ar[n];
        k=0;
        cin>>ar[0];
        min=max=ar[0];
        for(int i=1;i<n;i++)
        {
            cin>>ar[i];
            if(ar[i]<min)
                min=ar[i];
            if(ar[i]>max)
                max=ar[i];
        }
        long long cache[max-min+1]{},num[max-min+1];
        for(int i=0;i<n;i++)
        {
            if(cache[ar[i]-min]==0)
                num[k++]=ar[i];
            cache[ar[i]-min]++;
        }
        ans=0;
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                if((2*num[i]-num[j])>=min && (2*num[i]-num[j])<=max)
                {
                    ans+=(cache[2*num[i]-num[j]-min]*cache[num[j]-min]);
                    if(i==j)
                        ans-=cache[num[j]-min];
                }
        cout<<ans/2<<endl;
    }
    return 0;
}
