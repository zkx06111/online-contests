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

int n, ai[1005];

int main(){
	scanf("%d", &n);
	REP(i, 1, n) scanf("%d", &ai[i]);
	sort(ai + 1, ai + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i += 2){
		ans += ai[i + 1] - ai[i];
	}
	printf("%d\n", ans);
	return 0;
}