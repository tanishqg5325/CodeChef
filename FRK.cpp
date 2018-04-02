#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n,count=0,t;
    char str[21];
    cin>>n;
    cin.getline(str,21);
    while(n--)
    {
        cin.getline(str,21);
        t=strlen(str);
        for(int i=0;i<t-1;i++)
            if((str[i]=='c'&& str[i+1]=='h') || (str[i]=='h' && str[i+1]=='e') || (str[i]=='e' && str[i+1]=='f'))
            {
                count++;
                break;
            }
    }
    cout<<count<<endl;
    return 0;
}
