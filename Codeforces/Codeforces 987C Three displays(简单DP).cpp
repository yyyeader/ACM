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
const int N=3e3+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

struct node{
	int val,cost;
}a[N];

int dp[N];

int main(){
	FAST_IO;
	memset(dp,0x3f,sizeof(dp));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].cost;
	}
	int ans=INF;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i].val>a[j].val){
				dp[i]=min(dp[i],a[i].cost+a[j].cost);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i].val>a[j].val&&dp[j]!=INF){
				ans=min(ans,dp[j]+a[i].cost);
			}
		}
	}
	if(ans!=INF)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
	return 0;
}

