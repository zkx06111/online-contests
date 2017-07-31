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
	int n;
	scanf("%d", &n);
	REP(i, 1, n){
		LL a, b;
		scanf("%lld%lld", &a, &b);
		LL v = a * b;
		LL l = 1, r = 1000000, res = 1;
		while (l <= r){
			LL mid = l + r >> 1;
			if (mid * mid * mid <= v) res = mid, l = mid + 1;
			else r = mid - 1;
		}
		if (res * res * res == v && a % res == 0 && b % res == 0)
			puts("Yes");
		else puts("No");
	}
	return 0;
}