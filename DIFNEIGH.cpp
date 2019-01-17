#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,m,k,l;
    cin>>T;
    while(T--)
    {
        cin>>n>>m; k = 1;
        int ar[n][m];
        if(n>=3 && m>=3)
        {
            k = 4;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                {
                    if(i%4 == 0)
                    {
                        if(j%4 == 0 || j%4 == 1) ar[i][j] = 1;
                        else ar[i][j] = 2;
                    }
                    else if(i%4 == 1)
                    {
                        if(j%4 == 0 || j%4 == 1) ar[i][j] = 3;
                        else ar[i][j] = 4;
                    }
                    else if(i%4 == 2)
                    {
                        if(j%4 == 0 || j%4 == 1) ar[i][j] = 2;
                        else ar[i][j] = 1;
                    }
                    else
                    {
                        if(j%4 == 0 || j%4 == 1) ar[i][j] = 4;
                        else ar[i][j] = 3;
                    }
                }
        }
        else if(n == 1)
        {
            for(int i=0;i<m;i++)
            {
                if(i % 4 == 0 || i % 4 == 1) ar[0][i] = 1;
                else ar[0][i] = 2;
            }
            if(m > 2) k = 2;
            else k = 1;
        }
        else if(m == 1)
        {
            for(int i=0;i<n;i++)
            {
                if(i % 4 == 0 || i % 4 == 1) ar[i][0] = 1;
                else ar[i][0] = 2;
            }
            if(n > 2) k = 2;
            else k = 1;
        }
        else if(n == 2 && m == 2) {k = 2; ar[0][0] = ar[0][1] = 1; ar[1][0] = ar[1][1] = 2;}
        else if(n == 2)
        {
            k = 3;
            for(int i=0;i<m;i++)
            {
                if(i % 6 == 0 || i%6 == 1) ar[0][i] = 1;
                else if(i%6 == 2 || i%6 == 3) ar[0][i] = 2;
                else ar[0][i] = 3;
            }
            for(int i=0;i<m;i++)
            {
                if(i % 6 == 3 || i%6 == 4) ar[1][i] = 1;
                else if(i%6 == 0 || i%6 == 5) ar[1][i] = 2;
                else ar[1][i] = 3;
            }
        }
        else if(m == 2)
        {
            k = 3;
            for(int i=0;i<n;i++)
            {
                if(i % 6 == 0 || i%6 == 1) ar[i][0] = 1;
                else if(i%6 == 2 || i%6 == 3) ar[i][0] = 2;
                else ar[i][0] = 3;
            }
            for(int i=0;i<n;i++)
            {
                if(i % 6 == 3 || i%6 == 4) ar[i][1] = 1;
                else if(i%6 == 0 || i%6 == 5) ar[i][1] = 2;
                else ar[i][1] = 3;
            }
        }
        cout<<k<<"\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cout<<ar[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
