#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
#define MAXN 1001
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

bool marked[MAXN][MAXN], done[MAXN][MAXN],temp[MAXN][MAXN];
ll weights[MAXN][MAXN],dp[MAXN][MAXN];

void maxPath(int a1,int a2,int b1,int b2,vector<pii> &ans)
{
    dp[a1][a2] = weights[a1][a2];
    for(int j=a1+1;j<=b1;j++) dp[j][a2] = dp[j-1][a2] + weights[j][a2];
    if(a2 <= b2)
    {
        for(int j=a2+1;j<=b2;j++) dp[a1][j] = dp[a1][j-1] + weights[a1][j];
        for(int i=a1+1;i<=b1;i++)
            for(int j=a2+1;j<=b2;j++)
                dp[i][j] = weights[i][j] + max(dp[i-1][j], dp[i][j-1]);
        int i = b1,j = b2;
        while(i != a1 && j != a2)
        {
            temp[i][j] = 1;
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
        while(i != a1) {temp[i][j] = 1; i--;}
        while(j != a2) {temp[i][j] = 1; j--;}
        while(i != b1 && j != b2)
        {
            ans.pb({i,j});
            if(temp[i][j+1]) j++;
            else i++;
        }
        while(i != b1) {ans.pb({i,j}); i++;}
        while(j != b2) {ans.pb({i,j}); j++;}
        ans.pb({b1,b2});
    }
    else
    {
        for(int j=a2-1;j>=b2;j--) dp[a1][j] = dp[a1][j+1] + weights[a1][j];
        for(int i=a1+1;i<=b1;i++)
            for(int j=a2-1;j>=b2;j--)
                dp[i][j] = weights[i][j] + max(dp[i-1][j], dp[i][j+1]);
        int i = b1,j = b2;
        while(i != a1 && j != a2)
        {
            temp[i][j] = 1;
            if(dp[i-1][j] > dp[i][j+1]) i--;
            else j++;
        }
        while(i != a1) {temp[i][j] = 1; i--;}
        while(j != a2) {temp[i][j] = 1; j++;}
        while(i != b1 && j != b2)
        {
            ans.pb({i,j});
            if(temp[i][j-1]) j--;
            else i++;
        }
        while(i != b1) {ans.pb({i,j}); i++;}
        while(j != b2) {ans.pb({i,j}); j--;}
        ans.pb({b1,b2});
    }
}

ll maxPath2(int a1, int a2, int b1, int b2, int n, vector<pii> &ans)
{
    ll temp=0, maxi=0; int ind = max(a2,b2);
    for(int j=max(a2,b2)+1;j<=n;j++)
    {
        temp += weights[a1][j] + weights[b1][j];
        if(temp > maxi) {maxi = temp; ind = j;}
    }
    ll score = 0;
    for(int j=a2;j<=ind;j++) ans.pb({a1,j}), score += weights[a1][j];
    for(int j=ind;j>=b2;j--) ans.pb({b1,j}), score += weights[b1][j];
    return score;
}

ll maxPath3(int a1, int a2, int b1, int b2, vector<pii> &ans)
{
    ll temp=0, maxi=0; int ind = min(a2,b2);
    for(int j=min(a2,b2)-1;j>=1;j--)
    {
        temp += weights[a1][j] + weights[b1][j];
        if(temp > maxi) {maxi = temp; ind = j;}
    }
    ll score = 0;
    for(int j=a2;j>=ind;j--) ans.pb({a1,j}), score += weights[a1][j];
    for(int j=ind;j<=b2;j++) ans.pb({b1,j}), score += weights[b1][j];
    return score;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m,x,y,k=0,l,start,endd,extra; bool right=1,travel;
    cin>>n>>m;
    vector<int> mar1[n+1]; vector<pii> ans[m];
    for(int i=0;i<2*m;i++)
    {
        cin>>x>>y;
        marked[x][y] = 1;
    }

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>weights[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(marked[i][j]) mar1[i].pb(j);

    for(int i=1;i<=n;i++)
    {
        if(mar1[i].empty()) continue;
        l = mar1[i].size(); extra = 0; travel = 0;
        if(right)
        {
            if(done[i][mar1[i][0]])
            {
                if(l == 1) start = 2, endd = 1;
                else {start = mar1[i][1]; if(l & 1) endd = mar1[i][l-1]; else endd = mar1[i][l-2], extra = mar1[i][l-1];}
            }
            else
            {
                if(l == 1) start = 2, endd = 1, extra = mar1[i][0];
                else {start = mar1[i][0]; if(l & 1) endd = mar1[i][l-2], extra = mar1[i][l-1]; else endd = mar1[i][l-1];}
            }
            for(int j=start;j<=endd;j++)
            {
                if(travel || marked[i][j]) ans[k].pb({i,j});
                if(!travel && marked[i][j]) travel = 1;
                else if(travel && marked[i][j]) {k++; travel = 0;}
            }
            if(!extra) continue;
            if(!mar1[i+1].empty())
            {
                right = 0;
                int l1 = mar1[i+1].size();
                done[i+1][mar1[i+1][l1-1]] = 1;
                vector<pii> v1,v2;
                if(l1 == 1 && l == 1)
                {
                    ll score1 = maxPath2(i,extra,i+1,mar1[i+1][l1-1],n,v1);
                    ll score2 = maxPath3(i,extra,i+1,mar1[i+1][l1-1],v2);
                    if(score1 > score2) ans[k] = v1;
                    else ans[k] = v2;
                }
                else maxPath2(i,extra,i+1,mar1[i+1][l1-1],n,ans[k]);
            }
            else
            {
                int j = i+2;
                while(mar1[j].empty()) j++;
                ans[k].pb({i,extra});
                maxPath(i+1,extra,j-1,mar1[j][0],ans[k]);
                ans[k].pb({j,mar1[j][0]});
                done[j][mar1[j][0]] = 1;
            }
            k++;
        }
        else
        {
            if(done[i][mar1[i][l-1]])
            {
                if(l == 1) start = 1, endd = 2;
                else {start = mar1[i][l-2]; if(l & 1) endd = mar1[i][0]; else endd = mar1[i][1], extra = mar1[i][0];}
            }
            else
            {
                if(l == 1) start = 1, endd = 2, extra = mar1[i][0];
                else {start = mar1[i][l-1]; if(l & 1) endd = mar1[i][1], extra = mar1[i][0]; else endd = mar1[i][0];}
            }
            for(int j=start;j>=endd;j--)
            {
                if(travel || marked[i][j]) ans[k].pb({i,j});
                if(!travel && marked[i][j]) travel = 1;
                else if(travel && marked[i][j]) {k++; travel = 0;}
            }
            right = 1;
            if(!extra) continue;
            if(!mar1[i+1].empty())
            {
                done[i+1][mar1[i+1][0]] = 1;
                int l1 = mar1[i+1].size();
                vector<pii> v1,v2;
                if(l == 1 && l1 == 1)
                {
                    ll score1 = maxPath2(i,extra,i+1,mar1[i+1][0],n,v1);
                    ll score2 = maxPath3(i,extra,i+1,mar1[i+1][0],v2);
                    if(score1 > score2) ans[k] = v1;
                    else ans[k] = v2;
                }
                else maxPath3(i,extra,i+1,mar1[i+1][0],ans[k]);
            }
            else
            {
                right = 0;
                int j = i+2;
                while(mar1[j].empty()) j++;
                ans[k].pb({i,extra});
                int l1 = mar1[j].size();
                maxPath(i+1,extra,j-1,mar1[j][l1-1],ans[k]);
                ans[k].pb({j,mar1[j][l1-1]});
                done[j][mar1[j][l1-1]] = 1;
            }
            k++;
        }
    }
    for(int i=0;i<m;i++)
    {
        k = ans[i].size();
        cout<<k<<" ";
        for(int j=0;j<k;j++) cout<<ans[i][j].X<<" "<<ans[i][j].Y<<" ";
        cout<<"\n";
    }
    return 0;
}
