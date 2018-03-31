#include  <iostream>

using namespace std;

int main()
{
    int t,n,flag;
    char c[1001];
    cin>>t;
    while(t--)
    {
        cin>>n;
        flag=0;
        for(int i=0;i<n;i++)
            cin>>c[i];
        for(int i=0;i<n;i++)
        {
            if(c[i]=='Y')
                flag=1;
            else if(c[i]=='I')
                flag=2;
            if(flag!=0)
                break;
        }

        if(flag==1)
            cout<<"NOT INDIAN"<<endl;
        else if(flag==2)
            cout<<"INDIAN"<<endl;
        else
            cout<<"NOT SURE"<<endl;
    }
    return 0;
}
