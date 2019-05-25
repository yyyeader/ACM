#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e3+5;
int vis[N][N][5];
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char map[N][N];
int m,n;
bool flag=false;

struct node{
	int x,y,dir,cnt;
}now,t,pre;
//int num=0;
void bfs(int stax,int stay){
	queue<node>q;
	t.x=stax;
	t.y=stay;
	t.dir=-1;
	t.cnt=0;
	q.push(t);
	while(!q.empty()){
		pre=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int x=pre.x+d[i][0];
			int y=pre.y+d[i][1];
			int cnt;
			if(pre.dir==-1)//判断一下上次方向和当前要走的方向的关系 
				cnt=0;
			else if(pre.dir==i)
				cnt=pre.cnt;
			else if(pre.dir!=i)
				cnt=pre.cnt+1;
			if(x<=0||x>m||y<=0||y>n||cnt>2)
				continue;
			if(map[x][y]=='T'){//到达终点 
				flag=true;
				return;
			}
			if(map[x][y]!='S'&&map[x][y]!='.')
				continue;
			if(vis[x][y][i]<=cnt)//这个点这个方向已经有更优方案了 
				continue;
			vis[x][y][i]=cnt;
			now.x=x;
			now.y=y;
			now.dir=i;
			now.cnt=cnt;
//			num++;
//			printf("%d\n",num);
			q.push(now);
		}	
	}
}
int main(){
	int index,indey;
	scanf("%d %d",&m,&n);
	getchar();
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%c",&map[i][j]);
			if(map[i][j]=='S'){
				index=i;
				indey=j;
			}
		}
		getchar();
	}
	memset(vis,0x3f,sizeof(vis));
	bfs(index,indey);
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
} 
