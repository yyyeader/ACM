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
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e2+5;
const int M=2e4+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,w;
};
vector<node>v[N];

LL mod;
LL dp[N][M];//dp[i][j]表示"从起点到达i点的距离%mod==j 时的最小距离"
bool vis[N][M];

void spfa(int s){
	memset(dp,0x3f3f3f3f,sizeof(dp));
	memset(vis,false,sizeof(vis));
	queue<pii>q;
	dp[s][0]=0;
	q.push(pll(0,s));
	while(!q.empty()){
		int u=q.front().second;
		LL y=q.front().first;
		q.pop();
		vis[u][y]=false;
		rep(i,0,(int)v[u].size()-1){
			node t=v[u][i];
			LL yy=(y+t.w)%mod;
			if(dp[u][y]+t.w<dp[t.to][yy]){
				dp[t.to][yy]=dp[u][y]+t.w;
				if(!vis[t.to][yy]){
					vis[t.to][yy]=true;
					q.push(pll(yy,t.to));
				}
			}
		}
	}
}

int main(){
	FAST_IO;
	int q;
	cin>>q;
	while(q--){
		LL n,m,t;
		cin>>n>>m>>t;
		rep(i,0,n) v[i].clear();
		rep(i,1,m){
			int a,b,c;
			cin>>a>>b>>c;
			v[a].push_back(node{b,c});
			v[b].push_back(node{a,c});
		}
		
		bool flag=false;
		rep(i,0,(int)v[n].size()-1){
			mod=v[n][i].w*2;
			spfa(1);
			if(dp[n][t%mod]<=t){
				cout<<"Yes"<<endl;
				flag=true;
				break;
			}
		}
		if(!flag)
			cout<<"No"<<endl;
	}
	return 0;
}

