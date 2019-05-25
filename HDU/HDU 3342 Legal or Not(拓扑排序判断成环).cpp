#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;
const int N=1e2+5;

int n,m;
int vis[N];
bool G[N][N];

bool dfs(int u){
	vis[u]=-1;
	for(int i=0;i<n;i++){
		if(G[u][i]){
			if(vis[i]==-1)
				return false;
			else if(!vis[i]&&!dfs(i))
				return false;
		}
	}
	vis[u]=1;
	return true;
}

bool toposort(){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++){
		if(!vis[i]){
			if(!dfs(i))
				return false;
		}
	}
	return true;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(G,false,sizeof(G));
		if(n==0&&m==0)
			break;
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			G[a][b]=true;
		}
		if(toposort())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
