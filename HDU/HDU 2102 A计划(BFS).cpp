#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=15;

int m,n,T;
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char map[N][N][5];
int vis[N][N][5];

struct node{
	int x,y,z,step;
}pre,now;

bool bfs(){
	queue<node>q;
	now.x=now.y=now.z=1;
	now.step=0;
	q.push(now);
	while(!q.empty()){
		pre=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx=pre.x+d[i][0];
			int yy=pre.y+d[i][1];
			int zz=pre.z;
			int t=pre.step+1;
			if(xx<1||yy<1||zz<1||xx>n||yy>m||zz>2||vis[xx][yy][zz]||map[xx][yy][zz]=='*')
				continue;
			vis[xx][yy][zz]=1;
			if(map[xx][yy][zz]=='#'){
				if(zz==1)
					zz++;
				else
					zz--;
				//注意除了墙，如果另一层是传送机也不行，传来传去无限循环啊~ 
				if(vis[xx][yy][zz]||map[xx][yy][zz]=='*'||map[xx][yy][zz]=='#')
					continue;
				vis[xx][yy][zz]=1;							
			}
			if(map[xx][yy][zz]=='P'){
				if(t<=T)
					return true;
				return false;
			}
			now.x=xx;
			now.y=yy;
			now.z=zz;
			now.step=t;
			q.push(now);					
		}
	}
	return false;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d",&n,&m,&T);
		for(int k=1;k<=2;k++){
			if(k!=1)
				getchar();
			for(int i=1;i<=n;i++){
				getchar();
				for(int j=1;j<=m;j++){
					scanf("%c",&map[i][j][k]);
				}
			}
		}
		if(bfs())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
