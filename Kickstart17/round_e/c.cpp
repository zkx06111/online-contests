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
	double a[3];
	REP(i, 0, 2){
		double t;
		cin >> a[i] >> t >> t;
	}
	sort(a, a + 3);
	printf("%.8lf\n", (a[2] - a[0]) / 6);
}

int main(){
	int T; scanf("%d", &T);
	REP(i, 1, T){
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}