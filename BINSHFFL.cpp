#include <iostream>
#define ll long long
using namespace std;

int count1(ll x)
{
    int count=0;
    while(x){if(x%2) count++; x/=2;}
    return count;
}

int ans(ll a, ll b)
{
    if(a==b) return 0;
    if(b==0) return -1;
    if(b==1){if(a==0) return 1; else return -1;}
    if(b==(a+1)) return 1;
    int t1=count1(a),t2=count1(b-1);
    if(t1==t2) return 1;
    if(t1>t2) return 2;
    else return (1+t2-t1);
}

int main()
{
    int t; ll a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<ans(a,b)<<endl;
    }
    return 0;
}
