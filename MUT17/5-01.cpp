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

int n, m, q, bi[50005], cnt[50005], ans[50005];
bitset<50005> A, B, C;
VI qr[50005];

void solve(){
	scanf("%d%d%d", &n, &m, &q);
	A.reset();
	B.reset();
	memset(cnt, 0, sizeof cnt);
	memset(bi, 0, sizeof bi);
	REP(i, 1, n){
		int x; scanf("%d", &x);
		A[x] = ((int)A[x] ^ 1);
	}
	PER(i, 50000, 0) qr[i].clear();
	REP(i, 1, m){
		int x; scanf("%d", &x);
		bi[x] ^= 1;
	}
	REP(i, 1, q){
		int x; scanf("%d", &x);
		qr[x].pb(i);
	}
	int sum = 0;
	PER(i, 50000, 0){
		int fl = 0;
		if (i && A[i]) fl = sum;
		if (qr[i].size()){
			C = (A >> i) & B;
			int t = fl ^ ((int)C.count() & 1);
			RVC(j, qr[i]) ans[qr[i][j]] = t;
		}
		if (bi[i]){
			for (int j = i; j <= 50000; j += i) B[j] = ((int)B[j] ^ 1);
			sum ^= 1;
		}
	}
	REP(i, 1, q) printf("%d\n", ans[i]);
}

int main(){
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}