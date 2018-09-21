#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool ans(int n, int m, int x, int y)
{
    n--; m--;
    if(n%x == 0 && m%y == 0) return 1;
    if(n == 0) return (m%y == 0);
    if(m == 0) return (n%x == 0);
    n--; m--;
    if(n%x == 0 && m%y == 0) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,m,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x>>y;
        if(ans(n,m,x,y)) cout<<"Chefirnemo\n";
        else cout<<"Pofik\n";
    }
    return 0;
}
