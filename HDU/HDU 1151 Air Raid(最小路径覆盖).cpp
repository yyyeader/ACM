#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=205;

int n,m;
int link[N];
bool vis[N];
vector<int>v[N];

bool dfs(int u){
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		if(!vis[t]){
			vis[t]=true;
			if(link[t]==-1||dfs(link[t])){
				link[t]=u;
				return true;
			}
		}
	}
	return false;
}

int max_match(){
	memset(link,-1,sizeof(link));
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));
		if(dfs(i)) ans++;
	}
	return ans;
}

int main(){
	int t;
	while(~scanf("%d",&t)){
		while(t--){
			scanf("%d%d",&n,&m);
			for(int i=0;i<=n;i++) v[i].clear();
			for(int i=1;i<=m;i++){
				int a,b;
				scanf("%d%d",&a,&b);
				v[a].push_back(b);
			}
			//有向无环图的最小路径覆盖=该图的顶点数-该图的最大匹配。
			printf("%d\n",n-max_match());
		}
	}
	return 0;
}

