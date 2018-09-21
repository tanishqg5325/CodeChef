#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct node
{
    int ranku, c;
    node *p;
};

void linku(node *a, node *b)
{
    if(a->ranku >= b->ranku) {b->p = a; a->c = min(a->c,b->c); }
    else {a->p = b; b->c = min(a->c,b->c); return;}
    if(a->ranku == b->ranku) a->ranku++;
}

node* findu(node *n)
{
    if(n != n->p) n->p = findu(n->p);
    return n->p;
}

void unionu(node *a, node *b)
{
    linku(findu(a),findu(b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,c;
    cin>>n>>m;
    int a[m],b[m]; node planet[n];
    for(int i=0;i<n;i++) { planet[i].p = &planet[i]; planet[i].ranku = 0; planet[i].c = 10001;}
    for(int i=0;i<m;i++) cin>>a[i]>>b[i];
    for(int i=0;i<n;i++)
    {
        cin>>c;
        if(c>=0) planet[i].c = c;
    }
    for(int i=0;i<m;i++) unionu(&planet[a[i]-1], &planet[b[i]-1]);
    int k=0, mincost=10001, sum=0; bool flag=0;
    for(int i=0;i<n;i++)
        if(planet[i].p == &planet[i])
        {
            if(planet[i].c == 10001) flag=1;
            mincost = min(mincost, planet[i].c);
            k++; sum += planet[i].c;
        }
    if(k == 1) cout<<"0\n";
    else if(flag) cout<<"-1\n";
    else cout<<(k-2)*mincost+sum<<"\n";
    return 0;
}
