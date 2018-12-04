#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans,mini,t=1,sum,cost1,cost2;
    cin>>n;
    while(n)
    {
        int ar[n+1],sr[n+1]; int pos[1000];
        for(int i=1;i<=n;i++) cin>>ar[i], sr[i] = ar[i], pos[ar[i]] = i;
        sort(sr+1,sr+n+1); ans = 0;
        bool visited[n+1]{};
        for(int i=1;i<=n;i++)
        {
            if(visited[i]) continue;
            int j = i,k=1; sum = ar[j]; mini = ar[j]; visited[j] = 1;
            while(sr[j] != ar[i])
            {
                j = pos[sr[j]];
                k++;
                sum += ar[j];
                visited[j] = 1;
                mini = min(mini, ar[j]);
            }
            sum -= mini;
            cost1 = sum+(k-1)*mini;
            cost2 = 2*(sr[1]+mini) + sum + sr[1]*(k-1);
            ans += min(cost1,cost2);
        }
        cout<<"Case "<<t<<": "<<ans<<"\n\n";
        t++;
        cin>>n;
    }
}
