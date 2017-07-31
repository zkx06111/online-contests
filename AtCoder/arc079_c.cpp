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
LL ai[55];

LL chk(LL x){
	LL sum = 0;
	REP(i, 1, n){
		LL t = (ai[i] + x - (n - 1));
		if (t < 0) continue;
		if (t % (n + 1)) t = t / (n + 1) * (n + 1) + (n + 1);
		t /= (n + 1);
		sum += t;
	}
	return abs(sum - x);
}

int main(){
	cin >> n;
	REP(i, 1, n) cin >> ai[i];
	LL l = 0, r = 500000000000000000;
	while (l + 10000 <= r){
		LL lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
		if (chk(lmid) <= chk(rmid)) r = rmid;
		else l = lmid;
	}
	for (LL i = l; i <= r; ++i)
		if (chk(i) == 0){
			cout << i << endl;
			return 0;
		}
	return 0;
}
