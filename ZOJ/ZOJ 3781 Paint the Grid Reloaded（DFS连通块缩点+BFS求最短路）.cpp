#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define lc(a) (a<<1)
#define rc(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)  
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=50+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int n,m,cnt;
int path[N*N],vis[N][N];
int d[4][2]={0,1,1,0,0,-1,-1,0};
char mp[N][N];
vector<int>v[N*N];

bool judge(int x,int y){
	if(x>=1&&y>=1&&x<=n&&y<=m&&!vis[x][y])
		return true;
	return false;
}

void dfs(int x,int y){
	vis[x][y]=cnt;
	for(int i=0;i<4;i++){
		int xx=x+d[i][0];
		int yy=y+d[i][1];
		if(judge(xx,yy)&&mp[x][y]==mp[xx][yy]){
			dfs(xx,yy);
		}			
	}
}

int bfs(int st){
	memset(path,-1,sizeof(path));
	queue<int>q;
	q.push(st);
	path[st]=0;
	while(!q.empty()){
		int k=q.front();
		q.pop();
		for(int i=0;i<v[k].size();i++){
			int t=v[k][i];
			if(path[t]==-1){
				path[t]=path[k]+1;
				q.push(t);
			}
		}
	}
}

int main(){
	FAST_IO;
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		cin>>n>>m;
		for(int i=1;i<=n*m;i++) v[i].clear();
		for(int i=1;i<=n;i++){
			cin>>mp[i]+1;
		}
		cnt=0;
		//找连通块,缩点 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!vis[i][j]){
					++cnt;
					dfs(i,j);
				}
			}
		}
		//连通块间建边 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=0;k<4;k++){
					int xx=i+d[k][0];
					int yy=j+d[k][1];
					if(vis[xx][yy]!=vis[i][j]){
						int t1=vis[i][j],t2=vis[xx][yy];
						v[t1].push_back(t2);
					}
				}
			}
		}
		//枚举每个连通块为起点,每次找出最大路径,找出这些最大路径中的最小值 
		int ans=INF;
		for(int i=1;i<=cnt;i++){
			bfs(i);
			int mmax=-INF;
			for(int j=1;j<=cnt;j++){
				mmax=max(mmax,path[j]);
			}
			ans=min(ans,mmax);
		}
		cout<<ans<<endl;
	}
	return 0;
}
