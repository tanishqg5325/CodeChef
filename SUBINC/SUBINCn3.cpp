#include <iostream>

using namespace std;

int check(int ar[], int start, int end)
{
    for(int i=start;i<end;i++)
        if(ar[i]>ar[i+1])
            return 0;
    return 1;
}

int main()
{
    int t,n;
    long long count;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)
            cin>>ar[i];
        count=n;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=n-i;j++)
            {
                if(check(ar,j,j+i-1))
                    count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
