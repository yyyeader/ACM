#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+5;
vector<int>v[N];

int n;
int link[N];
bool vis[N];

bool dfs(int u){
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!vis[t]){
            vis[t]=true;
            if(link[t]==-1||dfs(link[t])){ //如果t尚未被匹配，或者link[t]即x可以找到其他能够替代的点,则把t点让给u匹配
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
	for(int i=0;i<n;i++){
		memset(vis,false,sizeof(vis));
		if(dfs(i)) ans++;
	}
	return ans;
}

int main(){
	while(~scanf("%d",&n)){
		for(int i=0;i<=n;i++) v[i].clear();
		memset(link,-1,sizeof(link));
		for(int i=0;i<=n-1;i++){
			int num,t;
			scanf("%d: (%d)",&num,&t);
			for(int j=1;j<=t;j++){
				int x;
				scanf("%d",&x);
				v[num].push_back(x);
			}
		}
		printf("%d\n",n-max_match());
	}
	return 0;
}
