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
const int N=2e3+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

bool rain[N],flag[N];
LL dp[N][3],ub[N];
//dp[i][0]表示到达第i段不拿伞最小花费
//dp[i][1]表示到达第i段拿伞最小化费
//dp[i][2]表示到达第i段拿最小重量的伞的最小化费 

int main(){
	FAST_IO;
	int a,n,m;
	cin>>a>>n>>m;
	for(int i=0;i<N;i++){
		ub[i]=dp[i][0]=dp[i][0]=dp[i][1]=1e18;
	}
	for(int i=1;i<=n;i++){
		int l,r;
		if(l>r)
			swap(l,r);
		cin>>l>>r;
		for(int j=l;j<=r-1;j++){
			rain[j]=true;
		}
	}
	for(int i=1;i<=m;i++){
		LL p,w;
		cin>>p>>w;
		ub[p]=min(ub[p],w);
	}
	
	if(!rain[0])
		dp[0][0]=0;
	dp[0][1]=dp[0][2]=ub[0];
	LL mmin=ub[0],now=ub[0];
	for(int i=1;i<=a-1;i++){
		if(ub[i]){
			mmin=min(ub[i],mmin);
			now=min(ub[i],now);
		}
		LL t=min(dp[i-1][1]+now,dp[i-1][2]+mmin);
		dp[i][1]=t;
		if(t==dp[i-1][2]+mmin)
			now=mmin;
		dp[i][2]=dp[i-1][2]+mmin;
			
		//下雨 
		if(rain[i]){
			//有伞 
			if(ub[i]){
				dp[i][1]=min(dp[i-1][0]+ub[i],dp[i][1]);
				if(dp[i][1]==dp[i-1][0]+ub[i])
					now=ub[i];	
				if(mmin==ub[i]){
					dp[i][2]=min(dp[i-1][0]+mmin,dp[i][2]);
				}
			}
		}
		//不下雨 
		else{
			dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
			//有伞 
 			if(ub[i]){
				dp[i][1]=min(dp[i-1][0]+ub[i],dp[i][1]);
				if(dp[i][1]==dp[i-1][0]+ub[i])
					now=ub[i];	
				if(mmin==ub[i]){
					dp[i][2]=min(dp[i-1][0]+mmin,dp[i][2]);
				}
			}
		}
	}
	LL ans=min(dp[a-1][0],dp[a-1][1]);
	if(ans!=1e18)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
	return 0;
}

