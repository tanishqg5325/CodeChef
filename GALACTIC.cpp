#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct node
{
    int rank, c;
    int p;
};

node planet[100000];

void linku(int a, int b)
{
    if(a == b) return;
    if(planet[a].rank >= planet[b].rank)
    {
        planet[b].p = a;
        planet[a].c = min(planet[a].c, planet[b].c);
    }
    else
    {
        planet[a].p = b;
        planet[b].c = min(planet[a].c, planet[b].c);
        return;
    }
    if(planet[a].rank == planet[b].rank) planet[a].rank++;
}

int findu(int n)
{
    if(n != planet[n].p) planet[n].p = findu(planet[n].p);
    return planet[n].p;
}

void unionu(int a, int b)
{
    linku(findu(a), findu(b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,c;
    cin>>n>>m;
    int a[m],b[m];
    for(int i=0;i<n;i++) { planet[i].p = i; planet[i].rank = 0; planet[i].c = 10001;}
    for(int i=0;i<m;i++) cin>>a[i]>>b[i];
    for(int i=0;i<n;i++)
    {
        cin>>c;
        if(c>=0) planet[i].c = c;
    }
    for(int i=0;i<m;i++) unionu(a[i]-1, b[i]-1);
    int k=0, mincost=10001, sum=0; bool flag=0;
    for(int i=0;i<n;i++)
        if(planet[i].p == i)
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
