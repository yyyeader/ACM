#include<iostream> 
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1e4+5;

struct node{
	int to,next;
}edge[2*N];

int n,m,idx;
int head[N],vis[N],degree[N],dis[N];

void init(){
	idx=1;
	memset(head,0,sizeof(head));
	memset(degree,0,sizeof(degree));
	memset(dis,0,sizeof(dis));
}

void addedge(int u,int v){
	edge[idx].to=v;
	edge[idx].next=head[u];
	head[u]=idx++;
}

int toposort(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		 if(degree[i]==0)
		 	q.push(i);
	}
	int cnt=0;
	while(!q.empty()){
		int k=q.front();
		q.pop();
		degree[k]--;
		cnt++;
		for(int j=head[k];j;j=edge[j].next){
			node t=edge[j];
			degree[t.to]--;
			dis[t.to]=max(dis[t.to],dis[k]+1);
			if(degree[t.to]==0)
				q.push(t.to);
		}
	}
	int ans=0;
	//ÅÐ¶Ï»· 
	if(cnt!=n)
		 ans=-1;
	else{
		for(int i=1;i<=n;i++)
			ans+=dis[i]+888;
	}
	return ans;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			addedge(b,a);
			degree[a]++;
		}
		printf("%d\n",toposort());
	}
	return 0;
}
