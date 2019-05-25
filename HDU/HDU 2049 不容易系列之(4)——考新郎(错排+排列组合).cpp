#include <bits/stdc++.h>
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

LL C(int n,int m){
	LL s1=1,s2=1;
	for(int i=n;i>n-m;i--) s1*=i;
	for(int i=1;i<=m;i++) s2*=i;
	return s1/s2;
}

LL f[105];

int main(){
	f[1]=0,f[2]=1;
	for(int i=3;i<50;i++) f[i]=(i-1)*(f[i-1]+f[i-2]);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%lld\n",C(n,m)*f[m]);
	}
	return 0;
}

