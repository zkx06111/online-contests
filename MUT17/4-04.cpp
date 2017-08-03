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

const int N = 60005;
int n, ai[N], pos[N], vis[N], las[N];
double mn[N << 2], tag[N << 2];

#define lc (x << 1)
#define rc (x << 1 | 1)

void build(int x, int l, int r){
	mn[x] = tag[x] = 0;
	if (l == r){
		pos[l] = x;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
}

void add(int x, double v){
	mn[x] += v;
	tag[x] += v;
}

void pd(int x){
	add(lc, tag[x]);
	add(rc, tag[x]);
	tag[x] = 0;
}

void pu(int x){
	mn[x] = min(mn[lc], mn[rc]);
}

void modify(int x, int l, int r, int ql, int qr, double v){
	if (ql > qr) return;
	if (ql <= l && r <= qr){
		add(x, v);
		return;
	}
	int mid = l + r >> 1;
	pd(x);
	if (ql <= mid) modify(lc, l, mid, ql, qr, v);
	if (qr > mid) modify(rc, mid + 1, r, ql, qr, v);
	pu(x);
}

double query(int x, int l, int r, int ql, int qr){
	if (ql <= l && r <= qr) return mn[x];
	int mid = l + r >> 1;
	double res = 1e10;
	pd(x);
	if (ql <= mid) res = min(res, query(lc, l, mid, ql, qr));
	if (qr > mid) res = min(res, query(rc, mid + 1, r, ql, qr));
	return res;
}

int chk(double p){
	build(1, 1, n);
	REP(i, 1, n){
		modify(1, 1, n, 1, las[i], -p);
		modify(1, 1, n, las[i] + 1, i, 1 - p);
		if (query(1, 1, n, 1, i) < 0) return 1;
	}
	return 0;
}

void solve(){
	scanf("%d", &n);
	memset(vis, 0, sizeof vis);
	REP(i, 1, n){
		scanf("%d", &ai[i]);
		las[i] = vis[ai[i]];
		vis[ai[i]] = i;
	}
	chk(0.5);
	double l = 0, r = 1, ans = 0;
	REP(i, 0, 20){
		double mid = 0.5 * (l + r);
		if (chk(mid)) ans = r = mid;
		else l = mid;
	}
	printf("%.8lf\n", ans);
}

int main(){
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}