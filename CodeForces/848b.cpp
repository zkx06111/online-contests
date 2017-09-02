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
int n, W, H, pos[N], ti[N], gi[N], idx;
pii ans[N];
map<int, int> id;
deque<int> dq[N];
VI va[N], vb;

bool cmp(int x, int y){
	if (pos[x] != pos[y])
		return pos[x] < pos[y];
	return ti[x] < ti[y];
}

int main(){
	// freopen("d.in", "r", stdin);
	scanf("%d%d%d", &n, &W, &H);
	REP(i, 1, n){
		scanf("%d%d%d", &gi[i], &pos[i], &ti[i]);
		if (gi[i] == 1){
			if (!id[ti[i] - pos[i]]){
				id[ti[i] - pos[i]] = ++idx;
			}
			va[id[ti[i] - pos[i]]].pb(i);
		} else{
			vb.pb(i);
		}
	}
	REP(i, 1, idx){
		sort(va[i].begin(), va[i].end(), cmp);
		RVC(j, va[i])
			dq[i].pb(va[i][j]);
	}
	sort(vb.begin(), vb.end(), cmp);
	RVC(i, vb){
		int x = vb[i];
		int y = ti[x] - pos[x];
		if (!id[y]){
			ans[x] = mp(W, pos[x]);
		} else{
			y = id[y];
			ans[dq[y].back()] = mp(W, pos[x]);
			dq[y].pop_back();
			dq[y].push_front(x);
		}
	}
	for (auto it = id.begin(); it != id.end(); ++it){
		int a = it -> se;
		int j = 0;
		for (auto jt = dq[a].begin(); jt != dq[a].end(); ++jt, ++j){
			ans[*jt] = mp(pos[va[a][j]], H);
		}
	}
	REP(i, 1, n) printf("%d %d\n", ans[i].fi, ans[i].se);
	return 0;
}