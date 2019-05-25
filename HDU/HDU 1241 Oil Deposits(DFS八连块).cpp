#include<cstdio>
#include<cstring>
const int N=105;

int d[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
int vis[N][N],n,m,cnt;
char map[N][N];

void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<8;i++){
		int xx=x+d[i][0];
		int yy=y+d[i][1];
		if(xx<1||yy<1||xx>n||yy>m||map[xx][yy]=='*'||vis[xx][yy])
			continue;
		dfs(xx,yy);
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)&&(n||m)){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			getchar();
			for(int j=1;j<=m;j++){
				scanf("%c",&map[i][j]);
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!vis[i][j]&&map[i][j]=='@'){
					cnt++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
} 
