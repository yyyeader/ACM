#include<iostream>
#include<cstdio>
#include<cstring>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
typedef pair<int,int> p;
const int N=1e6+5;
const int INF=1<<30;//这里不能比1e9小 
struct edge{
	int to,cost;
};

vector<edge>eg[N];
int V,E;
bool used[N];
int d[N];
int a[N],b[N],c[N];

void dijkstra(int s){
	for(int i=1;i<=V;i++){
		d[i]=INF;
		used[i]=false;
	}
	d[s]=0;
	
	priority_queue<p,vector<p>,greater<p> >q;
	q.push(p(0,s));
	while(!q.empty()){
		p p1=q.top();
		q.pop();
		int v=p1.second;
		if(used[v])	continue;
		used[v]=true;
		for(int i=0;i<eg[v].size();i++){
			edge e=eg[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				q.push(p(d[e.to],e.to));
			}
		}
	}
} 

int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&V,&E);
		for(int i=1;i<=V;i++){
			eg[i].clear();
		}
		for(int i=1;i<=E;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			edge gg;
			gg.to=b[i],gg.cost=c[i];
			eg[a[i]].push_back(gg);
		}
		dijkstra(1);
		LL sum=0;
		for(int i=1;i<=V;i++){
			sum+=d[i];
		}
		//将边的方向反一下
		for(int i=1;i<=V;i++){
			eg[i].clear();
		}
		for(int i=1;i<=E;i++){
			edge gg;
			gg.to=a[i],gg.cost=c[i];
			eg[b[i]].push_back(gg);
		}
		dijkstra(1);
		for(int i=1;i<=V;i++){
			sum+=d[i];
		}
		printf("%lld\n",sum);
	}
}
