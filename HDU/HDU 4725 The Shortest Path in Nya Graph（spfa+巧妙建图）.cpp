#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+5;
const int INF=0x3f3f3f3f;

struct node{
    int to,next,w;
}edge[5*N];

int n;
int idx,head[N],dis[N],layer[N];//layer[i]��¼��i�������ڵĲ� 
bool vis[N],sign[N];//sign[i]��¼��i���Ƿ��е�

void init(){
	idx=1;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int w){
	edge[idx].to=v;
	edge[idx].w=w;
    edge[idx].next=head[u];
    head[u]=idx; 
    idx++;
}

void spfa(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
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
					vis[t.to]=true;
				}
			}
		}
	}
}

int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		init();
		memset(sign,false,sizeof(sign));
		int m,c;
		scanf("%d%d%d",&n,&m,&c);
		for(int i=1;i<=n;i++){
			scanf("%d",&layer[i]);
			sign[layer[i]]=true;
		}
		for(int i=1;i<=n-1;i++){		//���ڲ������㽨��
			if(sign[i]&&sign[i+1]){		//���������ڲ㶼�е�Ž��� 
				addEdge(i+n,i+n+1,c);
				addEdge(i+n+1,i+n,c);
			} 
		}
		for(int i=1;i<=n;i++){			//����㵽ͬһ��ĵ㽨�� 
			addEdge(layer[i]+n,i,0);	 
			if(layer[i]>1)				//������ڲ������㽨�� 
				addEdge(i,layer[i]+n-1,c);
			if(layer[i]<n)
				addEdge(i,layer[i]+n+1,c);
		}
		
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addEdge(u,v,w);
			addEdge(v,u,w);
		}
		spfa(1);	
		if(dis[n]<INF)
			printf("Case #%d: %d\n",++cas,dis[n]);
		else
			printf("Case #%d: -1\n",++cas);
	}
	return 0;
}
