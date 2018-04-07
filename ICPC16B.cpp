#include <bits/stdc++.h>

using namespace std;

int search(int ar[], int n, int k)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(ar[mid]==k)
            return 1;
        else if(ar[mid]<k)
            low=mid+1;
        else
            high=mid-1;
    }
    return 0;
}

int check(int ar[],int n)
{
    if(n==1)
        return 1;
    if((ar[0]<-1 && ar[1]<-1) || (ar[n-1]>1 && ar[n-2]>1) || (ar[0]<-1 && ar[n-1]>1))
        return 0;
    if(ar[n-1]>1)
    {
        if(search(ar,n,-1))
            return 0;
        else
            return 1;
    }
    if(ar[0]<-1)
    {
        if(search(ar,n,-1))
            return 0;
        else
            return 1;
    }
    if(!search(ar,n,-1))
        return 1;
    if(search(ar,n,-1) && search(ar,n,1))
        return 1;
    if(search(ar,n,-1) && !search(ar,n,0) && !search(ar,n,1))
        return 0;
    if(ar[1]==0)
        return 1;
    else
        return 0;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)
            cin>>ar[i];
        sort(ar,ar+n);
        if(check(ar,n))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
