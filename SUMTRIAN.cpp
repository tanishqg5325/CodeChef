#include <iostream>

using namespace std;

int max(int a, int b)
{
    if(a>=b)
        return a;
    return b;
}

int maxsum(int ar[][100][100], int i, int j, int k, int n, int ar1[][100][100])
{
    if(j >= n)
        return 0;
    if(ar1[i][j][k])
        return ar1[i][j][k];
    int t1 = maxsum(ar, i, j+1, k, n, ar1);
    int t2 = maxsum(ar, i, j+1, k+1, n, ar1);
    int t = ar[i][j][k] + max(t1,t2);
    ar1[i][j][k] = t;
    return t;
}

int main()
{
    int n;
    cin>>n;
    int ar[n][100][100], rows[n], ar1[n][100][100];
    for (int i=0; i < n; i++)
    {
        cin>>rows[i];
        for (int j=0; j < rows[i]; j++)
            for(int k=0; k <= j; k++)
            {
                cin>>ar[i][j][k];
                ar1[i][j][k]=0;
            }
    }

    for (int i=0; i < n; i++)
    {
        int maxs;
        maxs = maxsum(ar,i,0,0,rows[i],ar1);
        cout<<maxs<<endl;
    }
    return 0;
}
