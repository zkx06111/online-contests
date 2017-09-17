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
 
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> VI;

int n, ai[55], dp[55][2][2];

int main(){
	scanf("%d", &n);
	int sum = 0;
	REP(i, 1, n) scanf("%d", &ai[i]), sum += ai[i];
	PER(i, n, 1){
		REP(j, 0, 1){
			dp[i][j][0] = max(dp[i + 1][j][1], dp[i + 1][j][0]);
			dp[i][j][1] = min(dp[i + 1][j ^ 1][0], dp[i + 1][j ^ 1][1]) + ai[i];
		}
	}
	int ans = max(dp[1][0][0], dp[1][0][1]);
	printf("%d %d\n", sum - ans, ans);
	return 0;
}