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

LL chk(LL x){
	LL l = 1, r = 100000, res = -1;
	while (l <= r){
		LL mid = l + r >> 1;
		if (mid * (mid - 1) / 2 <= x)
			res = mid, l = mid + 1;
		else r = mid - 1;
	}
	return res;
}

int cnt[26];

int main(){
	LL k;
	cin >> k;
	if (k == 0){
		return puts("a"), 0;
	}
	int t = 0;
	while (k){
		cnt[t] = chk(k);
		k -= cnt[t] * (cnt[t] - 1) / 2;
		++t;
	}
	REP(i, 0, 25){
		REP(j, 1, cnt[i]) putchar('a' + i);
	}
	puts("");
	return 0;
}