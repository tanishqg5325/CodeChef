#include <iostream>

using namespace std;

int main()
{
    int n,a;
    cin>>n;
    int ar[n+1]{};
    for(int i=0;i<n;i++)
    {
        cin>>a;
        ar[a]++;
    }
    for(int i=0;i<n+1;i++)
        if(!ar[i])
            cout<<i<<" ";
    return 0;
}
