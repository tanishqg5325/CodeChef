#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,q,l,r,c,ans,maxl=0;
    char p;
    cin>>n;
    string str[n];
    getline(cin,str[0]);
    for(int i=0;i<n;i++) {getline(cin,str[i]); maxl=max(maxl,(int)str[i].size());}
    int ar[26*maxl][n];
    for(int j=0;j<(26*maxl); j++) ar[j][0] = 0;
    for(int i=0;i<n;i++)
    {
        if(i>0) {for(int j=0;j<(26*maxl);j++) ar[j][i] = ar[j][i-1];}
        l = str[i].size();
        for(int j=0;j<l;j++)
        {
            if(str[i][j]>='a' && str[i][j]<='z')
            {
                int index = 26*j + str[i][j] - 'a';
                ar[index][i]++;
            }
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>l>>r>>c>>p;
        ans=0;
        l--; r--; c--;
        int index = c*26 + p - 'a';
        if(index>=0 && index<(26*maxl))
        {
            if(l>0)
                ans = ar[index][r] - ar[index][l-1];
            else
                ans = ar[index][r];
        }
        cout<<ans<<endl;
    }
    return 0;
}
