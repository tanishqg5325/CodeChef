#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int p,s,n;
    cin>>p>>s;
    pair<int,int> prob[p]; pair<int,int> subtask[s];
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<s;j++) cin>>subtask[j].first;
        for(int j=0;j<s;j++) cin>>subtask[j].second;
        sort(subtask, subtask+s);
        n = 0;
        for(int j=0;j<s-1;j++) if(subtask[j].second > subtask[j+1].second) n++;
        prob[i].first = n; prob[i].second = i+1;
    }
    sort(prob, prob+p);
    for(int i=0;i<p;i++) cout<<prob[i].second<<"\n";
    return 0;
}
