#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int N=3e5+5;
ll a[N],sum[N];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=(a[i]+sum[i-1])%MOD;//sum[i]Ϊa[i]ǰ׺�� 
	}
	ll ans=0;
	ll tmp=1;
	for(int i=0;i<=n-2;i++){
		if(i!=0)
			tmp=tmp<<1;
		tmp%=MOD;
		ll a=(sum[n]-sum[n-(i+1)]-sum[i+1])%MOD;
		if(a<0)
			a=(a+MOD)%MOD;//����֪��a�϶��Ǵ���0�ģ�С��0����Ϊsum[i]ȡģ��ֵ��С�ˣ�����Ҫ������ 
		ans+=tmp*a;
		ans%=MOD;
	}
	cout<<ans<<endl;
}
