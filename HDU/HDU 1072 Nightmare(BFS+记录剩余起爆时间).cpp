#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define CLR(arr,val)  memset(arr,val,sizeof(arr))
using namespace std;
const int N=15;

int d[4][2]={0,1,0,-1,1,0,-1,0};
int str[N][N],vis[N][N];

struct node{
	int x,y,step,time;			//time表示剩余时间 
	node(){}
	node(int x,int y,int step,int time){
		this->x=x;
		this->y=y;
		this->step=step;
		this->time=time;
	}
}pre;

int bfs(int x,int y){
	queue<node>q;
	q.push(node(x,y,0,6));
	vis[x][y]=6;
	while(!q.empty()){
		pre=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx=pre.x+d[i][0];
			int yy=pre.y+d[i][1];
			int t=pre.step+1;
			int time=pre.time-1;
			if(time<=0||str[xx][yy]==0||time<=vis[xx][yy])
				continue;
			if(str[xx][yy]==3)
				return t;
			if(str[xx][yy]==4)
				time=6;
			vis[xx][yy]=time;
			q.push(node(xx,yy,t,time));
		}
	}
	return -1;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		CLR(vis,-1);
		CLR(str,0);
		int sx,sy;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&str[i][j]);
				if(str[i][j]==2)
					sx=i,sy=j;
			}
		}
		printf("%d\n",bfs(sx,sy));
	}
	return 0;
}
