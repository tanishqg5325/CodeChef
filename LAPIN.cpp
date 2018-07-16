#include <iostream>
using namespace std;

int main()
{
    int t,n,flag; string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n = s.size();
        int t1[26]{}; int t2[26]{};
        for(int i=0;i<n/2;i++)
            t1[s[i]-'a']++;
        for(int i=(n+1)/2;i<n;i++)
            t2[s[i]-'a']++;
        flag=1;
        for(int i=0;i<26;i++)
            if(t1[i]!=t2[i])
                flag=0;
        if(flag) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
    return 0;
}
