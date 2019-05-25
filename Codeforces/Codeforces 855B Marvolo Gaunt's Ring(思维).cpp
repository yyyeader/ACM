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
const int INF=0x3f3f3f3f;
const double eps=1e-10;

LL Max[N],Min[N],a[N],dp[N];

int main(){
	FAST_IO;
	int n,p,q,r;
	cin>>n>>p>>q>>r;
	Max[0]=-4e18;
	Min[0]=4e18;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Max[i]=max(Max[i-1],a[i]);
		Min[i]=min(Min[i-1],a[i]);
	}
	for(int i=1;i<=n;i++){
		if(p<0)
			dp[i]=Min[i]*p+a[i]*q;
		else
			dp[i]=Max[i]*p+a[i]*q;
	}
	for(int i=2;i<=n;i++){
		dp[i]=max(dp[i],dp[i-1]);
	}
	LL ans=-4e18;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]+a[i]*r);
	}
	cout<<ans<<endl;
	return 0;
}

