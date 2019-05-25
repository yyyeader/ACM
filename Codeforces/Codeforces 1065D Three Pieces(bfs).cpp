#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int x,y,op,k,t;//(x,y)为坐标,op为当前移动方式,k表示当前已按规则走过k个点,切换了t次走法 
};

int d1[8][2] = {{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}}; //日
int d2[4][2] = {{-1,0},{1,0},{0,1},{0,-1}}; //直线
int d3[4][2] = {{-1,-1},{-1,1},{1,-1},{1,1}}; //斜线
int g[15][15];
int n,sx,sy,ex,ey;
int vis[15][15][3][105][205];

void bfs(){
	memset(vis,0x3f,sizeof(vis));
	queue<node>q;
	for(int i=0;i<3;i++){
		q.push(node{sx,sy,i,1,0});
		vis[sx][sy][i][1][0]=0;
	}
	while(!q.empty()){
		node pre=q.front();
		q.pop();
		int x=pre.x,y=pre.y,op=pre.op,k=pre.k,t=pre.t,step=vis[x][y][op][k][t]+1;
		//cout<<x<<" "<<y<<" "<<op<<" "<<k<<" "<<t<<" "<<step<<endl;
		//换走法
		for(int i=0;i<3;i++){
			if(i==op) continue;
			if(vis[x][y][i][k][t+1]>step){
				vis[x][y][i][k][t+1]=step;
				q.push(node{x,y,i,k,t+1});
			}
		}
		if(op==0){
			for(int i=0;i<8;i++){
				int xx=x+d1[i][0],yy=y+d1[i][1];
				if(xx<1||yy<1||xx>n||yy>n) continue;
				int kk=k;
				if(g[xx][yy]==k+1) kk++;
				if(vis[xx][yy][op][kk][t]>step){
					vis[xx][yy][op][kk][t]=step;
					q.push(node{xx,yy,op,kk,t});
				}
			}
		}
		if(op==1){
			for(int i=1;i<=10;i++){
				for(int j=0;j<4;j++){
					int xx=x+d2[j][0]*i,yy=y+d2[j][1]*i;
					if(xx<1||yy<1||xx>n||yy>n) continue;
					int kk=k;
					if(g[xx][yy]==k+1) kk++;
					if(vis[xx][yy][op][kk][t]>step){
						vis[xx][yy][op][kk][t]=step;
						q.push(node{xx,yy,op,kk,t});
					}
				}
			}
		}
		if(op==2){
			for(int i=1;i<=10;i++){
				for(int j=0;j<4;j++){
					int xx=x+d3[j][0]*i,yy=y+d3[j][1]*i;
					if(xx<1||yy<1||xx>n||yy>n) continue;
					int kk=k;
					if(g[xx][yy]==k+1) kk++;
					if(vis[xx][yy][op][kk][t]>step){
						vis[xx][yy][op][kk][t]=step;
						q.push(node{xx,yy,op,kk,t});
					}
				}
			}
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
			if(g[i][j]==1)
				sx=i,sy=j;
			if(g[i][j]==n*n)
				ex=i,ey=j;
		}
	}
	bfs();
	int ans=INF;
	for(int i=0;i<3;i++){
		for(int j=0;j<=201;j++){
			ans=min(ans,vis[ex][ey][i][n*n][j]);
		}
	}
	int t=INF;
	for(int i=0;i<3;i++){
		for(int j=0;j<=201;j++){
			if(vis[ex][ey][i][n*n][j]==ans){
				t=min(t,j);
			}
		}
	}
	cout<<ans<<" "<<t<<endl;
	return 0;
}

