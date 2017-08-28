#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define RVC(i, S) for (int i = 0; i < S.size(); ++i)
#define mp make_pair
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define fi first
#define se second
using namespace std;
 
typedef unsigned long long LL;
typedef pair<int, int> pii;
typedef vector<int> VI;

int dp[105][105][105], n;
char str[105];
LL hs[105], pwr[105];

void cmin(int &x, int y){
	x = min(x, y);
}

LL get_hash(int x, int L){
	return hs[x] - hs[x + L] * pwr[L];
}

void solve(){
	scanf("%s", str + 1);
	n = strlen(str + 1);
	hs[n + 1] = 0;
	PER(i, n, 1) hs[i] = (hs[i + 1] + str[i]) * 233;
	pwr[0] = 1;
	REP(i, 1, n) pwr[i] = pwr[i - 1] * 233;
	memset(dp, 0x3f, sizeof dp);
	dp[0][0][0] = 0;
	REP(i, 0, n - 1){
		int mn = 0x3f3f3f3f;
		REP(l, 0, i) REP(r, l, i)
			cmin(mn, dp[i][l][r]);
		REP(l, 0, i) REP(r, l, i)
			cmin(dp[i][l][r], mn + 1);
		REP(l, 0, i) REP(r, l, i){
			if (dp[i][l][r] > n) continue;
			// debug("dp[%d][%d][%d] = %d\n", i, l, r, dp[i][l][r]);
			cmin(dp[i + 1][l][r], dp[i][l][r] + 1);
			if (i + r - l + 1 <= n && get_hash(l, r - l + 1) == get_hash(i + 1, r - l + 1))
				cmin(dp[i + r - l + 1][l][r], dp[i][l][r] + 1);
			cmin(mn, dp[i][l][r]);
		}
	}
	int ans = 0x3f3f3f3f;
	REP(l, 0, n) REP(r, l, n) cmin(ans, dp[n][l][r]);
	printf("%d\n", ans);
}

int main(){
	int T; scanf("%d", &T);
	REP(i, 1, T){
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}