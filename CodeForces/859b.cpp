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

int main(){
	int n, sq;
	cin >> n;
	int ans = INT_MAX;
	for (int i = 1; i * i <= n; ++i){
		int b = n / i, c = n % i;
		if (c) ++b;
		ans = min(ans, 2 * b + 2 * i);
	}
	printf("%d\n", ans);
	return 0;
}