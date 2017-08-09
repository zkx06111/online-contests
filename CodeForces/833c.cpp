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

LL L, R;
int dig[20], ci[10], tmp[10], cnt, ans;

void dfs(int x, int s){
	if (x == 10){
		if (s < cnt){
			int p = 0;
			LL v = 0;
			PER(i, 9, 1){
				REP(j, 1, ci[i]){
					v = v * 10 + i;
					++p;
				}
			}
			while (p < cnt - 1){
				v *= 10;
				++p;
			}
			if (v >= L){
				++ans;
				return;
			}
		}
		int fl = 1;
		LL q = 0;
		memcpy(tmp, ci, sizeof tmp);
		tmp[0] = cnt - s;
		REP(i, 1, cnt){
			int pos = -1;
			PER(j, dig[i] - 1, 0) if (tmp[j]){
				pos = j; break;
			}
			if (pos == -1 || (!pos && i == 1)){
				if (!tmp[dig[i]]) break;
				--tmp[dig[i]];
				q = q * 10 + dig[i];
				continue;
			}
			LL v = q * 10 + pos;
			int p = i;
			--tmp[pos];
			PER(j, 9, 0){
				REP(k, 1, tmp[j]) v = v * 10 + j, ++p;
			}
			++tmp[pos];
			while (p < cnt){
				v *= 10;
				++p;
			}
			if (v >= L){
				++ans;
				return;
			}
			if (!tmp[dig[i]]) break;
			--tmp[dig[i]];
			q = q * 10 + dig[i];
			continue;
		}
		if (q == R){
			REP(i, 1, 9) if (tmp[i]) return;
			if (q >= L){ ++ans; return;}
		}
		return;
	}
	REP(i, 0, cnt - s){
		ci[x] = i;
		dfs(x + 1, s + i);
	}
}

int main(){
	cin >> L >> R;
	if (L == R){
		printf("1\n");
		return 0;
	}
	LL t = R;
	if (t == 1000000000000000000LL) --t, --R;
	while (t){
		dig[++cnt] = t % 10;
		t /= 10;
	}
	reverse(dig + 1, dig + cnt + 1);
	dfs(1, 0);
	if (R + 1 == 1000000000000000000LL && L > 100000000000000000LL) ++ans;
	printf("%d\n", ans);
	return 0;
}