#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=3e3+5;

int n,m,k;
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
	for(int i=0;i<n;i++){
		memset(vis,false,sizeof(vis));
		if(dfs(i)) ans++;
	}
	return ans;
}

int main(){
	while(~scanf("%d",&n)&&n){
		scanf("%d%d",&m,&k);
		for(int i=0;i<=m+n;i++) v[i].clear();
		for(int i=0;i<k;i++){
			int num,x,y;
			scanf("%d%d%d",&num,&x,&y);
			if(x==0||y==0) continue;
			//注意要将A和B的模式区分开,如A的mode1和B的mode1是不同的
			v[x].push_back(y+n);
		}
		//最小点覆盖=最大匹配数
		printf("%d\n",max_match());
	}
	return 0;
}


