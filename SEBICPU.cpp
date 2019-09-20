#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ll;

vector<string> ans;

void f(ll num, string reg) {
    vector<int> v;
    while(num) {
        v.pb(num & 1);
        num >>= 1;
    }
    if(v.empty()) return;
    reverse(v.begin(), v.end());
    if(v[0]) ans.pb("inc " + reg);
    for(int i=1;i<v.size();i++) {
        ans.pb("shl " + reg + " rdx");
        if(v[i]) ans.pb("inc " + reg);
    }
}

int main()
{
    int n; cin>>n;
    ll a[n],b[n],c[n],s; bool flag = 1;
    for(int i=0;i<n;i++) {
        cin>>a[i]>>b[i]>>c[i];
        if(flag && i && s != a[i] + b[i] + c[i]) flag = 0;
        else if(i == 0) s = a[i] + b[i] + c[i];
    }
    if(flag == 0) {
        ans.pb("inc rdx");
        for(int i=0;i<n;i++) {
            f(a[i], "rax"); f(b[i], "rbx"); f(c[i], "rcx");
            ans.pb("sub rax rax");
            ans.pb("sub rbx rbx");
            ans.pb("sub rcx rcx");
        }
        for(int i=0;i<3;i++) ans.pop_back();
    }
    else {
        ans.pb("inc rdx");
        f(s, "rcx");
        for(int i=0;i<n;i++) {
            f(a[i], "rax"); f(b[i], "rbx");
            ans.pb("mov rdx rcx");
            ans.pb("sub rcx rax");
            ans.pb("sub rcx rbx");
            ans.pb("sub rax rax");
            ans.pb("sub rbx rbx");
            ans.pb("mov rcx rdx");
            ans.pb("sub rdx rdx");
            ans.pb("inc rdx");
        }
        for(int i=0;i<5;i++) ans.pop_back();
    }
    n = ans.size();
    cout<<n<<"\n";
    for(int i=0;i<n;i++) cout<<ans[i]<<"\n";
    return 0;
}
