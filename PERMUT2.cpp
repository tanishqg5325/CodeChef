#include <iostream>

using namespace std;

int main()
{
    int n,ar[100000],flag;
    cin>>n;
    while(n)
    {
        flag=0;
        for(int i=0;i<n;i++)
            cin>>ar[i];
        for(int i=0;i<n;i++)
            if(ar[ar[i]-1]!=i+1)
                flag=1;
        if(flag==1)
            cout<<"not ambiguous"<<endl;
        else
            cout<<"ambiguous"<<endl;
        cin>>n;
    }
    return 0;
}
