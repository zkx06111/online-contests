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

const int N = 300005;
int n, m, va[N], vb[N];

int main(){
	cin >> n >> m;
	REP(i, 1, m){
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		if (u == 1) va[v] = 1;
		if (v == n) vb[u] = 1;
	}
	REP(i, 1, n) if (va[i] && vb[i])
		return puts("POSSIBLE"), 0;
	puts("IMPOSSIBLE");
	return 0;
}
