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
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int dis[N];
bool vis[N];

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
		if(u-3>0){
			if(dis[u-3]>dis[u]+3){
				dis[u-3]=dis[u]+3;
				q.push(pii(dis[u-3],u-3));
			}
		}
		if(u*2<=500000){
			if(dis[u*2]>dis[u]+2){
				dis[u*2]=dis[u]+2;
				q.push(pii(dis[u*2],u*2));
			}
		}
	}
}

void spfa(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=false;
		if(u-3>0){
			if(dis[u-3]>dis[u]+3){
				dis[u-3]=dis[u]+3;
				if(!vis[u-3]){
					vis[u-3]=true;
					q.push(u-3);
				}
			}
		}
		if(u*2<=500000){
			if(dis[u*2]>dis[u]+2){
				dis[u*2]=dis[u]+2;
				if(!vis[u*2]){
					vis[u*2]=true;
					q.push(u*2);
				}
			}
		}
	}
}

int main(){
	FAST_IO;
	int n,m;
	cin>>n>>m;
	dij(n);
	//spfa(n);
	if(dis[m]==INF)
		cout<<-1<<endl;
	else
		cout<<dis[m]<<endl;
	return 0;
}

