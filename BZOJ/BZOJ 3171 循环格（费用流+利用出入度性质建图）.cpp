#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e3+5;
const int M=1e5+5;
const int INF=0x3f3f3f3f;


struct node{
	int next,to,cap,cost,flow;
}edge[M*2];

int cnt,st,en;
int dc[305];
int head[N],dis[N],pre[N];
bool vis[N];
char mp[20][20];
int d[4][2]={-1,0,1,0,0,-1,0,1};

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void link(int u,int v,int cap,int cost){
	edge[cnt]=node{head[u],v,cap,cost,0};
	head[u]=cnt++;
	edge[cnt]=node{head[v],u,0,-cost,0};
	head[v]=cnt++;
}

bool spfa(){
	memset(dis,0x3f,sizeof(dis));
	memset(pre,0,sizeof(pre));
	memset(vis,false,sizeof(vis));
	dis[st]=0;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(t.flow<t.cap&&dis[t.to]>dis[u]+t.cost){
				dis[t.to]=dis[u]+t.cost;
				pre[t.to]=i;
				if(!vis[t.to]){
					vis[t.to]=true;
					q.push(t.to);
				}
			}
		}
	}
	if(dis[en]==INF)
		return false;
	return true;
}

void mcmf(int &flow,int &cost){
	flow=cost=0;
	while(spfa()){
		int mmin=INF;
		for(int i=pre[en];i;i=pre[edge[i^1].to]){
			mmin=min(mmin,edge[i].cap-edge[i].flow);
		}
		for(int i=pre[en];i;i=pre[edge[i^1].to]){
			edge[i].flow+=mmin;
			edge[i^1].flow-=mmin;
			cost+=edge[i].cost*mmin;
		}
		flow+=mmin;
	}
}

int main(){
	FAST_IO;
	int n,m;
	cin>>n>>m;
	init();
	dc['U']=1,dc['D']=2,dc['L']=3,dc['R']=4;
	rep(i,1,n){
		cin>>mp[i]+1;
	} 
	st=0,en=2*n*m+1;
	rep(i,1,n){
		rep(j,1,m){
			link(st,(i-1)*m+j,1,0);
			link((i-1)*m+j+n*m,en,1,0);
			rep(k,0,3){
				int xx=i+d[k][0];
				int yy=j+d[k][1];
				if(xx>n) xx=1;
				if(yy>m) yy=1;
				if(xx<1) xx=n;
				if(yy<1) yy=m;
				//方向相同连容量为1,费用为0的边，否则连容量为0,费用为1的边 
				if(dc[mp[i][j]]==k+1)
					link((i-1)*m+j,(xx-1)*m+yy+n*m,1,0);
				else
					link((i-1)*m+j,(xx-1)*m+yy+n*m,1,1);
			}
		}
	}
	int flow,cost;
	mcmf(flow,cost);
	cout<<cost<<endl;
	return 0;
}

