#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int N=205;

int n,m,ans,cnt;
int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int vis[N][N],resy[N][N],resm[N][N];
char map[N][N];

struct node{
	int x,y,step;
}pre,now;

struct node2{
	int x,y;	
}kfc[N*N];

void bfs(int x,int y,int name){
	queue<node>q;
	now.x=x;
	now.y=y;
	now.step=0;
	q.push(now);
	int num=0;
	while(!q.empty()){
		pre=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx=pre.x+d[i][0];
			int yy=pre.y+d[i][1];
			if(xx<1||yy<1||xx>n||yy>m||map[xx][yy]=='#'||vis[xx][yy])
				continue;
			//打表记录Y、M到各个@点的最小距离 
			if(map[xx][yy]=='@'){
				num++;
				if(name==1)
					resy[xx][yy]=pre.step+1;
				else
					resm[xx][yy]=pre.step+1;
				if(num==cnt)
					return;
			}
			vis[xx][yy]=1;
			now.x=xx;
			now.y=yy;
			now.step=pre.step+1;
			q.push(now);
		}
	}
	return;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(vis,0,sizeof(vis));
		memset(resy,0x3f,sizeof(resy));
		memset(resm,0x3f,sizeof(resm));
		int sx,sy,sxx,syy;
		cnt=0;
		for(int i=1;i<=n;i++){
			getchar();
			for(int j=1;j<=m;j++){
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@')
					kfc[++cnt].x=i,kfc[cnt].y=j;
				if(map[i][j]=='Y')
					sx=i,sy=j;
				if(map[i][j]=='M')
					sxx=i,syy=j;
			}
		}
		bfs(sx,sy,1);
		memset(vis,0,sizeof(vis));
		bfs(sxx,syy,2);
		int ans=1<<30;
		for(int i=1;i<=cnt;i++){
			int x=kfc[i].x;
			int y=kfc[i].y;
			ans=min(ans,resy[x][y]+resm[x][y]);
		}
		printf("%d\n",ans*11);
	}
	return 0;
}
