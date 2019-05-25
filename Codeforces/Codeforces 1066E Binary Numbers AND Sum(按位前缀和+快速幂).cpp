#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;
const int MOD=998244353;

char a[N],b[N]; 
LL sum[N];//到第i位位置累计1的数量

LL mod_pow(LL x,LL n){
	LL res=1;
	while(n>0){
		if(n&1) res=res*x%MOD;
		x=x*x%MOD;
		n>>=1;		     
	}
	return res;
}

int main(){
	int n,m;
	cin>>n>>m;
	cin>>a+1>>b+1;
	reverse(a+1,a+1+n);
	reverse(b+1,b+1+m);
	for(int i=m;i>=1;i--){
		if(b[i]!='1') continue;
		int t=min(n,i);
		sum[t]++;
	}
	LL ans=0;
	for(int i=n;i>=1;i--){
		sum[i]+=sum[i+1];
		if(a[i]!='1') continue;
		ans=(ans+sum[i]*mod_pow(2,i-1))%MOD;
	}
	cout<<ans<<endl;
	return 0;
}

