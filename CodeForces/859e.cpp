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

const int N = 200005;
int n, col[N], fa[N], in[N], onc[N], vis[N], pa[N], sz[N];
queue<int> Q;

void hhh(int x){
	if (onc[x] != -1) return;
	if (!fa[x]){
		onc[x] = 1;
		return;
	}
	hhh(fa[x]);
	onc[x] = onc[fa[x]];
}

int Find(int x){
	return pa[x] == x ? x : pa[x] = Find(pa[x]);
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if (x != y){
		pa[x] = y;
		sz[y] += sz[x];
	}
}

int main(){
	scanf("%d", &n);
	REP(i, 1, n){
		int a, b;
		scanf("%d%d", &a, &b);
		fa[a] = b;
		col[a] = col[b] = 1;
		++in[b];
	}
	REP(i, 1, 2 * n) if (col[i] && !in[i]){
		Q.push(i);
	}
	while (!Q.empty()){
		int h = Q.front(); Q.pop();
		--in[fa[h]];
		if (!in[fa[h]]){
			Q.push(fa[h]);
		}
	}
	memset(onc, -1, sizeof onc);
	int mo = 1000000007;
	LL p = 1;

	REP(i, 1, 2 * n) if (col[i] && !vis[i] && in[i] > 0){
		onc[i] = 0;
		int t =0;
		for (int j = i; !vis[j]; j = fa[j]){
			vis[j] = 1;
			onc[j] = 0;
			++t;
		}
		if (t != 1)
			p = p * 2 % mo;
	}
	REP(i, 1, 2 * n) if (col[i] && onc[i] == -1) hhh(i);
	REP(i, 1, 2 * n) if (onc[i]){
		sz[i] = 1;
		pa[i] = i;
	}
	REP(i, 1, 2 * n) if (col[i] && onc[i] && fa[i])
		Union(i, fa[i]);

	LL ans = 1;
	REP(i, 1, 2 * n) if (i == pa[i]) (ans *= sz[i]) %= mo;
	printf("%lld\n", ans * p % mo);
	return 0;
}