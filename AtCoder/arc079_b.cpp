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

LL ans[55];
int main(){
	int n = 50;
	printf("%d\n", n);
	LL k; cin >> k;
	LL ave = k / n, lft = k % n;
	REP(i, 1, n) ans[i] = ave * (n + 1) + (n - 1) - k;
	REP(i, 1, lft) ans[i] += (n + 1);
	REP(i, 1, n) printf("%lld ", ans[i]);
	puts("");
	return 0;
}
