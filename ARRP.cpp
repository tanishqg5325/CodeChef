#include <iostream>

using namespace std;

int check(int ar[],int n)
{
    for(int i=1;i<n;i++)
        if(ar[i]!=ar[0])
            return 0;
    return 1;
}

int a(int ar[],int n,int k, long long sum)
{
    int count=0,index=0;
    long long tmp;
    while(index!=n)
    {
        tmp=0;
        while(tmp<sum && index<n)
            tmp+=ar[index++];
        if(tmp!=sum)
            return 0;
        count++;
    }
    if(count==k)
        return 1;
    else
        return 0;
}

int main()
{
    int t,n,k;
    long long sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        sum=0;
        bool res[n]{};
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
            sum+=ar[i];
        }
        res[0]=1;
        res[n-1]=check(ar,n);
        for(int k=2;k<n;k++)
        {
            if(sum%k!=0)
                res[k-1]=0;
            else
                res[k-1]=a(ar,n,k,sum/k);
        }
        for(int i=0;i<n;i++)
            cout<<res[i];
        cout<<endl;
    }
    return 0;
}
