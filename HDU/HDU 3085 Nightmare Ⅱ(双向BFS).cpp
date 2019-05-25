#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=805;

int n,m,t;
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char map[N][N];
int vis[N][N];

struct node{
	int x,y;
}M,G,pre,now,a[3];
queue<node>q[3];

bool judge(int x,int y){
	if(x<1||y<1||x>n||y>m||map[x][y]=='X')
		return false;
	//利用曼哈顿距离判断是否会被鬼抓到 
	for(int i=1;i<=2;i++){
		if(abs(x-a[i].x)+abs(y-a[i].y)<=2*t)
			return false;
	}
	return true;
}

bool bfs(int mark){
	//小技巧，利用size就可以控制出队的都是上一步的，而不会将这一步的也出队，就能实现走3步了。 
	int size=q[mark].size(); 
	while(size--){
		pre=q[mark].front();
		q[mark].pop();
		//鬼在人之前行动，时间每增加1，先判断鬼能不能把人吃掉
		if(!judge(pre.x,pre.y)) 
			continue;
		for(int i=0;i<4;i++){
			int xx=pre.x+d[i][0];
			int yy=pre.y+d[i][1];
			if(!judge(xx,yy))
				continue;
			//遇到不同标记说明两人相遇 
			if(vis[xx][yy]){
				if(vis[xx][yy]!=mark)
					return true;
				else
					continue;
			}
			vis[xx][yy]=mark;
			now.x=xx;
			now.y=yy;
			q[mark].push(now);
		}
	}
	return false;
}

int solve(){
	//清空队列 
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	q[1].push(M);
	q[2].push(G);
	vis[M.x][M.y]=1,vis[G.x][G.y]=2;
	t=0;
	//双向bfs 
	while(!q[1].empty()||!q[2].empty()){
		t++;
		for(int i=1;i<=3;i++){
			if(bfs(1))
				return t;
		}		
		if(bfs(2))
			return t;
	}
	return -1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		//注意用scanf("%c",map[i][j])会超时 
		for(int i=1,cnt=0;i<=n;i++){
			scanf("%s",map[i]+1);
			for(int j=1;j<=m;j++){
				if(map[i][j]=='M')
					M.x=i,M.y=j;
				if(map[i][j]=='G')
					G.x=i,G.y=j;
				if(map[i][j]=='Z')
					a[++cnt].x=i,a[cnt].y=j;
			}
		}
		printf("%d\n",solve());
	}
	return 0;
}
