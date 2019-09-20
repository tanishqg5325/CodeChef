#include <bits/stdc++.h>
using namespace std;

int bit[1025][1025];

int find_cf(int x, int y)
{
    int sum = 0;
    for(int idx = x; idx > 0; idx -= (idx & -idx))
        for(int idy = y; idy > 0; idy -= (idy & -idy))
            sum += bit[idx][idy];
    return sum;
}

void update(int x, int y, int val, int MaxIdx)
{
    for(int idx = x; idx <= MaxIdx; idx += (idx & -idx))
        for(int idy = y; idy <= MaxIdx; idy += (idy & -idy))
            bit[idx][idy] += val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,x1,y1,x2,y2; int num; string str; cin>>T;
    while(T--)
    {
        cin>>n; for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) bit[i][j] = 0;
        int ar[n][n]{};
        cin>>str;
        while(str.compare("END"))
        {
            if(!str.compare("SET"))
            {
                cin>>x1>>y1>>num;
                update(x1+1, y1+1, num - ar[x1][y1], n);
                ar[x1][y1] = num;
            }
            else
            {
                cin>>x1>>y1>>x2>>y2;
                cout<<find_cf(x2+1, y2+1) + find_cf(x1, y1) - find_cf(x2+1, y1) - find_cf(x1, y2+1)<<"\n";
            }
            cin>>str;
        }
    }
    return 0;
}
