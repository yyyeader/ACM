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
const int N=2e3+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

LL dp[N],ub[N];
bool rain[N];

int main(){
	FAST_IO;
	int a,n,m;
	cin>>a>>n>>m;
	for(int i=0;i<N;i++){
		dp[i]=ub[i]=1e18;
	}
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		if(l>r) swap(l,r);
		for(int j=l;j<=r-1;j++){
			rain[j]=true;
		}
	}
	for(int i=1;i<=m;i++){
		LL p,w;
		cin>>p>>w;
		ub[p]=min(ub[p],w);
	}
	dp[0]=0;
	for(int i=1;i<=a;i++){
		if(!rain[i-1]){
			dp[i]=dp[i-1];
		}
		else{
			for(int j=i-1;j>=0;j--){
				if(ub[j]!=1e18)
					dp[i]=min(dp[i],dp[j]+(i-j)*ub[j]);
			}
		}
	}
	if(dp[a]==1e18)
		cout<<-1<<endl;
	else
		cout<<dp[a]<<endl;
	return 0;
}

