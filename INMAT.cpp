#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int ask(int i, int j)
{
    int ans;
    cout<<"1 "<<i<<" "<<j<<"\n"<<flush;
    cin>>ans;
    return ans;
}

void result(int i, int j)
{
    cout<<"2 "<<i<<" "<<j<<"\n"<<flush;
}

int main()
{
    int n,k,i,left,right,mid; ll v,a,b,val;
    cin>>n>>k>>v;
    if(k >= n*n)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(ask(i,j)==v) { result(i,j); return 0;}
        result(-1,-1); return 0;
    }
    for(i=0;i<n;i++)
    {
        a = ask(i+1,1); if(a==v) {result(i+1,1); return 0;}
        mid = (n-1)/2;
        val = ask(i+1, mid +1); if(val==v) {result(i+1,mid+1); return 0;}
        left=0; right=n-1;
        if(a<val)
        {
            if(val>v) right = mid-1;
            else left = mid+1;
            while(left<=right)
            {
                mid = (left+right)/2;
                val = ask(i+1,mid+1);
                if(val == v) {result(i+1,mid+1); return 0;}
                else if(val>v) right = mid-1;
                else left = mid+1;
            }
        }
        else
        {
            if(val>v) left = mid+1;
            else right = mid-1;
            while(left<=right)
            {
                mid = (left+right)/2;
                val = ask(i+1,mid+1);
                if(val == v) {result(i+1,mid+1); return 0;}
                else if(val>v) left = mid+1;
                else right = mid-1;
            }
        }
    }
    result(-1,-1);
    return 0;
}
