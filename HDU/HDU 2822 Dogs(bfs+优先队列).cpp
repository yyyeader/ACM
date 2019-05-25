#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e3+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int n,m,sx,sy,ex,ey;
int d[4][2]={0,1,0,-1,1,0,-1,0};
char mp[N][N];
struct node{
	int x,y,dg;
	bool operator <(const node& b)const{
		return dg>b.dg;
	}
};

bool vis[N][N];

int bfs(){
	memset(vis,false,sizeof(vis));
	priority_queue<node>q;
	vis[sx][sy]=true;
	q.push(node{sx,sy,0});
	while(!q.empty()){
		node t=q.top();q.pop();
		if(t.x==ex&&t.y==ey)
			return t.dg;
		rep(i,0,3){
			int x=t.x+d[i][0];
			int y=t.y+d[i][1];
			int dg=t.dg;
			if(x<1||y<1||x>n||y>m)
				continue;
			if(mp[x][y]=='.')
				dg++;
			if(!vis[x][y]){
				vis[x][y]=true;
				q.push(node{x,y,dg});
			}
		}
	}
	return -1;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0) break;
		rep(i,1,n)
			scanf("%s",mp[i]+1);
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		printf("%d\n",bfs());
	}
	return 0;
}

