#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e3+5;

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
	while(~scanf("%d",&n)&&n){
        scanf("%d",&m);
        for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int x;
				scanf("%d",&x);
				if(x==1)
                    v[i].push_back(j+n);
			}
		}
		printf("%d\n",max_match());
	}
	return 0;
}
