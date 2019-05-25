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

LL f[105],fac[105];

int main(){
	f[1]=0,f[2]=1,fac[1]=1,fac[2]=2;
	for(int i=3;i<30;i++){
		f[i]=(i-1)*(f[i-1]+f[i-2]);
		fac[i]=i*fac[i-1];
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n); 
		printf("%.2f%%\n",100.0*f[n]/fac[n]);//%%ЧЄТе 
	}
	return 0;
}

