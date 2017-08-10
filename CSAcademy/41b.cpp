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

int n;
char str[100005];
vector<pii> seg;

int main(){
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for (int i = 1, j; i <= n; i = j){
		j = i + 1;
		if (str[i] == '1') continue;
		while (j <= n && str[j] == '0') ++j;
		seg.pb(mp(i, j));
	}
	if (seg.size() == 1){
		printf("%d\n", seg[0].se - seg[0].fi);
		return 0;
	}
	if (seg.size() == 2){
		if (seg[0].se + 1 == seg[1].fi)
			printf("%d\n", seg[0].se - seg[0].fi + seg[1].se - seg[1].fi);
		else printf("%d\n", max(seg[0].se - seg[0].fi, seg[1].se - seg[1].fi) + 1);
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < seg.size(); ++i){
		ans = max(ans, seg[i].se - seg[i].fi + 1);
		if (i + 1 < seg.size() && seg[i].se + 1 == seg[i + 1].fi){
			ans = max(ans, seg[i + 1].se - seg[i].fi);
		}
	}
	printf("%d\n", ans);
	return 0;
}