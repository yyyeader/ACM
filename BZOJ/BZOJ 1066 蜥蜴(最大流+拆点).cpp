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
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,next,flow;
}edge[M*2];

int cnt,st,en;
int head[N],dep[N];
int high[25][25];
char mp[25][25];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void link(int u,int v,int flow){
	edge[cnt]=node{v,head[u],flow};
	head[u]=cnt++;
	edge[cnt]=node{u,head[v],0};
	head[v]=cnt++;
}

int bfs(){
	memset(dep,0,sizeof(dep));
	dep[st]=1;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(t.flow&&!dep[t.to]){
				dep[t.to]=dep[u]+1;
				q.push(t.to);
			}
		}
	}
	return dep[en];
}

int dfs(int u,int fl){
	if(u==en) return fl;
	int tmp=0;
	for(int i=head[u];i&&fl;i=edge[i].next){
		node &t=edge[i];
		if(t.flow&&dep[t.to]==dep[u]+1){
			int x=dfs(t.to,min(t.flow,fl));
			if(x>0){
				t.flow-=x;
				edge[i^1].flow+=x;
				fl-=x;
				tmp+=x;
			}
		}
	}
	if(!tmp) dep[u]=-2;
	return tmp;
}

int dinic(){
	int ans=0;
	while(bfs()){
		while(int d=dfs(st,INF))
			ans+=d;
	}
	return ans;
}

double cal(int x1,int y1,int x2,int y2){
	return sqrt(1.0*(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
	int n,m,d;
	while(~scanf("%d%d%d",&n,&m,&d)){
		init();
		st=0,en=n*m*2+1;
		int sum=0;
		for(int i=1;i<=n;i++){
			scanf("%s",mp[i]+1);
			for(int j=1;j<=m;j++){
				high[i][j]=mp[i][j]-'0';
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%s",mp[i]+1);
			for(int j=1;j<=m;j++){
				if(mp[i][j]=='L'){
					sum++;
					//st与蜥蜴建边 
					link(st,(i-1)*m+j,1);
				}
			}
		}
		int now,next;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!high[i][j]) continue;
				//拆点 
				now=(i-1)*m+j;
				link(now,now+n*m,high[i][j]);
				//与距离小于d的石柱建边 
				for(int k=1;k<=n;k++){
					for(int q=1;q<=m;q++){
						if(i==k&&j==q) continue;
						if(cal(i,j,k,q)<=d&&high[k][q]){
							next=(k-1)*m+q;
							link(now+n*m,next,INF);
						}
					}
				}
				//能够跳出边间的石柱与en建边 
				if(i-1<d||n-i<d||j-1<d||m-j<d){
					link(now+n*m,en,INF);
				}
			}
		}
		int ans=dinic();
		printf("%d\n",sum-ans);
	}
	return 0;
}

