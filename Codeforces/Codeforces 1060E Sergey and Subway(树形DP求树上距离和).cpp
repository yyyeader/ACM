#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N=2e5+5;

struct node{int nxt,to;}edge[N*2];
int cnt;
int head[N],sign[N],sze[N];
bool vis[N];

void init(){
	cnt=1;
	memset(head,0,sizeof(head));
}

void add(int u,int v){
	edge[cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt++;
}

int dfs(int u,int p,int k){
	sze[u]=1;
	sign[u]=k;
	for(int i=head[u];i;i=edge[i].nxt){
		node t=edge[i];
		if(t.to==p) continue;
		sze[u]+=dfs(t.to,u,k^1);
	}
	return sze[u];
}

int main(){
	FAST_IO;
	int n;
	while(cin>>n){
		init();
		for(int i=1;i<=n-1;i++){
			int a,b;
			cin>>a>>b;
			add(a,b);
			add(b,a);
		}
		dfs(1,-1,1);
		LL ans=0,sum=0;
		for(int i=1;i<=n;i++){
			ans+=1LL*sze[i]*(n-sze[i]);
			sum+=sign[i];
		}
		ans+=sum*(n-sum);
		cout<<ans/2<<endl;
	}
	return 0;
} 
