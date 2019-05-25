#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int N=5e3+5;

int n,m,cnt,num,uN;
int dfn[N],low[N],fa[N],link[N];
bool vis[N];
stack<int>sk;
vector<int>v[N];
vector<int>g[N];

void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    sk.push(u);
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!dfn[t]){                                        //点t未被访问
            tarjan(t);
            low[u]=min(low[u],low[t]);
        }
        else if(!fa[t])  low[u]=min(low[u],dfn[t]);         //点t已被访问，且t还在栈中
    }
    if(low[u]==dfn[u]){
        num++;
        while(1){
            int t=sk.top();
            sk.pop();
            fa[t]=num;                                      //缩点操作，将这些点都归为点num
            if(t==u) break;
        }
    }
}

bool dfs(int u){
	for(int i=0;i<g[u].size();i++){
		int t=g[u][i];
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
	for(int i=1;i<=uN;i++){
		memset(vis,false,sizeof(vis));
		if(dfs(i)) ans++;
	}
	return ans;
}

void init(){
    cnt=num=0;
    memset(fa,0,sizeof(fa));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    for(int i=0;i<=n;i++){
        v[i].clear();
        g[i].clear();
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        init();
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
        }
        for(int i=1;i<=n;i++){
            if(!dfn[i]) tarjan(i);
        }
        //缩点建新图 
        for(int i=1;i<=n;i++){
            for(int j=0;j<v[i].size();j++){
                int t=v[i][j];
                if(fa[t]!=fa[i]) g[fa[t]].push_back(fa[i]);
            }
        }
        uN=num;
        printf("%d\n",num-max_match());
    }
    return 0;
}
