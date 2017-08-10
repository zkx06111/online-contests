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

int n, k, m, vis[1 << 16];

int main(){
	scanf("%d%d%d", &n, &k, &m);
	if (m == n){
		if (k == (1 << n)){
			REP(i, 1, (1 << n)) printf("%d ", i);
			puts("");
		} else puts("-1");
		return 0;
	}
	if (k < (1 << m) || k == (1 << n)) return puts("-1"), 0;
	REP(i, 1, (1 << m) - 1) vis[i] = 1, printf("%d ", i);
	vis[k] = 1, printf("%d ", k);
	vis[k + 1] = 1, printf("%d ", k + 1);
	REP(i, 1, (1 << n)) if (!vis[i]) printf("%d ", i);
	puts("");
	return 0;
}