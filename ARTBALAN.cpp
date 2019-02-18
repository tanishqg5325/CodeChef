#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T,n; string str; cin>>T;
    while(T--)
    {
        cin>>str; n = str.size();
        int freq[26]{}, ans = n;
        for(int i=0;i<n;i++) freq[str[i] - 'A']++;
        int temp[26];
        for(int i=1;i<=26;i++)
        {
            if(n % i) continue;
            for(int j=0;j<26;j++) temp[j] = n/i - freq[j];
            sort(temp, temp + 26);
            int a = 0;
            for(int j=0;j<i;j++) if(temp[j] > 0) a += temp[j];
            ans = min(ans, a);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
