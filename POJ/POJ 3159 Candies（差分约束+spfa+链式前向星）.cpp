#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
const int N=2e5+5;

struct node{
    int to,next,w;
}edge[N];

int n,m;
int idx,head[N];
//初始化
void init(){
    idx=1;
    memset(head,-1,sizeof(head));
}
//添加边
void addEdge(int u,int v,int w){
    edge[idx].to=v;
    edge[idx].w=w;
    edge[idx].next=head[u];
    head[u]=idx;
    idx++;
}

int dis[N];
bool vis[N];

void spfa(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	//注意，这题卡spfa，将队列改为栈
	stack<int>sk;
	sk.push(s);
	while(!sk.empty()){
		int k=sk.top();
		sk.pop();
		vis[k]=false;
		for(int i=head[k];i!=-1;i=edge[i].next){
			node t=edge[i];
			//改变了松弛条件
			if(dis[t.to]>dis[k]+t.w){
				dis[t.to]=dis[k]+t.w;
				if(!vis[t.to]){
					sk.push(t.to);
					vis[t.to]=true;
				}
			}
		}
	}
}

int main(){
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		addEdge(a,b,w);
	}
	//糖果是由1号分发
	spfa(1);
	printf("%d\n",dis[n]-dis[1]);
	return 0;
}
