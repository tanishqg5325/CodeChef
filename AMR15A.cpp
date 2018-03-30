#include <iostream>

using namespace std;

int main()
{
    int n,t,a,count=0;
    cin>>n;
    t=n;
    while(t--)
    {
        cin>>a;
        if(a%2==0)
            count++;
    }
    if(2*count>n)
        cout<<"READY FOR BATTLE"<<endl;
    else
        cout<<"NOT READY"<<endl;
    return 0;
}

