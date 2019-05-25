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
const int N=2e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

LL n,m,k,x,s;
LL a[N],b[N],c[N],d[N];

int main(){
	FAST_IO;
	cin>>n>>m>>k>>x>>s;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>d[i];
	}
	
	LL ans=x*n;				//初始化为不用魔法所需时间 
	a[0]=x;
	
	for(int i=0;i<=m;i++){
		//魔力值不够 
		if(b[i]>s) continue; 
		LL t=s-b[i];
		int pos=upper_bound(d+1,d+1+k,t)-d;
		pos--;
		ans=min(ans,a[i]*(n-c[pos]));
	}
	cout<<ans<<endl;
	return 0;
}

