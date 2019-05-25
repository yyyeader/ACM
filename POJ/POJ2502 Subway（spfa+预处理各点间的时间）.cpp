#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=3e2+5;
const int INF=0x3f3f3f3f;
struct node{
	double x,y;
	node(){}
	node(int x,int y){
		this->x=x;
		this->y=y;
	}
}a[N];

int cnt;
double cost[N][N],dis[N];
bool vis[N];

double cal_time(int i,int j,int v){
	return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y))/(v*1000)*60;
}

void spfa(int s){
	for(int i=1;i<=cnt;i++){
		dis[i]=INF;
	}
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int k=q.front();
		q.pop();
		vis[k]=false;
		for(int i=1;i<=cnt;i++){
			if(i==k)
				continue;
			if(dis[k]+cost[k][i]<dis[i]){
				dis[i]=dis[k]+cost[k][i];
				if(!vis[i]){
					q.push(i);
					vis[i]=true;
				}
			}
		}
	}
}

int main(){
	for(int i=1;i<N;i++){
		for(int j=1;j<N;j++){
			cost[i][j]=INF;
		}
	}
	double x,y;
	scanf("%lf%lf",&x,&y);
	a[1]=node(x,y);
	scanf("%lf%lf",&x,&y);
	a[2]=node(x,y);
	cnt=2;
	while(scanf("%lf%lf",&x,&y)==2){
		a[++cnt]=node(x,y);
		while(scanf("%lf%lf",&x,&y)){
			if(x==-1&&y==-1)
				break;
			a[++cnt]=node(x,y);
			//先处理地铁站间的时间 
			cost[cnt][cnt-1]=cost[cnt-1][cnt]=cal_time(cnt,cnt-1,40);
		}
	}
	//处理人走路时各点间所需的时间 
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			if(cost[i][j]==INF){
				cost[j][i]=cost[i][j]=cal_time(i,j,10);
			}
		}
	}
	spfa(1);
	//竟然要四舍五入，惨绝人寰！！！ 
	printf("%d\n",(int)(dis[2]+0.5));
	return 0;
} 


