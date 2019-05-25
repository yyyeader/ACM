#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=1e3+5;
const int M=1e3+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow;
}edge[M*2];

int cnt,st,en;
int head[N],dep[N],a[N],b[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void link(int u,int v,int flow){
	edge[cnt].next=head[u];
	edge[cnt].to=v;
	edge[cnt].flow=flow;
	head[u]=cnt++;
	
	edge[cnt].next=head[v];
	edge[cnt].to=u;
	edge[cnt].flow=0;
	head[v]=cnt++;
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
	int n,m,sum=0;
	cin>>n>>m;
	init();
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]-=m;
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		b[i]-=n;
		sum+=b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			link(i,j+n,19);
		}
	}
	st=0,en=n+m+1;
	for(int i=1;i<=n;i++){
		link(st,i,a[i]);
	}
	for(int i=1;i<=m;i++){
		link(i+n,en,b[i]);
	}
	if(dinic()==sum){
		cout<<"Yes"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int p=(i-1)*m+j;
				if(j==m)
					printf("%d\n",edge[p*2^1].flow+1);
				else
					printf("%d ",edge[p*2^1].flow+1);
			}
		}
	}
	else
		cout<<"No"<<endl;
	return 0;
}

