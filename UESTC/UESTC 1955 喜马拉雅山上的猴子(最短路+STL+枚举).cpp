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
const int N=2e3+5;
const int M=1e5+5;
const int INF=0x3f3f3f3f;

struct node{
	int to,w;
};
vector<node>v[N];
vector<node>pre[N];
vector<node>nxt[N];

int dis[N],cost[N][N];
bool vis[N];

bool cmp(node a,node b){
	return a.w>b.w;
}

void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push(pii(0,s));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<v[u].size();i++){
			node t=v[u][i];
			if(dis[t.to]>dis[u]+t.w){
				dis[t.to]=dis[u]+t.w;
				q.push(pii(dis[t.to],t.to));
			}
		}
	}
}

int main(){
	FAST_IO;
	int n,m;
	cin>>n>>m;
	rep(i,1,m){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back(node{b,c});
	}
	rep(i,1,n){
		dij(i);
		rep(j,1,n){
			cost[i][j]=dis[j];
			if(dis[j]!=INF&&i!=j){
				nxt[i].push_back(node{j,dis[j]});
				pre[j].push_back(node{i,dis[j]});
			}
		}
	}
	
	rep(i,1,n){
		sort(pre[i].begin(),pre[i].end(),cmp);
		sort(nxt[i].begin(),nxt[i].end(),cmp);
	}
	int a,b,c,d,mmax=-INF;
	//枚举pre[i]/next[i]取前三个是为了不重复,x->B->C->y中x可能和C或y重复，所以至少要三个 
	rep(i,1,n){
		rep(j,1,n){
			if(i==j||cost[i][j]==INF) continue;
			bool flag=false;
			rep(k,0,(int)pre[i].size()-1){
				rep(p,0,(int)nxt[j].size()-1){
					node t1=pre[i][k],t2=nxt[j][p];
					if(t1.to!=t2.to&&t1.to!=j&&t2.to!=i){
						if(t1.w+cost[i][j]+t2.w>mmax){
							mmax=t1.w+cost[i][j]+t2.w;
							a=t1.to,b=i,c=j,d=t2.to;
						}
						flag=true;
						break;
					}
				}
				if(flag) break;
			}
		}
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	return 0;
}


