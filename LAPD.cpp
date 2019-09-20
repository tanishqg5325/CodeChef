#include <iostream>
using namespace std;
typedef long long ll;

ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,st,en,st1,en1,j,x,y,t1,t2,A,B,C,BB; ll ans,cnt;
    cin>>T; ll tmp[5000]{};
    for(j=1;j<5000;j++)
        {
            st = j*j+1; en = (j+1)*(j+1); cnt = 0;
            t1 = j+1; t2 = j+1;
            for(x=1;x<=t1;x++)
            {
                st1 = (st+x-1)/x; if(st1 < 1) st1 = 1;
                en1 = en/x;
                if(en1 >= st1) cnt += en1-st1+1;
            } t1++;
            for(y=1;y<=t2;y++)
            {
                st1 = (st+y-1)/y; if(st1 < t1) st1 = t1;
                en1 = en/y;
                if(en1 >= st1) cnt += en1-st1+1;
            }
            tmp[j] = (tmp[j-1] + j * cnt) % mod;
        }
    while(T--)
    {
        cin>>A>>B>>C; ans = 0;
        BB = B*B; A--; C--;
        if(A >= BB && C >= BB)
        {
            ans = tmp[B-1]; cnt = 0;
            for(x=BB;x>=1;x--)
            {
                t2 = C-BB/x;
                if(t2 > 0) cnt += t2;
                else break;
            }
            if(A > BB) cnt = (cnt + (ll)C * (A-BB)) % mod;
            ans = (ans + B * cnt) % mod;
            cout<<ans<<"\n"; continue;
        }
        for(j=1;j<B;j++)
        {
            st = j*j+1; en = (j+1)*(j+1); cnt = 0;
            t1 = min(A, j+1); t2 = min(C, j+1);
            for(x=1;x<=t1;x++)
            {
                st1 = (st+x-1)/x; if(st1 < 1) st1 = 1;
                en1 = en/x; if(en1 > C) en1 = C;
                if(en1 >= st1) cnt += en1-st1+1;
            } t1++;
            for(y=1;y<=t2;y++)
            {
                st1 = (st+y-1)/y; if(st1 < t1) st1 = t1;
                en1 = en/y; if(en1 > A) en1 = A;
                if(en1 >= st1) cnt += en1-st1+1;
            }
            ans += j * cnt;
        }
        cnt = 0; t1 = min(A, BB);
        for(x=t1;x>=1;x--)
        {
            t2 = C-BB/x;
            if(t2 > 0) cnt += t2;
            else break;
        }
        if(A > BB) cnt = (cnt + (ll)C * (A-BB)) % mod;
        ans = (ans + B * cnt) % mod;
        cout<<ans<<"\n";
    }
    return 0;
}
