#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node* makeTree(int pre[], int in[], int dp[], int pre_start, int pre_end, int in_start, int in_end)
{
    if(pre_start > pre_end) return NULL;
    node *root = new node; root->data = pre[pre_start];
    if(pre_start == pre_end)
    {
        root->left = root->right = NULL;
        return root;
    }
    int ind = dp[pre[pre_start]];
    root->left = makeTree(pre,in,dp,pre_start+1,pre_start+ind-in_start,in_start, ind-1);
    root->right = makeTree(pre,in,dp,pre_start+ind-in_start+1,pre_end,ind+1,in_end);
    return root;
}

void postOrder(node* root, vector<int> &v)
{
    if(root)
    {
        postOrder(root->left, v);
        postOrder(root->right, v);
        v.push_back(root->data);
    }
}

int main()
{
    int n;
    cin>>n;
    int pre[n],post[n],in[n],dp[n+1];
    for(int i=0;i<n;i++) cin>>pre[i];
    for(int i=0;i<n;i++) cin>>post[i];
    for(int i=0;i<n;i++) {cin>>in[i]; dp[in[i]] = i;}
    node * root = makeTree(pre,in,dp,0,n-1,0,n-1);
    vector<int> v;
    postOrder(root,v);
    bool flag=1;
    for(int i=0;i<n;i++)
        if(v[i] != post[i])
        {
            flag=0; break;
        }
    if(flag) cout<<"yes\n";
    else cout<<"no\n";
    return 0;
}
