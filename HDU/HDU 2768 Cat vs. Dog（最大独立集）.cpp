#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e3+5;
vector<int>v[N];

int n,m,k;
int link[N];
bool vis[N];
char str1[N][10],str2[N][10];

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
	for(int i=1;i<=k;i++){
		memset(vis,false,sizeof(vis));
		if(dfs(i)) ans++;
	}
	return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=k;i++) v[i].clear();
        for(int i=1;i<=k;i++){
            scanf("%s%s",str1[i],str2[i]);
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                //将意见相反的人建边
                if(strcmp(str1[i],str2[j])==0||strcmp(str2[i],str1[j])==0){
                    v[i].push_back(j);
                }
            }
        }
        //求最大独立集
        printf("%d\n",k-max_match()/2);
    }
	return 0;
}
