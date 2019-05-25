#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int INF=0x3f3f3f3f;
const int N=205;
const int M=205;

struct node{
	int to,next,flow;
}edge[M*2];

int cnt,st,en;
int head[N],dep[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void addedge(int u,int v,int flow){
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].flow=flow;
	head[u]=cnt++;
}

bool bfs(){
	queue<int>q;
	memset(dep,0,sizeof(dep));
	dep[st]=1;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
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

int dfs(int u,int fl){
	if(u==en) return fl;
	int tmp=0; 
	for(int i=head[u];i;i=edge[i].next){
		node &t=edge[i];
		if((dep[t.to]==dep[u]+1)&&t.flow!=0){
			int x=dfs(t.to,min(fl,t.flow));
			if(x>0){
				t.flow-=x;
				edge[i^1].flow+=x;
				tmp+=x;
				return x;
			}
		}
	}
	if(!tmp) dep[u]=-2;//Õ¨µãÓÅ»¯ 
	return 0;
}

int dinic(){
	int ans=0;
	while(bfs()){
		while(int d=dfs(st,INF))
			ans+=d;
	}
	return ans;
}

int main(){
	FAST_IO;
	int n,m;
	while(cin>>m>>n){
		init();
		for(int i=1;i<=m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			addedge(a,b,c);
			addedge(b,a,0);
		}
		st=1,en=n;
		cout<<dinic()<<endl;
	}
	return 0;
}

