#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int N=1e2+5;
const int INF=0x3f3f3f3f;

struct  node2{
	int cost,num;
	node2(){}
	node2(int num,int cost){
		this->cost=cost;
		this->num=num;
	}
};

int lim,n;
int cost[N][N],dis[N];
bool vis[N];

void spfa(int l,int r){
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		vis[k]=false;
		for(int i=1;i<=n;i++){
			if(a[i].lv<l||a[i].lv>r)
				continue;
			if(dis[k]+cost[k][i]<dis[i]){
				dis[i]=dis[k]+cost[k][i];
				if(!vis[i]){
					vis[i]=true;
					q.push(i);
				}
			}
		}	
	}
}

int main(){
	memset(cost,0x3f,sizeof(cost));
	scanf("%d%d",&lim,&n);
	for(int i=1;i<=n;i++){
		int m;
		scanf("%d%d%d",&a[i].w,&a[i].lv,&m);
		for(int j=1;j<=m;j++){
			int cost,num;
			scanf("%d%d",&num,&cost);
			a[i].v.push_back(node2(num,cost));
		}
	}
	//预处理两点间花费 
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==j)
				continue;
			bool flag=false;
			for(int k=0;k<a[i].v.size();k++){
				node2 t=a[i].v[k];
				if(t.num==j){
					cost[j][i]=t.cost;
					flag=true;
					break;
				}
			}
			if(!flag){
				cost[j][i]=a[i].w;
			}
		}
	}
	int ans=INF;
	//枚举等级区间 
	for(int i=a[1].lv-lim;i<=a[1].lv;i++){
		spfa(i,i+lim);
		if(dis[1]<ans)
			ans=dis[1];
	}
	printf("%d\n",ans);
	return 0;
}
