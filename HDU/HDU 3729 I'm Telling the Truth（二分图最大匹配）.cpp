#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int M=1e6+5;
const int N=105;

int n;
int link[M];
bool vis[M];
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

void max_match(vector<int> &ans){
	memset(link,-1,sizeof(link));
	//为了使字典序最大
	for(int i=n;i>=1;i--){
		memset(vis,false,sizeof(vis));
		if(dfs(i)) ans.push_back(i);
	}
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<=n;i++) v[i].clear();
        for(int i=1;i<=n;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            for(int j=l;j<=r;j++){
                v[i].push_back(j);
            }
        }
        vector<int>ans;
        max_match(ans);
        sort(ans.begin(),ans.end());
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++){
            printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
        }
    }
    return 0;
}
