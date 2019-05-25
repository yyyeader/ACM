#include<bits/stdc++.h>
#define lc(a) (a<<1)
#define rc(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

LL dp[N];
int p[N];

int main(){
	FAST_IO;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		dp[i+1]=(2*dp[i]-dp[p[i]]+2+MOD)%MOD;
	}
	cout<<dp[n+1]<<endl;
	return 0;
}

