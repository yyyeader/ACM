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

int dp[N],root[N];

struct node{
	int w,b;
	node(){}
	node(int w,int b):w(w),b(b){}
}a1[N],a2[N];
vector<node>v[N]; 

int find(int x){
	return root[x]==x?x:find(root[x]);
}

int main(){
	FAST_IO;
	int n,m,lim;
	cin>>n>>m>>lim;
	for(int i=1;i<=n;i++){
		root[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>a1[i].w;
		a2[i].w=a1[i].w;
	}
	for(int i=1;i<=n;i++){
		cin>>a1[i].b;
		a2[i].b=a1[i].b;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		int t1=find(x),t2=find(y);
		if(t1!=t2){
			a1[t2].w+=a1[t1].w;
			a1[t2].b+=a1[t1].b;
			root[t1]=t2;
		}
	}
	for(int i=1;i<=n;i++){
		if(find(i)==i){
			v[i].push_back(node(a1[i].w,a1[i].b));
			v[i].push_back(node(a2[i].w,a2[i].b));
		}
		else
			v[find(i)].push_back(node(a2[i].w,a2[i].b));
	}
	
	for(int i=1;i<=n;i++){
		for(int j=lim;j>=0;j--){
			for(int k=0;k<v[i].size();k++){
				node t=v[i][k];
				if(j>=t.w){
					dp[j]=max(dp[j],dp[j-t.w]+t.b);
				}
			}
		}
	}
	cout<<dp[lim]<<endl;
	return 0;
}

