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
int pi[N], n, out[N], on_tree[N], Q[N], sg[N], vis[N], va[N];
VI to[N];

void tok(int x){
	memset(va, 0, sizeof va);
	for (int i = pi[x]; i != x; i = pi[i]){
		RVC(j, to[i]) va[sg[to[i][j]]] = i;
		for (sg[i] = 0; va[sg[i]] == i; ++sg[i]);
	}
	RVC(j, to[x]) va[sg[to[x][j]]] = x;
	int tmp = 0;
	for (; va[tmp] == x; ++tmp);
	if (tmp == sg[x]){
		puts("POSSIBLE");
		exit(0);
	}
}

int main(){
	scanf("%d", &n);
	REP(i, 1, n){
		scanf("%d", &pi[i]);
		to[pi[i]].pb(i);
		++out[pi[i]];
	}
	int hd = 1, tl = 0;
	REP(i, 1, n) if (!out[i]) Q[++tl] = i;
	while (hd <= tl){
		int x = Q[hd++];
		on_tree[x] = 1;
		--out[pi[x]];
		if (!out[pi[x]]) Q[++tl] = pi[x];
	}
	REP(i, 1, tl){
		int x = Q[i];
		RVC(j, to[x]) vis[sg[to[x][j]]] = x;
		for (sg[x] = 0; vis[sg[x]] == x; ++sg[x]);
	}
	REP(i, 1, n) if (!on_tree[i]){
		RVC(j, to[i]) if (on_tree[to[i][j]]) vis[sg[to[i][j]]] = i;
		for (sg[i] = 0; vis[sg[i]] == i; ++sg[i]);
		tok(i);
		for (++sg[i]; vis[sg[i]] == i; ++sg[i]);
		tok(i);
		return puts("IMPOSSIBLE"), 0;
	}
	return 0;
}
