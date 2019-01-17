#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n; string str;
    cin>>T; getline(cin, str);
    while(T--)
    {
        getline(cin, str); n = str.size();
        bool flag = 0;
        for(int i=0;i<n-2;i++)
            if(str[i] == 'n' && str[i+1] == 'o' && str[i+2] == 't')
            {
                if(i != 0 && str[i-1] != ' ') continue;
                if(i != n-3 && str[i+3] != ' ') continue;
                flag = 1;
                break;
            }
        if(flag) cout<<"Real Fancy\n";
        else cout<<"regularly fancy\n";
    }
    return 0;
}
