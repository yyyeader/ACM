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

int v[N],w[N],dp[N];

int main(){
	memset(dp,0x3f,sizeof(dp));
	FAST_IO;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=10005;j>=w[i];j--){
			dp[j]=min(dp[j-w[i]]+v[i],dp[j]);
		}
	}
	int ans;
	for(int i=10000;i>=0;i--){
		if(dp[i]<=m){
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

