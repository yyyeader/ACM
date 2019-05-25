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
const int N=5e2+5;

struct node{
	int c,t,v;
	node(){}
	node(int c,int t,int v):c(c),t(t),v(v){}
}a[N];

int dp[2005];//到ti秒为止的最大价值 

bool cmp(node a,node b){
	return a.t<b.t;
}

int main(){
	FAST_IO;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].t>>a[i].v;
		a[i].t--;
	}
	sort(a+1,a+1+n,cmp);//开始时间小的排在前面 
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=a[i].t;j>=a[i].c;j--){
			dp[j]=max(dp[j],dp[j-a[i].c]+a[i].v);
			ans=max(ans,dp[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}

