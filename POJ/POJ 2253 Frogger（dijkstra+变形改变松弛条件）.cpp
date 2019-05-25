#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e2+5;
const int INF=0x3f3f3f3f;

struct node{
	double x,y;
}a[N];

int n;
double dis[N];
bool vis[N];

double cal_dis(int i,int j){
	return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
}

void dij(int s){
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++){
		dis[i]=INF;
	}
	dis[s]=0;

	while(1) {
		int k=-1;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&(k==-1||dis[k]>dis[i])){
				k=i;
			}
		}
		if(k==-1)
			break;
		vis[k]=true;
		for(int i=1;i<=n;i++){
			if(i==k)
				continue;
			double mdis=max(dis[k],cal_dis(i,k));
			if(dis[i]>mdis){
				dis[i]=mdis;
			}
		}
	}
}

int main(){
	int cas=0;
	while(~scanf("%d",&n)){
		if(n==0)
			break;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&a[i].x,&a[i].y);
		}
		dij(1);
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",++cas,dis[2]);
	}
	return 0;
}
