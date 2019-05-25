#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<ll,ll>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int n,k,m,ans;
int dis[N],deg[N];
vector<int>v[N];

int topo(){
	queue<int>q;
	memset(dis,0x3f,sizeof(dis));
	rep(i,1,n){
		if(deg[i]==0){
			q.push(i);
			dis[i]=1;
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<v[u].size();i++){
			int t=v[u][i];
			deg[t]--;
			dis[t]=min(dis[t],dis[u]+1);
			if(deg[t]==0)
				q.push(t);
		}
	}
	return dis[k];
}

int main(){
	FAST_IO;
	cin>>n>>k>>m;
	rep(i,1,m){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		deg[b]++;
	}
	cout<<topo()<<endl;
	return 0;
}

