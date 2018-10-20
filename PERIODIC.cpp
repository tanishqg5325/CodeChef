#include <bits/stdc++.h>
using namespace std;

bool isInf(int ar[], int n)
{
    int i = 0;
    while(i<n && ar[i] == -1) i++;
    if(i == n) return 1;
    for(int j=i+1;j<n;j++)
        if(ar[j] != -1 && ar[j] != (ar[i]+j-i))
            return 0;
    return 1;
}

unordered_set<int> intersection(unordered_set<int> &h1, unordered_set<int> &h2)
{
    unordered_set<int> h;
    for (auto i = h2.begin(); i != h2.end(); i++) if (h1.find(*i) != h1.end()) h.insert(*i);
    return h;
}

int check(int ar[], int n)
{
    int i = 0;
    while(i<n && ar[i] == -1) i++;
    int minp = ar[i],j;
    for(int j=i+1;j<n;j++) if(ar[j] > minp) minp = ar[j];

    unordered_set<int> hm; bool first = true;
    while(i<n)
    {
        for(j=i+1;j<n;j++)
        {
            if(ar[j] == -1 || ar[j] == (ar[i]+j-i)) continue;
            break;
        }
        if(j == n) break;
        if(ar[j] > j-i) return -1;
        int p = ar[i]-ar[j]+j-i;
        if(p<minp) return -1;
        if(first)
        {
            hm.insert(p);
            for(int k = minp; k <= p/2; k++) if(p%k == 0) hm.insert(k);
            first = 0;
        }
        else
        {
            unordered_set<int> h; h.insert(p);
            for(int k = minp; k <= p/2; k++) if(p%k == 0) h.insert(k);
            hm = intersection(hm,h);
        }
        if(hm.size() == 0) return -1;
        i = j;
    }
    int maxi = 1;
    for (auto i = hm.begin(); i != hm.end(); i++) if (*i > maxi) maxi = *i;
    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n; int ar[n]; for(int i=0;i<n;i++) cin>>ar[i];
        if(isInf(ar,n)) {cout<<"inf\n"; continue;}
        k = check(ar,n);
        if(k == -1) cout<<"impossible\n";
        else cout<<k<<"\n";
    }
    return 0;
}
