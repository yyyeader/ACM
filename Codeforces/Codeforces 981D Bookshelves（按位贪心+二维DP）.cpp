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
const int N=1e2+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int n,p;
LL a[N],dp[N][N];//dp[i][j]表示1~i分j段是否符合条件 

bool check(LL x){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int k=1;k<=p;k++){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<=n;j++){
				LL t=a[j]-a[i];
				if((t&x)==x&&dp[i][k-1]){
					dp[j][k]=1;
				}
			}
		}
	}
	return dp[n][p];
}

int main(){
	FAST_IO;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	LL ans=0;
	for(int i=60;i>=0;i--){
		ans|=(1LL<<i);
		if(!check(ans))
			ans-=(1LL<<i);
	}
	cout<<ans<<endl;
	return 0;
}

