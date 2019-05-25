#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e5+5;
vector<int>v[N];
vector<int>Set;

int n,m,cnt;
int link[N],col[N];
bool vis[N];

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
	for(int i=0;i<Set.size();i++){
		memset(vis,false,sizeof(vis));
		int t=Set[i];
		if(dfs(t)) ans++;
	}
	return ans;
}

bool judge(int u){
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!col[t]){
            if(col[u]==1)
                col[t]=2;
            else col[t]=1;
            if(!judge(t)) return false;
        }
        else if(col[t]==col[u])
            return false;
    }
    return true;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<=n;i++) v[i].clear();
		memset(col,0,sizeof(col));
		Set.clear();
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        //染色判断是否为二分图
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(!col[i]){
                col[i]=1;
                if(!judge(i)){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            //计算出其中一个集合的点（没有关联的点集）
            for(int i=1;i<=n;i++){
                if(col[i]==1)
                    Set.push_back(i);
            }
            printf("%d\n",max_match());
        }
        else puts("No");
	}
	return 0;
}
