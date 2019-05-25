#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define pll pair<long long,long long>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=2e3+5;
const int M=1e6+5;
const LL INF=2e18;

struct node{
	int next,to;
	LL flow;
}edge[M*2];

struct vnode{
	int to;
	LL w;
};

int n,m,st,en,cnt;
int dep[N],head[N],a[M],b[M],c[M];
LL dis[N];
bool vis[N];
vector<vnode>v[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
	for(int i=1;i<=n;i++) v[i].clear();
}

void link(int u,int v,LL flow){
	edge[cnt]=node{head[u],v,flow};
	head[u]=cnt++;
	edge[cnt]=node{head[v],u,0};
	head[v]=cnt++;
}

void dijkstra(int s){
	memset(vis,false,sizeof(vis));
	for(int i=0;i<=n;i++){
		dis[i]=INF;
	}
	dis[s]=0;
	priority_queue<pll,vector<pll>,greater<pll> >q;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<v[u].size();i++){
			vnode t=v[u][i];
			if(dis[u]+t.w<dis[t.to]){
				dis[t.to]=dis[u]+t.w;
				q.push(make_pair(dis[t.to],t.to));
			}
		}
	}
}

bool bfs(){
	memset(dep,0,sizeof(dep));
	dep[st]=1;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(t.flow&&!dep[t.to]){
				dep[t.to]=dep[u]+1;
				q.push(t.to);
			}
		}
	}
	return dep[en];
}

LL dfs(int u,LL fl){
	if(u==en) return fl;
	for(int i=head[u];i;i=edge[i].next){
		node &t=edge[i];
		if(t.flow&&dep[t.to]==dep[u]+1){
			LL x=dfs(t.to,min(t.flow,fl));
			if(x>0){
				t.flow-=x;
				edge[i^1].flow+=x;
				return x;
			}
		}
	}
	dep[u]=-2;
	return 0;
}

LL dinic(){
	LL ans=0;
	while(bfs()){
		while(LL d=dfs(st,INF))
			ans+=d;		
	}
	return ans;
}

int main(){
	FAST_IO;
	while(cin>>n>>m){
		init();
		for(int i=1;i<=m;i++){
			cin>>a[i]>>b[i]>>c[i];
			v[a[i]].push_back(vnode{b[i],c[i]});
			v[b[i]].push_back(vnode{a[i],c[i]});
		}
		dijkstra(1);
		for(int i=1;i<=m;i++){
			if(dis[a[i]]+c[i]==dis[b[i]]){
				link(a[i]+n,b[i],INF);
			}
			if(dis[b[i]]+c[i]==dis[a[i]]){
				link(b[i]+n,a[i],INF);
			}
		}
		//起点和终点流量为INF,根据题意起点和终点不用考虑吞吐量 
		for(int i=1;i<=n;i++){
			LL x;
			cin>>x;
			if(i!=1&&i!=n)
				link(i,i+n,x);
			else 
				link(i,i+n,INF);
		}
		st=1,en=2*n;
		cout<<dinic()<<endl;
	}
	return 0;
}
