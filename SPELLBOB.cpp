#include <bits/stdc++.h>
using namespace std;

bool ans(string str1, string str2)
{
    if((str1[0] == 'b' || str2[0] == 'b') && (str1[1] == 'b' || str2[1] == 'b') && (str1[2] == 'o' || str2[2] == 'o'))
        return true;
    if((str1[0] == 'b' || str2[0] == 'b') && (str1[1] == 'o' || str2[1] == 'o') && (str1[2] == 'b' || str2[2] == 'b'))
        return true;
    if((str1[0] == 'o' || str2[0] == 'o') && (str1[1] == 'b' || str2[1] == 'b') && (str1[2] == 'b' || str2[2] == 'b'))
        return true;
    return false;
}

int main()
{
    int t; string str1, str2;
    cin>>t;
    while(t--)
    {
        cin>>str1>>str2;
        if(ans(str1, str2)) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
