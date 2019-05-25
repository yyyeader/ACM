#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<cctype>
#include<math.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
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
const int N=2e2+5;
const LL INF64=1e18;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int p[N];
int mp[N][N],dp[1<<15][N];

int main(){
	memset(mp,0x3f,sizeof(mp));
	memset(dp,0x3f,sizeof(dp));
	FAST_IO;
	int n,m,r;
	cin>>n>>m>>r;
	int res=0;
	for(int i=0;i<r;i++){
		cin>>p[i];
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		mp[a][b]=mp[b][a]=c;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}

	int lim=1<<r;
	int ans=INF;
	for(int i=1;i<lim;i++){
		int cnt=0;
		for(int j=0;j<r;j++){
			int tmp=(1<<j);
			if(tmp&i)
				cnt++;
		}
		for(int j=0;j<r;j++){
			int tmp=(1<<j);
			if(tmp&i){
				int pre=i-tmp;
				if(cnt==1)
					dp[i][j]=0;
				else{
					for(int k=0;k<r;k++){
						if(dp[pre][k]==INF) continue;
						dp[i][j]=min(dp[i][j],dp[pre][k]+mp[p[k]][p[j]]);
					}
				}
				if(cnt==r)
					ans=min(dp[i][j],ans);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
