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

const int N = 100005;
int n, m, hi[N], tag[N << 2], pos[N];

#define lc (x << 1)
#define rc (x << 1 | 1)

void build(int x, int l, int r){
	if (l == r){
		pos[l] = x;
		return;
	}
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
}

void modify(int x, int l, int r, int ql, int qr){
	if (ql > qr) return;
	if (ql <= l && r <= qr){
		--tag[x];
		return;
	}
	int mid = l + r >> 1;
	if (ql <= mid) modify(lc, l, mid, ql, qr);
	if (qr > mid) modify(rc, mid + 1, r, ql, qr);
}

int query(int x){
	int res = hi[x];
	for (x = pos[x]; x; x >>= 1)
		res += tag[x];
	return res;
}

int main(){
	scanf("%d%d", &n, &m);
	REP(i, 1, n) scanf("%d", &hi[i]);
	sort(hi + 1, hi + n + 1);
	build(1, 1, n);
	REP(i, 1, m){
		int x; scanf("%d", &x);
		int p = n - x + 1;
		int l = 1, r = p, v = query(p), lb, rb;
		if (v == 0)
			return printf("%d\n", i - 1), 0;
		while (l <= r){
			int mid = l + r >> 1;
			if (query(mid) == v)
				lb = mid, r = mid - 1;
			else l = mid + 1;
		}
		l = p, r = n;
		while (l <= r){
			int mid = l + r >> 1;
			if (query(mid) == v)
				rb = mid, l = mid + 1;
			else r = mid - 1;
		}
		modify(1, 1, n, rb + 1, n);
		modify(1, 1, n, lb, lb + rb - p);
	}
	printf("%d\n", m);
	return 0;
}