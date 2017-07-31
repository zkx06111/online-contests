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

const int N = 35005;
int n, m, ai[N], prev[N], vis[N], dp[N], mx[N << 2], tag[N << 2];

#define lc (x << 1)
#define rc (x << 1 | 1)

void add(int x, int v){
	mx[x] += v;
	tag[x] += v;
}

void pd(int x){
	if (tag[x]){
		add(lc, tag[x]);
		add(rc, tag[x]);
		tag[x] = 0;
	}
}

void pu(int x){
	mx[x] = max(mx[lc], mx[rc]);
}

void build(int x, int l, int r){
	tag[x] = 0;
	if (l == r){
		mx[x] = dp[l - 1];
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pu(x);
}

void modify(int x, int l, int r, int ql, int qr){
	if (ql > qr) return;
	if (ql <= l && r <= qr){
		add(x, 1); return;
	}
	pd(x);
	int mid = l + r >> 1;
	if (ql <= mid) modify(lc, l, mid, ql, qr);
	if (qr > mid) modify(rc, mid + 1, r, ql, qr);
	pu(x);
}

int query(int x, int l, int r, int ql, int qr){
	if (ql <= l && r <= qr) return mx[x];
	int mid = l + r >> 1, res = 0;
	pd(x);
	if (ql <= mid) res = max(res, query(lc, l, mid, ql, qr));
	if (qr > mid) res = max(res, query(rc, mid + 1, r, ql, qr));
	return res;
}

int main(){
	// freopen("d.in", "r", stdin);
	scanf("%d%d", &n, &m);
	REP(i, 1, n) scanf("%d", &ai[i]);
	REP(i, 1, n){
		prev[i] = vis[ai[i]];
		vis[ai[i]] = i;
		dp[i] = dp[i - 1];
		if (!prev[i]) ++dp[i];
	}
	dp[0] = -n;
	// debug("prev[5] = %d\n", prev[5]);
	REP(i, 2, m){
		build(1, 1, n);
		REP(j, 1, n){
			// debug("add [%d, %d]\n", prev[j] + 1, j);
			modify(1, 1, n, prev[j] + 1, j);
			if (j >= i){
				dp[j] = query(1, 1, n, i, j);
				// debug("dp[%d][%d] = %d\n", i, j, dp[j]);
			} else dp[j] = -n;
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}