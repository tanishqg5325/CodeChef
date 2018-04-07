#include <iostream>

using namespace std;

int sum(int d,int n)
{
    int temp=n;
    for(int i=0;i<d;i++)
        temp=temp*(temp+1)/2;
    return temp;
}

int main()
{
    int t,d,n;
    cin>>t;
    while(t--)
    {
        cin>>d>>n;
        cout<<sum(d,n)<<endl;
    }
    return 0;
}
