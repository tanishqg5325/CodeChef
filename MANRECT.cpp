#include <bits/stdc++.h>
using namespace std;

int ask(int x, int y)
{
    int ans; cout<<"Q "<<x<<" "<<y<<endl; cin>>ans; return ans;
}

const int maxn = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n,xl,yl,xu,yu; cin>>T; int ver;
    while(T--)
    {
        int a = ask(0, 0);
        int b = 2*maxn - ask(maxn, maxn);
        int c = maxn - ask(maxn, 0);
        yl = ask((a+c)/2, 0);
        xl = a - yl; xu = c + yl; yu = b - xu;
        cout<<"A "<<xl<<" "<<yl<<" "<<xu<<" "<<yu<<endl;
        cin>>ver;
        if(ver != 1) break;
    }
    return 0;
}
