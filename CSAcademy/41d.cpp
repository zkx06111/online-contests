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

const int N = 5005;
int n, ai[N], bi[N];
set<pii> S;

int main(){
	scanf("%d", &n);
	if (n == 1) return puts("0"), 0;
	REP(i, 1, n) scanf("%d", &ai[i]);
	REP(i, 1, n) scanf("%d", &bi[i]);
	if (ai[2] != bi[2]) return puts("-1"), 0;
	printf("%d\n", 2 * (n - 1) - 1);
	REP(i, 1, n - 1) printf("%d %d\n", 1, ai[i + 1]);
	REP(i, 2, n - 1) printf("%d %d\n", bi[i], bi[i + 1]);
	return 0;
}