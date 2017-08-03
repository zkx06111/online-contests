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


const int N = 1000005;
int nop[N], pr[N];

void sieve(int n){
	REP(i, 2, n){
		if (!nop[i]) pr[++pr[0]] = i;
		for (int j = 1; j <= pr[0] && i * pr[j] <= n; ++j){
			nop[pr[j] * i] = 1;
			if (i % pr[j] == 0) break;
		}
	}
}

LL num[N], prod[N];
const int mo = 998244353;

void solve(){
	LL L, R, K;
	scanf("%lld%lld%lld", &L, &R, &K);
	for (int i = 0; i <= R - L; ++i) prod[i] = 1, num[i] = L + i;
	for (int i = 1; i <= pr[0] && pr[i] <= R; ++i){
		LL l = (L / pr[i] + (L % pr[i] != 0)) * pr[i];
		while (l <= R){
			int x = l - L, c = 0;
			while (num[x] % pr[i] == 0){
				++c;
				num[x] /= pr[i];
			}
			(prod[l - L] *= (K * c + 1)) %= mo;
			l += pr[i];
		}
	}
	int ans = 0;
	for (int i = 0; i <= R - L; ++i){
		if (num[i] > 1) (prod[i] *= (K + 1)) %= mo;
		(ans += prod[i]) %= mo;
	}
	printf("%d\n", ans);
}

int main(){
	sieve(1000000);
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}