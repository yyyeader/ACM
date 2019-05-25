#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+5;
const int M=2e5+5;

struct node{
	int to,next;
}edge[M];

int cnt,n,m;
int head[N],in_deg[N],out_deg[N],dp[N];//dp[i]记录到i点为止的方案数 

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
	memset(dp,0,sizeof(dp));
	memset(in_deg,0,sizeof(in_deg));
	memset(out_deg,0,sizeof(out_deg));
}

void add(int u,int v){
	edge[cnt]=node{v,head[u]};
	head[u]=cnt++;
}

int topo(){
	int ans=0;
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(in_deg[i]==0){
			dp[i]=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			in_deg[t.to]--;
			dp[t.to]+=dp[u];
			if(in_deg[t.to]==0)
				q.push(t.to);
			if(out_deg[t.to]==0)
				ans+=dp[u];
		}
	}
	return ans;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			in_deg[v]++;
			out_deg[u]++;
		}
		printf("%d\n",topo());
	}
	return 0;
}
