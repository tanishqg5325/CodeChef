#include <iostream>
using namespace std;

void fastscan(int &n)
{
    register int c;
    n=0;
    c=getchar();
    for (;(c>47 && c<58);c=getchar())
        n=n*10+c-48;
}

int search(int q[], int l, int r, int x)
{
    if(x>=q[l])
        return l;
    if(x<q[r])
        return r+1;
    int m;
    while(r!=l+1)
    {
        m=(l+r)/2;
        if(q[m]<=x)
            r=m;
        else
            l=m;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,i; bool flag;
    fastscan(t);
    while(t--)
    {
        fastscan(n);
        int a[n],b[n];
        for(int i=0;i<n;i++) fastscan(a[i]);
        flag=1;
        for(i=0;i<n;i++)
        {
            fastscan(b[i]);
            if(flag && b[i]>a[i]) flag=0;
        }
        if(flag)
        {
            int cuts,start=0,end=-1,q[n];bool flag[n];
            if(b[n-1]==a[n-1]){cuts=flag[0]=0;} else {cuts=flag[0]=1;} q[++end]=b[n-1];
            for(int i=n-2;i>=0;i--)
            {
                start=search(q,start,end,a[i]);
                if(b[i]==b[i+1])
                {
                    if(!flag[end] && b[i]!=a[i]){flag[end]=1;cuts++;}
                }
                else if(b[i]<b[i+1])
                {
                    q[++end]=b[i];
                    if(b[i]==a[i]){flag[end]=0;} else {flag[end]=1;cuts++;}
                }
                else
                {
                    end=search(q,start,end,b[i]);
                    if(q[end]==b[i])
                    {
                        if(!flag[end] && b[i]!=a[i]){flag[end]=1;cuts++;}
                    }
                    else
                    {
                        q[end]=b[i];
                        if(b[i]==a[i])flag[end]=0;
                        else{flag[end]=1;cuts++;}
                    }
                }
            }
            cout<<cuts<<"\n";
        }
        else
            cout<<-1<<"\n";
    }
    return 0;
}
