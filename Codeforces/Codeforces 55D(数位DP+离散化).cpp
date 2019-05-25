#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int N = 25;
const int LCM = 2520 + 5;//1~9的最小公倍数是2520 
ll a[N];
ll dp[N][LCM][50];
ll HASH[LCM];

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}

ll dfs(ll pos, ll mod, ll lcm, bool limit) {
	if (pos == 0)  return mod%lcm == 0;
	if (!limit&&dp[pos][mod][HASH[lcm]] != -1)	return dp[pos][mod][HASH[lcm]];
	ll ans = 0;
	ll up = limit ? a[pos] : 9;
	for (int i = 0; i <= up; i++) {
		ans += dfs(pos - 1, (mod * 10 + i) % 2520, i==0?lcm:lcm/ gcd(lcm, i)*i, limit && (i == up));
	}
	if (!limit)	dp[pos][mod][HASH[lcm]] = ans;
	return ans;
}

ll solve(ll n) {
	ll top = 0;
	while (n) {
		a[++top] = n % 10;
		n /= 10;
	}
	return dfs(top, 0, 1, 1);
}

int main() {
	ios::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	int num = 1;
	for (int i = 1; i<= 2520; i++){//为什么把其他情况都当成0可以 
		if (2520 % i == 0){
			HASH[i] = num++;
		}
	}
	ll t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		ll ans = 0;
		ans += solve(r) - solve(l - 1);
		cout << ans << endl;
	}
}
