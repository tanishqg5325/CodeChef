#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef long long ll;
using namespace std;

ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,r,R; cin>>n>>r;
    while(n--)
    {
        cin>>R;
        if(R >= r) cout<<"Good boi\n";
        else cout<<"Bad boi\n";
    }
    return 0;
}
