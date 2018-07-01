#include <iostream>
using namespace std;
int ans;
void heapPermutation(int a[], int size, int n, int q[], int k)
{
    if (size == 1)
    {
        for(int i=0;i<n;i++)
        {
            if(q[i]!=0 && q[i]!=a[i])
                return;
        }
        int count = 0;
        for(int i=1;i<n;i++)
            if(a[i]>a[i-1])
                count++;
        if(count == k)
            ans++;
        return;
    }
    for (int i=0; i<size; i++)
    {
        heapPermutation(a,size-1,n,q,k);
        if (size%2==1)
            swap(a[0], a[size-1]);
        else
            swap(a[i], a[size-1]);
    }
}

int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int tmp[n];
        for(int i=0;i<n;i++)
            tmp[i]=i+1;
        ans=0;
        heapPermutation(tmp, n, n, a, k);
        cout<<ans<<endl;
    }
    return 0;
}
