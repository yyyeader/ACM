#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
const int N=1e2+5;

int m,n,k,lim,ans;
int d[6][2]={{-1,0},{1,0},{0,-1},{0,1},{0,0}};
bool attack[N][N][1005];//判断(x,y)在时间t是否被炮台攻击 
bool vis[N][N][1005];//判断t时刻在(x,y) 的状态是否出现过,判重 

struct node{
	int x,y,step;
}pre,now;

struct node1{
	int c,v,t,x,y;
}a[N];

bool bfs(){
	queue<node>q;
	now.x=0;
	now.y=0;
	now.step=0;
	q.push(now);
	while(!q.empty()){
		pre=q.front();
		q.pop();
		for(int i=0;i<5;i++){		
			int xx=pre.x+d[i][0];
			int yy=pre.y+d[i][1];
			int t=pre.step+1;
			//时间不能超过lim 
			if(t>lim)
				continue;
			if(xx<0||yy<0||xx>n||yy>m)
				continue;
			if(vis[xx][yy][t]||attack[xx][yy][t]||attack[xx][yy][0])
				continue;
			if(xx==n&&yy==m){
				ans=t;
				return true;
			}
			vis[xx][yy][t]=true;
			now.x=xx;
			now.y=yy;
			now.step=t;
			q.push(now);
		}
	}
	return false;
}

int main(){
	while(~scanf("%d%d%d%d",&n,&m,&k,&lim)){
		memset(vis,false,sizeof(vis));
		memset(attack,false,sizeof(attack));
		for(int i=1;i<=k;i++){			
			getchar();
			scanf("%c%d%d%d%d",&a[i].c,&a[i].t,&a[i].v,&a[i].x,&a[i].y);
			//表示这个位置有炮台 
			attack[a[i].x][a[i].y][0]=true;
		}
		
		for(int i=1;i<=k;i++){
			char c;
			int t,v,x,y;
			c=a[i].c,t=a[i].t,v=a[i].v,x=a[i].x,y=a[i].y;
			int idx;
			if(c=='N')
				idx=0;
			if(c=='S')
				idx=1;
			if(c=='W')
				idx=2;
			if(c=='E')
				idx=3;
			int tmp=1;
			while(1){
				int xx=x+d[idx][0]*v*tmp;
				int yy=y+d[idx][1]*v*tmp;
				if(xx<0||yy<0||xx>n||yy>m)
					break;
				bool flag=false;
				//判断中途是否有炮台挡住子弹 
				for(int j=1+v*(tmp-1);j<=v*tmp;j++){
					int tx=x+d[idx][0]*j;
					int ty=y+d[idx][1]*j;
					if(attack[tx][ty][0]){
						flag=true;
						break;
					}
				}
				if(flag)
					break;
				//根据周期，计算被子弹攻击的时间 
				int tt=tmp;	
				while(tt<=1000){
					attack[xx][yy][tt]=true;
					tt+=t;
				}
				tmp++;
			}	
		}
		if(bfs())
			printf("%d\n",ans);
		else
			puts("Bad luck!");
	}
	return 0;
}

