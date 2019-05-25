#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=35;

int n,m,h,ans;
int d[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};//三维,相比于二维bfs仅多了向上和向下两个方向  
char map[N][N][N];
int vis[N][N][N];

struct node{
	int x,y,z,step;
}pre,now;

void bfs(int x,int y,int z){
	queue<node>q;
	now.x=x;
	now.y=y;
	now.z=z;
	now.step=0;
	q.push(now);
	while(!q.empty()){
		pre=q.front();
		q.pop();
		for(int i=0;i<6;i++){
			int xx=pre.x+d[i][0];
			int yy=pre.y+d[i][1];
			int zz=pre.z+d[i][2];
			if(xx<1||yy<1||zz<1||xx>n||yy>m||zz>h)
				continue;
			if(vis[xx][yy][zz]||map[xx][yy][zz]=='#')
				continue;
			if(map[xx][yy][zz]=='E'){
				ans=pre.step+1;
				return;
			}
			now.x=xx;
			now.y=yy;
			now.z=zz;
			now.step=pre.step+1;
			vis[xx][yy][zz]=1; 
			q.push(now);
		}
	}
	return;
}

int main(){
	while(~scanf("%d%d%d",&h,&n,&m)&&(h||n||m)){
		memset(vis,0,sizeof(vis));
		int sx,sy,sz;
		for(int k=1;k<=h;k++){
			if(k!=1)
			getchar();
			for(int i=1;i<=n;i++){
				getchar();
				for(int j=1;j<=m;j++){
					scanf("%c",&map[i][j][k]);
					if(map[i][j][k]=='S'){
						sx=i;sy=j;sz=k;
					}
				}
			}
		}	
		ans=0;
		bfs(sx,sy,sz);
		if(ans)
			printf("Escaped in %d minute(s).\n",ans);
		else
			puts("Trapped!");
	}
}
