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

int dp[505][5005],f[N],c[N],h[11];

int main(){
	FAST_IO;
	int n,k;
	cin>>n>>k;
	int x;
	for(int i=1;i<=n*k;i++){
		cin>>x;
		c[x]++;	
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		f[x]++;
	}
	for(int i=1;i<=k;i++){
		cin>>h[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n*k;j++){
			for(int t=1;t<=min(j,k);t++){
				dp[i][j]=max(dp[i][j],dp[i-1][j-t]+h[t]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<N;i++){
		ans+=dp[f[i]][c[i]];
	}
	cout<<ans<<endl;
	return 0;
}

