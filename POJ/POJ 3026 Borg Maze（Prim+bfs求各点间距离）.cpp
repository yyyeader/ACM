#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std; 
const int N=1e2+5;
const int MAXN=1e2+5;
const int INF=0x3f3f3f3f;

int n,m;
int d[4][2]={0,1,0,-1,-1,0,1,0};
int num[N][N],cost[N][N],root[MAXN],low[MAXN];
bool vis[N][N],used[MAXN];
char str[N][N];

struct node{
	int x,y,step;
	node(){}
	node(int x,int y,int step){
		this->x=x;
		this->y=y;
		this->step=step;
	}
}pre;

//(x,y)点到各个点之间的最短距离 
void bfs(int x,int y){
	memset(vis,false,sizeof(vis));
	queue<node>q;
	q.push(node(x,y,0));
	vis[x][y]=true;
	while(!q.empty()){
		pre=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int xx=pre.x+d[i][0];
			int yy=pre.y+d[i][1];
			int t=pre.step+1;
			if(x<=0||y<=0||x>n||y>m||vis[xx][yy]||str[xx][yy]=='#')
				continue;
			if(str[xx][yy]=='S'||str[xx][yy]=='A')
				cost[num[x][y]][num[xx][yy]]=t;
			vis[xx][yy]=true;
			q.push(node(xx,yy,t));
		}
	}
}
//Prim求最小生成树 
int Prim(int cnt){
	memset(used,false,sizeof(used));
	for(int i=1;i<=cnt;i++){
		low[i]=cost[1][i];
	}
	used[1]=true;
	int ans=0;
	for(int i=1;i<cnt;i++){
		int k=-1;
		for(int j=1;j<=cnt;j++){
			if(!used[j]&&(k==-1||low[k]>low[j])){
				k=j;
			}
		}
		if(k==-1||low[k]==INF) return -1;
		ans+=low[k];
		used[k]=true;
		for(int j=1;j<=cnt;j++){
			if(!used[j]&&low[j]>cost[k][j])
				low[j]=cost[k][j];
		}
	}
	return ans;
}

int main(){
	int t;
	char tmp[105];
	scanf("%d",&t);
	while(t--){
		memset(cost,0x3f,sizeof(cost));
		scanf("%d%d",&m,&n);
		//注意行列后面有一大堆空格要用gets()，出题人怕是个智。。。 
		gets(tmp);
		int cnt=0;
		for(int i=1;i<=n;i++){
			gets(str[i]+1);
			for(int j=1;j<=m;j++){
				if(str[i][j]=='S'||str[i][j]=='A')
					num[i][j]=++cnt;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(str[i][j]=='S'||str[i][j]=='A'){
					bfs(i,j);
				}
			}
		}
		printf("%d\n",Prim(cnt));
	}
	return 0;
}
