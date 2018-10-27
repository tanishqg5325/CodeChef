#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 32

ll memo[N][N][N][2], A, B, C;

int add(int a, int b, int c)
{
	return (a + b + c) % 2;
}

int carry(int a, int b, int c)
{
	return (a + b + c) / 2;
}

ll dp(int i, int onesA, int onesB, int car)
{
	if(onesA < 0 || onesB < 0) return 0;
	if(i == N) return (car == 0 && onesA == 0 && onesB == 0);
	ll ret = memo[i][onesA][onesB][car];
	if (ret != -1) return ret;
	ret = 0;
	int c = 0;
	if (C & (1LL << i)) c = 1;

	// 0 0
	if (add(0, 0, car) == c) ret += dp(i + 1, onesA, onesB, carry(0, 0, car));

	// 0 1
	if (add(0, 1, car) == c) ret += dp(i + 1, onesA, onesB - 1, carry(0, 1, car));

	// 1 0
	if (add(1, 0, car) == c) ret += dp(i + 1, onesA - 1, onesB, carry(1, 0, car));

	// 1 1
	if (add(1, 1, car) == c) ret += dp(i + 1, onesA - 1, onesB - 1, carry(1, 1, car));

	memo[i][onesA][onesB][car] = ret;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t, onesA, onesB;
	cin>>t;
	while (t--)
    {
		cin>>A>>B>>C;
		memset(memo, -1, sizeof memo);
		onesA = onesB = 0;
		for (ll i = 0; i < N; i++)
		{
			if(A & (1LL << i)) onesA++;
			if(B & (1LL << i)) onesB++;
		}
		cout<<dp(0,onesA,onesB,0)<<"\n";
	}
	return 0;
}
