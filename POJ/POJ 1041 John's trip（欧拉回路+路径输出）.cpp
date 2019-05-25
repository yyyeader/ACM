#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define CLR(arr,val)  memset(arr,val,sizeof(arr))
using namespace std;
const int N=4e3+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,w;
}edge[N];

int idx;;
int head[N],used[N],degree[N];
bool vis[N];
stack<int>sk;

void init(){
	idx=1;
	CLR(head,0);
	CLR(vis,false);
	CLR(degree,0);
}

void addedge(int u,int v,int w){
	edge[idx].to=v;
	edge[idx].w=w;
	edge[idx].next=head[u];
	head[u]=idx++;
}

void dfs(int u){
	for(int &j=head[u];j;j=edge[j].next){
		node t=edge[j];
		if(!vis[t.w]){
			vis[t.w]=true;
			dfs(t.to);
			sk.push(t.w);
		}
	}
}

int main(){
	int a,b,c;
	while(~scanf("%d%d",&a,&b)){
		if(a==0&&b==0)
			break;
		scanf("%d",&c);
		init();
		int cnt=1;
		addedge(a,b,c);addedge(b,a,c);
		degree[b]++;degree[a]++;
		while(~scanf("%d%d",&a,&b)){
			if(a==0&&b==0)
				break;
			scanf("%d",&c);
			cnt++;
			addedge(a,b,c);addedge(b,a,c);
			degree[b]++;degree[a]++;
		}
		bool flag=true;
		for(int i=1;i<45;i++){
			if(head[i]!=0){
				if(degree[i]%2)
					flag=false;
			}
		}
		if(flag){
			dfs(1);
			if(sk.size()!=cnt){
				puts("Round trip does not exist.");
				return 0;
			}
			while(!sk.empty()){
				if(sk.size()==1)
					cout<<sk.top()<<endl;
				else
					cout<<sk.top()<<" ";
				sk.pop();
			}
		}
		else
			puts("Round trip does not exist.");
	}
	return 0;
}
