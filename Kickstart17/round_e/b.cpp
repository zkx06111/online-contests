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

int n, arr[5005], cc[5005], scc[5005];
map<int, int> cnt;

void solve(){
	scanf("%d", &n);
	cnt.clear();
	REP(i, 1, n){
		int x; scanf("%d", &x);
		++cnt[x];
		arr[i] = x;
	}
	sort(arr + 1, arr + n + 1);
	n = unique(arr + 1, arr + n + 1) - arr - 1;
	REP(i, 1, n) cc[i] = cnt[arr[i]];
	REP(i, 1, n) scc[i] = scc[i - 1] + cc[i];
	LL ans = 0;
	REP(i, 1, n) if (cc[i] >= 2){
		int t = cc[i];
		REP(j, 1, n){ // top
			int l = j + 1, r = n, bot = -1;
			while (l <= r){
				int mid = l + r >> 1;
				if ((LL)arr[j] + (LL)2 * arr[i] > (LL)arr[mid])
					bot = mid, l = mid + 1;
				else r = mid - 1;
			}
			if (bot == -1) continue;
			if (j == i){	
				ans += 1ll * cc[i] * (cc[i] - 1) * (cc[i] - 2) / 6 * (scc[bot] - scc[j]);
			} else{
				if (j < i && i <= bot){
					ans += 1ll * cc[i] * (cc[i] - 1) / 2 * cc[j] * 
						(scc[bot] - scc[i] + scc[i - 1] - scc[j]);
					ans += 1ll * cc[i] * (cc[i] - 1) * (cc[i] - 2) / 6 * cc[j];
				} else{
					ans += 1ll * cc[i] * (cc[i] - 1) / 2 * cc[j] * (scc[bot] - scc[j]);
				}
			}
		}
	}
	printf("%lld\n", ans);
}

int main(){
	int T; scanf("%d", &T);
	REP(i, 1, T){
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}