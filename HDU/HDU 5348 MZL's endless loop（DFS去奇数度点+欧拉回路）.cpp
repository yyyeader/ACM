#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#define CLR(arr,val)  memset(arr,val,sizeof(arr))
using namespace std;
const int N=1e5+5;
const int M=3e5+5; 

struct node{
	int next,to,w;
}edge[2*M];

int n,m,idx;
int degree[N],head[N],dir[M];
bool vis[M];

void init(){
	idx=2;
	CLR(head,0);
	CLR(degree,0);
	CLR(vis,false);
}

void addedge(int u,int v,int w){
	edge[idx].next=head[u];
	edge[idx].to=v;
	edge[idx].w=w;
	head[u]=idx++;
}

void dfs1(int u){
	for(int &j=head[u];j;j=edge[j].next){
		node t=edge[j];
		if(!vis[j>>1]){
			vis[j>>1]=true;
			degree[u]--;
			degree[t.to]--;
			dir[j>>1]=t.w;
			if(degree[t.to]%2==1)
				dfs1(t.to);
			return;					//注意这里要return 
		}
	}
}

//套圈法找欧拉回路 
void dfs2(int u){
	for(int &j=head[u];j;j=edge[j].next){
		node t=edge[j];
		if(!vis[j>>1]){
			vis[j>>1]=true;
			degree[u]--;
			degree[t.to]--;
			dir[j>>1]=t.w;
			dfs2(t.to);
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			degree[u]++;
			degree[v]++;
			addedge(u,v,1);
			addedge(v,u,0);
		}
		queue<int>q;
		for(int i=1;i<=n;i++){
			if(degree[i]%2==1)
				q.push(i);		//所有奇点入队 
		}		
		//消除奇数点
		while(!q.empty()){
			int t=q.front();
			q.pop();
			if(degree[t]%2==1){
				dfs1(t);
			}		
		}
		//找欧拉回路
		for(int i=1;i<=n;i++){
			if(degree[i]>0)
				dfs2(i);
		}
		for(int i=1;i<=m;i++){
			printf("%d\n",dir[i]);
		}
	}
	return 0;
}
