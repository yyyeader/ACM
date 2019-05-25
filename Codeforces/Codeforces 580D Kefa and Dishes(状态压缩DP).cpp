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
const int N=25;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

LL ans,n,m,p;
LL val[N],mp[N][N],dp[1<<18][N];//dp[i][j]表示i的状态下最后一个盘子选择第j个的最优解

int main(){
	FAST_IO;
	cin>>n>>m>>p;
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	for(int i=1;i<=p;i++){
		int x,y,c;
		cin>>x>>y>>c;
		mp[x-1][y-1]=c;
	}
	memset(dp,-1,sizeof(dp));
	ans=0;
	int lim=(1<<n);
	for(int i=1;i<lim;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			int tmp=(1<<j);
			if(tmp&i)
				cnt++;
		}
		//点菜数不能>m 
		if(cnt>m) continue;
		for(int j=0;j<n;j++){
			int tmp=(1<<j);
			if(tmp&i){
				int pre=i-tmp;
				//单个菜的时候没有前一个菜所以直接赋值，否则会被0 x类型的rule影响
				if(cnt==1)
					dp[i][j]=val[j];
				else{
					for(int k=0;k<n;k++){
						if(dp[pre][k]==-1) continue;
						dp[i][j]=max(dp[i][j],dp[pre][k]+mp[k][j]+val[j]);
					}
				}
				ans=max(dp[i][j],ans);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

