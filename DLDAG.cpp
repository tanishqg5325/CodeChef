#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct node1
{
    int v,in,out;
};

struct node1_compare
{
    bool operator() (const node1 &n1, const node1 &n2) const
    {
        if(n1.out != n2.out) return n1.out < n2.out;
        if(n1.in != n2.in) return n1.in > n2.in;
        return n1.v < n2.v;
    }
};

struct node2
{
    int v,count_zero_childs,sum_child_in_deg;
    set<node1,node1_compare> zero_childs;
};

struct node2_compare
{
    bool operator() (const node2 &n1, const node2 &n2) const
    {
        if(n1.count_zero_childs != n2.count_zero_childs)
            return n1.count_zero_childs > n2.count_zero_childs;
        if(n1.sum_child_in_deg != n2.sum_child_in_deg)
            return n1.sum_child_in_deg > n2.sum_child_in_deg;
        return n1.v < n2.v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,u,v; cin>>n>>m;
    vector<int> rev[n];
    node1 ver[n]; node2 childs[n];
    for(int i=0;i<n;i++)
    {
        ver[i].v = i; ver[i].in = ver[i].out = 0;
        childs[i].v = i; childs[i].count_zero_childs = 0; childs[i].sum_child_in_deg = 0;
    }
    while(m--)
    {
        cin>>u>>v; u--; v--;
        rev[v].pb(u);
        ver[u].out++; ver[v].in++;
    }
    for(int i=0;i<n;i++)
        if(ver[i].out == 0)
            for(vector<int>::iterator j = rev[i].begin(); j != rev[i].end(); j++)
            {
                childs[*j].count_zero_childs++;
                childs[*j].sum_child_in_deg += ver[i].in;
                childs[*j].zero_childs.insert(ver[i]);
            }
    set<node1, node1_compare> ver_set(ver, ver+n);
    set<node2, node2_compare> parents;
    for(int i=0;i<n;i++)
    {
        if(ver[i].out != 0 && childs[i].count_zero_childs == ver[i].out)
            parents.insert(childs[i]);
    }

    int non_zero_childs[n];
    for(int i=0;i<n;i++) non_zero_childs[i] = ver[i].out - childs[i].count_zero_childs;

    vector<int> ans[n]; int k=0, first, second;
    set<node2>::iterator i; set<node1>::iterator j;

    while(!ver_set.empty())
    {
        first = second = -1;
        if(!parents.empty())
        {
            i = parents.begin(); int p = (*i).v;
            j = childs[p].zero_childs.begin(); first = (*j).v;
            if(childs[p].count_zero_childs >= 2) second = (*next(j)).v;
            else
            {
                while(i != parents.end() && (*i).count_zero_childs == 1 && (*(*i).zero_childs.begin()).v == first) i++;
                if(i != parents.end())
                {
                    p = (*i).v; j = childs[p].zero_childs.begin();
                    if((*j).v == first) second = (*next(j)).v;
                    else second = (*j).v;
                }
                else
                {
                    j = ver_set.begin();
                    if((*j).v != first) second = (*j).v;
                    else if(next(j) != ver_set.end() && (*next(j)).out == 0) second = (*next(j)).v;
                }
            }
        }
        else
        {
            j = ver_set.begin(); first = (*j).v; j = next(j);
            if(j != ver_set.end() && (*j).out == 0) second = (*j).v;
        }
        ans[k].pb(first + 1); if(second != -1) ans[k].pb(second + 1); k++;
rep:
        ver_set.erase(ver_set.find(ver[first]));
        for(vector<int>::iterator c = rev[first].begin(); c != rev[first].end(); c++)
        {
            ver_set.erase(ver_set.find(ver[*c]));
            ver[*c].out--; ver_set.insert(ver[*c]);
            i = parents.find(childs[*c]);
            if(i == parents.end())
            {
                childs[*c].count_zero_childs--;
                childs[*c].sum_child_in_deg -= ver[first].in;
                childs[*c].zero_childs.erase(childs[*c].zero_childs.find(ver[first]));
            }
            else
            {
                parents.erase(i);
                childs[*c].count_zero_childs--;
                childs[*c].sum_child_in_deg -= ver[first].in;
                if(childs[*c].count_zero_childs)
                {
                    childs[*c].zero_childs.erase(childs[*c].zero_childs.find(ver[first]));
                    parents.insert(childs[*c]);
                }
                else
                {
                    for(vector<int>::iterator c2 = rev[*c].begin(); c2 != rev[*c].end(); c2++)
                    {
                        non_zero_childs[*c2]--;
                        childs[*c2].count_zero_childs++;
                        childs[*c2].sum_child_in_deg += ver[*c].in;
                        childs[*c2].zero_childs.insert(ver[*c]);
                        if(non_zero_childs[*c2] == 0) parents.insert(childs[*c2]);
                    }
                }
            }
        }
        if(second != -1)
        {
            first = second;
            second = -1;
            goto rep;
        }
    }
    cout<<k<<"\n";
    for(int i=0;i<k;i++)
    {
        int l = ans[i].size();
        cout<<l<<" ";
        for(int j=0;j<l;j++) cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
