#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,m; char ch;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        bool ar[n][m]{}; bool flag=0; bool row[n]{},col[m]{};
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>ch;
                if(ch == '1') ar[i][j]=flag=row[i]=col[j]=1;
            }
        if(!flag)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++) cout<<"-1 ";
                cout<<"\n";
            }
            continue;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ar[i][j]) cout<<"0 ";
                else
                {
                    if(row[i] || col[j]) cout<<"1 ";
                    else cout<<"2 ";
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}
