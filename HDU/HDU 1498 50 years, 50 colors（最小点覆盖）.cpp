#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e3+5;

struct node{
	int x,y;
	node(int x,int y):x(x),y(y){}
};

int n,k;
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
	while(~scanf("%d%d",&n,&k)&&n&&k){
		vector<int>ans;
		vector<node>col[N];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int c;
				scanf("%d",&c);
				col[c].push_back(node(i,j));
			}
		}

		for(int i=1;i<=50;i++){
			if(col[i].size()==0) continue;
			for(int j=0;j<=n;j++) v[j].clear();
			//将该颜色点的行和列坐标建图，类似HDU Machine Schedule将对应A、B两台机械的模两种式建图
			for(int j=0;j<col[i].size();j++){
				node t=col[i][j];
				v[t.x].push_back(t.y+n);
			}
			//最小点覆盖
			if(max_match()>k)
				ans.push_back(i);
		}
		if(ans.size()==0)
			puts("-1");
		else{
			sort(ans.begin(),ans.end());
			for(int i=0;i<ans.size();i++){
				printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
			}
		}
	}
	return 0;
}
