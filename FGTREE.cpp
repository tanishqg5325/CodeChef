#include <bits/stdc++.h>
using namespace std;

bool ask(int x, int a, int b)
{
    string str;
    cout<<"Q "<<x<<" "<<a<<" "<<b<<endl;
    cin>>str;
    if(str[0] == 'Y') return 1; return 0;
}

void f(int l, int r, int pa[], int par)
{
    if(l > r) return;
    if(l == r) {pa[l] = par; return;}
    vector<int> v; for(int i=l;i<=r;i++) v.push_back(i);
    unsigned seed = 435; shuffle(v.begin(), v.end(), default_random_engine(seed));
    int i; for(int j : v) if(ask(j, l, r)) {i = j; break;}
    pa[i] = par;
    f(l, i-1, pa, i);
    f(i+1, r, pa, i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n; cin>>T;
    while(T--)
    {
        cin>>n; int pa[n+1];
        f(1, n, pa, -1);
        cout<<"A "; for(int i=1;i<=n;i++) cout<<pa[i]<<" "; cout<<endl;
    }
    return 0;
}
