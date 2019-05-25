#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int INF=1<<30;
const int N=1e6+5;

struct edge{
	int to,cost;
}; 

vector<edge>eg[N];
int V,E;
bool used[N];//是否在队列中 
int d[N];
int a[N],b[N],c[N];

void spfa(int s){
	for(int i=1;i<=V;i++){
		d[i]=INF;
		used[i]=false;
	}
	d[s]=0;
	
	queue<int>q;
	q.push(s);
	used[s]=true; 
	while(!q.empty()){
		int v=q.front();
		q.pop();
		used[v]=false;
		for(int i=0;i<eg[v].size();i++){
			edge e=eg[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				if(!used[e.to]){
					used[e.to]=true;
					q.push(e.to);
				}
			}
		}
	}	
} 

int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&V,&E);
		for(int i=1;i<=V;i++){
			eg[i].clear();
		}
		for(int i=1;i<=E;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			edge gg;
			gg.to=b[i],gg.cost=c[i];
			eg[a[i]].push_back(gg);
		}
		spfa(1);
		long long sum=0;
		for(int i=1;i<=V;i++){
			sum+=d[i];
		}
		//方向反一下 
		for(int i=1;i<=V;i++){
			eg[i].clear();
		}
		for(int i=1;i<=E;i++){
			edge gg;
			gg.to=a[i],gg.cost=c[i];
			eg[b[i]].push_back(gg);
		}
		spfa(1);
		for(int i=1;i<=V;i++){
			sum+=d[i];
		}
		printf("%lld\n",sum);
	}
}
