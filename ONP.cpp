#include <iostream>
#include <ctype.h>

using namespace std;

int check(char c)
{
    if (c=='(' || c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return 1;
    return 0;
}

int main()
{
    int t,n,top,k;
    char str[400],ans[400],temp[400];
    cin>>t;
    t++;
    while(t--)
    {
        cin.getline(str,400);
        k=top=0;
        for(int i=0;str[i]!='\0';i++)
        {
            if(check(str[i]))
                temp[top++]=str[i];
            else if(isalpha(str[i]))
                ans[k++]=str[i];
            else if(str[i]==')')
            {
                ans[k++]=temp[top-1];
                top-=2;
            }
        }
        ans[k]='\0';
        cout.write(ans,k);
        cout<<endl;
    }
    return 0;
}
