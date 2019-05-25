#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int N=105;
const int INF=0x3f3f3f3f;

struct edge{
	int to,cost;
	edge(){}
	edge(int to,int cost){
		this->to=to;
		this->cost=cost;
	}
};
vector<edge>v[N];

int n;
int dis[N];
bool vis[N];

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
		for(int i=0;i<v[k].size();i++){
			edge t=v[k][i];
			if(dis[k]+t.cost<dis[t.to]){
				dis[t.to]=dis[k]+t.cost;
				if(!vis[t.to]){
					q.push(t.to);
					vis[t.to]=true;
				}
			}
		}
	}
}

int main(){	
	scanf("%d",&n);
	getchar();
	for(int i=2;i<=n;i++){
		char c=getchar();
		int cost,cnt=1;
		while(c!='\n'){
			if(c=='x'||c==' '){
				if(c=='x')
					cnt++;
				c=getchar();
				continue;
			}
			cost=0;			
			while(c>='0'&&c<='9'){
				cost=cost*10+(c-'0');
				c=getchar();
			}
			v[i].push_back(edge(cnt,cost));
			v[cnt].push_back(edge(i,cost));
			cnt++;
		}
	}
	spfa(1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(dis[i]!=INF)
			ans=max(ans,dis[i]);
	}
	printf("%d\n",ans);
	return 0;
}
