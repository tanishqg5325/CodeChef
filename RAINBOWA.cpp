#include <iostream>

using namespace std;

int check(int ar[], int n)
{
    if(n<13)
        return 0;
    for(int i=0,j=n-1;i<n/2;i++,j--)
        if(ar[i]!=ar[j])
            return 0;
    int index=0,count;
    for(int i=1;i<7;i++)
    {
        count=0;
        while(ar[index]==i && index<n)
        {
            index++;
            count++;
        }
        if(count==0 || ar[index]!=i+1)
            return 0;
    }
    while(ar[index]==7)
        index++;
    if(ar[index]==6)
        return 1;
    else
        return 0;
}

int main()
{
    int t,n,ar[100];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>ar[i];
        if(check(ar,n))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
