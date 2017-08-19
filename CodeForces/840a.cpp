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
int n, A[N], B[N], rk[N], ans[N];
pii p[N];

int main(){
	scanf("%d", &n);
	REP(i, 1, n) scanf("%d", &A[i]);
	REP(i, 1, n){
		scanf("%d", &B[i]);
		p[i] = mp(B[i], i);
	}
	sort(p + 1, p + n + 1);
	sort(A + 1, A + n + 1, greater<int>());
	REP(i, 1, n) ans[p[i].se] = A[i];
	REP(i, 1, n) printf("%d ", ans[i]); puts("");
	return 0;
}