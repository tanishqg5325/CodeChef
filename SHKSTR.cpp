#include <bits/stdc++.h>
#include <string>
using namespace std;

struct node{
    int value;
    node* next;
};

int main()
{
    int n,q,r,l,index,min=0;
    cin>>n;
    string str[n],ans,p;
    getline(cin,ans);
    for(int i=0;i<n;i++) getline(cin,str[i]);
    unordered_map<string, node*> prefix;
    for(int i=0;i<n;i++)
    {
        if(str[i]<str[min]) min=i;
        l=str[i].size();
        for(int j=0;j<=l;j++)
        {
            string sub = str[i].substr(0,j);
            if(prefix.find(sub) == prefix.end())
            {
                node* temp = new node;
                temp->value = i;
                temp->next = NULL;
                prefix[sub] = temp;
            }
            else if(str[i]<str[prefix[sub]->value])
            {
                node* temp = new node;
                temp->value = i;
                temp->next = prefix[sub];
                prefix[sub] = temp;
            }
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>r;
        getline(cin,p);
        p.erase(0,1);
        l = p.size();
        index=min;
        for(int j=l;j>=0;j--)
        {
            string sub = p.substr(0,j);
            if(prefix.find(sub) == prefix.end()) continue;
            node* temp = prefix[sub];
            while(temp!=NULL && (temp->value)>=r)
                temp=temp->next;
            if(temp!=NULL)
            {
                index = temp->value;
                break;
            }
        }
        cout<<str[index]<<endl;
    }
    return 0;
}
