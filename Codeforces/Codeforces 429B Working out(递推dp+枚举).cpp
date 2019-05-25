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
const int N=1e3+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int mp[N][N];
LL dp1[N][N],dp2[N][N],dp3[N][N],dp4[N][N];

int main(){
	FAST_IO;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	}
	//计算从(1,1)到(n,m)路程中,(1,1)到(i,j)的最优解 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+mp[i][j];
		}
	}
	//计算从(1,1)到(n,m)路程中,(i,j)到(n,m)的最优解 
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1])+mp[i][j];
		}
	}
	//计算从(n,1)到(1,m)路程中,(n,1)到(i,j)的最优解 
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			dp3[i][j]=max(dp3[i+1][j],dp3[i][j-1])+mp[i][j];
		}
	}
	//计算从(n,1)到(1,m)路程中,(i,j)到(1,m)最优解 
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			dp4[i][j]=max(dp4[i-1][j],dp4[i][j+1])+mp[i][j];
		}		
	}
	
	LL ans=-1;
	//枚举相遇点,注意不能在边界相遇，因为这样两个人相遇肯定不止一次 
	for(int i=2;i<n;i++){
		for(int j=2;j<m;j++){
			LL t1=dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j];//情况一 
			LL t2=dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1];//情况二 	
			ans=max(ans,max(t1,t2));
		}
	}
	cout<<ans<<endl;
	return 0;
}

