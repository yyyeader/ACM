#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

ll sum[N];//ǰ׺��
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
	//1��-1��Ҫ���� 
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
	//sum[l]=0ʱ�����
	for (int i = 0; i <= cnt; i++) {
		mp[power[i] + 0]++;
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		//����ansһ��Ҫд������
		ans += mp[sum[i]];
		//��¼sum[r]=sum[l]+power[j]�ĳ��ִ���
		for (int j = 0; j <= cnt; j++) {
			mp[sum[i] + power[j]]++;
		}
	}
	cout << ans << endl;
	/*����д���Ǵ���ģ���Ϊsum[r]һ����sum[l]֮�󣬿��ܳ���sum[l]+power[i]�õ���ֵ����sum[l]���棬
	����sum[l]ǰ�棬��ôҲ�Ͳ�������sum[r]�������ˣ���������д�ͻ���������Ҳ��¼�����ˡ�
	for (int i = 1; i <= n; i++) {
		ans += mp[sum[i]];
	}
	cout << ans << endl;
	*/
	return 0;
}
