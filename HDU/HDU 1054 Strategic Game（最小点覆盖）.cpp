#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2e3+5;

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
	for(int i=0;i<n;i++){
		memset(vis,false,sizeof(vis));
		if(dfs(i)) ans++;
	}
	return ans;
}

int main(){
    while(~scanf("%d",&n)){
        for(int i=0;i<=n;i++) v[i].clear();
        for(int i=1;i<=n;i++){
            int num,cnt,x;
            scanf("%d:(%d)",&num,&cnt);
            for(int j=1;j<=cnt;j++){
                scanf("%d",&x);
                v[num].push_back(x);
                v[x].push_back(num);
            }
        }
        //最小点覆盖,由于对该二分图进行了补全（无向图），边增加为原来边的二倍。所以最终结果要除以2
        printf("%d\n",max_match()/2);
    }
    return 0;
}
