#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1e3+5;
const int INF=0x3f3f3f3f;
int n,m;
int chess[N][N],vis[N][N];
int d[4][2]={0,1,0,-1,1,0,-1,0};

struct node{
	int x,y,cost,col,magic;
	node(){}
	node(int a,int b,int c,int d,int e){
		x=a;y=b;cost=c;col=d;magic=e;
	}
}pre,now;

void bfs(){
	queue<node>q;
	now.x=now.y=1;
	now.cost=0;
	now.col=chess[1][1];
	q.push(now);
	while(!q.empty()){	
		pre=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx=pre.x+d[i][0];
			int yy=pre.y+d[i][1];
			int cost=pre.cost;
			int col=pre.col;
			int magic=0;
			if(xx<=0||yy<=0||xx>m||yy>m)
				continue;
			if(chess[xx][yy]==-1){
				cost+=2;
				if(pre.magic==1)
					continue;
				magic=1;
			}
			else if(chess[xx][yy]!=pre.col){
				cost+=1;
				col=chess[xx][yy];
			}
			if(vis[xx][yy]<=cost)
				continue;
			vis[xx][yy]=cost;
			q.push(node(xx,yy,cost,col,magic));	
		}
	}
}

int main(){
	scanf("%d%d",&m,&n);
	memset(vis,0x3f,sizeof(vis));
	memset(chess,-1,sizeof(chess));
	for(int i=1;i<=n;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		chess[x][y]=c;
	}
	vis[1][1]=0;
	bfs();
	if(vis[m][m]==INF)
		puts("-1");
	else
		printf("%d\n",vis[m][m]);
	return 0;
}
