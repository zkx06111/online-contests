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
	int K, v, mx = 0;
	cin >> K;
	REP(i, 1, K){
		cin >> v;
		mx = max(mx, v);
	}
	if (mx <= 25){
		puts("0");
	} else{
		printf("%d\n", mx - 25);
	}
	return 0;
}