#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
const int N=1e5+5; 

int num,cnt,n,m;
int low[N],dfn[N],fa[N],val[N],dp[N],deg[N],sum[N];
vector<int>v[N];
vector<int>g[N];
stack<int>sk;

void init(){
	cnt=num=0;
	for(int i=0;i<=n;i++) v[i].clear();
	for(int i=0;i<=n;i++) g[i].clear();
	memset(dfn,0,sizeof(dfn));
	memset(fa,0,sizeof(fa));
	memset(sum,0,sizeof(sum));
	memset(deg,0,sizeof(deg));
	memset(dp,0,sizeof(dp));
}

void tarjan(int u){
	sk.push(u);
	low[u]=dfn[u]=++cnt;
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		if(!dfn[t]){
			tarjan(t);
			low[u]=min(low[u],low[t]);
		}
		else if(!fa[t]) low[u]=min(low[u],dfn[t]);
	}
	if(low[u]==dfn[u]){
		num++;
		while(!sk.empty()){
			int t=sk.top();
			sk.pop();
			fa[t]=num;
			sum[num]+=val[t];
			if(t==u) break;
		}
	}
}

int topo(){
	queue<int>q;
	int ans=0;
	for(int i=1;i<=num;i++){
		if(!deg[i]) q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		dp[u]+=sum[u];
		ans=max(ans,dp[u]);
		for(int i=0;i<g[u].size();i++){
			int t=g[u][i];
			deg[t]--;
			dp[t]=max(dp[t],dp[u]);
			if(deg[t]==0){
				q.push(t);
			}
		}
	}
	return ans;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&val[i]);
		}
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
		}
		tarjan(1);//起点是1
		for(int i=1;i<=n;i++){
			if(fa[i]==0) continue;//i是1到达不了的点 
			for(int j=0;j<v[i].size();j++){
				int t=v[i][j];
				if(fa[i]!=fa[t]){
					g[fa[i]].push_back(fa[t]);
					deg[fa[t]]++;
				}
			}
		}
		printf("%d\n",topo());
	}
	return 0;
}
