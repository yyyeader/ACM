#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

ll sum[N];//前缀和
ll power[60];

int main() {
	ll n, k;
	cin >> n >> k;
	sum[0] = 0;
	map<ll, ll>mp;
	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}

	ll t = 1;
	ll cnt = 0;
	power[0] = 1;
	//1和-1需要特判 
	if (k == 1 || k == -1) {
		if (k == -1) {
			power[1] = -1;
			cnt++;
		}
	}
	else {
		for (int i = 1; i <= 50; i++) {
			t *= k;
			if (t>1e14)
				break;
			power[++cnt] = t;
		}
	}
	//sum[l]=0时的情况
	for (int i = 0; i <= cnt; i++) {
		mp[power[i] + 0]++;
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		//计算ans一定要写在这里
		ans += mp[sum[i]];
		//记录sum[r]=sum[l]+power[j]的出现次数
		for (int j = 0; j <= cnt; j++) {
			mp[sum[i] + power[j]]++;
		}
	}
	cout << ans << endl;
	/*这种写法是错误的，因为sum[r]一定在sum[l]之后，可能出现sum[l]+power[i]得到的值不在sum[l]后面，
	而在sum[l]前面，那么也就不满足是sum[r]的条件了，下面这样写就会把这种情况也记录在内了。
	for (int i = 1; i <= n; i++) {
		ans += mp[sum[i]];
	}
	cout << ans << endl;
	*/
	return 0;
}
