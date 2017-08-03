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

void solve(){
	int n;
	scanf("%d", &n);
	int cnt = 0;
	REP(i, 1, n){
		int x; scanf("%d", &x);
		cnt += x % 2;
	}
	if (cnt <= n / 2) printf("2 0\n");
	else printf("2 1\n");
}

int main(){
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}