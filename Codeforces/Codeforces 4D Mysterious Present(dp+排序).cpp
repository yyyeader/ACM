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
const int N=5e3+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int dp[N];
int path[N];

struct node{
	int w,h,id;
	bool operator <(const node &b)const{
		return w==b.w?h>b.h:w<b.w;
	}
}a[N];

void print(int x){
	if(x!=-1){
		print(path[x]);
		cout<<x<<" ";
	}
}

int main(){
	FAST_IO;
	int n,w,h;
	cin>>n>>w>>h;
	for(int i=1;i<=n;i++){
		int w,h;
		cin>>a[i].w>>a[i].h;
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	memset(path,-1,sizeof(path));
	int ans=0,idx=-1;
	for(int i=1;i<=n;i++){
		if(a[i].w<=w||a[i].h<=h) continue;
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(a[i].h>a[j].h){
				if(dp[i]<dp[j]+1){
					dp[i]=dp[j]+1;
					path[a[i].id]=a[j].id;
				}
			}
		}
		if(ans<dp[i]){
			ans=dp[i];
			idx=a[i].id;
		}
	}
	cout<<ans<<endl;
	print(idx);
	return 0;
}

