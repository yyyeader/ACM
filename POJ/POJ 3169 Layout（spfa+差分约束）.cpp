#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1e3+5;
const int INF=0x3f3f3f3f;
const int MAXN=3e4+5;

struct node{
	int to,w,next;
}edge[MAXN];

int n,idx;
int head[N],dis[N],qcnt[N];
bool vis[N];

void init(){
	idx=1;
	memset(head,-1,sizeof(head));
}

void addedge(int u,int v,int w){
	edge[idx].w=w;
	edge[idx].to=v;
	edge[idx].next=head[u];
	head[u]=idx;
	idx++;
}

bool spfa(int s) {
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		vis[k]=false;
		for(int i=head[k];i!=-1;i=edge[i].next){
			node t=edge[i];
			if(dis[k]+t.w<dis[t.to]){
				dis[t.to]=dis[k]+t.w;
				if(!vis[t.to]){
					q.push(t.to);
					qcnt[t.to]++;
					if(qcnt[t.to]>=n)
						return false;
					vis[t.to]=true;
				}
			}
		}
	}
	return true;
}

int main(){
	init();
	int ml,md;
	scanf("%d%d%d",&n,&ml,&md);
	int a,b,c;
	for(int i=1;i<=ml;i++){
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);			//b-a<=c 
	}
	for(int i=1;i<=md;i++){
		scanf("%d%d%d",&a,&b,&c);
		addedge(b,a,-c);		//b-a>=c → a-b<=-c都改成小于的形式 
	}
	for(int i=1;i<=n-1;i++){
		addedge(i+1,i,0);		//默认的dis[i+1]-dis[i]>=0
	}
	if(!spfa(1))
		puts("-1");
	else if(dis[n]==INF)
		puts("-2");
	else
		printf("%d\n",dis[n]-dis[1]);
	return 0;
}
