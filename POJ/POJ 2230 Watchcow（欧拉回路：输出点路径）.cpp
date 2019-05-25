#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define CLR(arr,val)  memset(arr,val,sizeof(arr))
using namespace std;
const int N=1e5+5;
const int M=1e5+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next;
}edge[M];

int idx;;
int head[N];
bool vis[N];

void init(){
	idx=1;
	CLR(head,0);
	CLR(vis,false);
}

void addedge(int u,int v){
	edge[idx].to=v;
	edge[idx].next=head[u];
	head[u]=idx++;
}

void dfs(int u){
	for(int &j=head[u];j;j=edge[j].next){
		node t=edge[j];
		if(!vis[j]){
			vis[j]=true;
			dfs(t.to);
			//不知道这样为什么错。。。先记着吧 
			//printf("%d\n",t.to);
		}
	}
	printf("%d\n",u);
}

int main(){
	init();
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addedge(a,b);
		addedge(b,a);
	}
	dfs(1);
	return 0;
}
