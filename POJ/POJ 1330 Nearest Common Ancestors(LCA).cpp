#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2e4+5;

int x,y;
int root[N];
bool vis[N],in[N];
vector<int>v[N];

int find(int x){
    return root[x]==x?x:root[x]=find(root[x]);
}

void lca(int u){
    vis[u]=true;
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!vis[t]){
            lca(t);
            root[t]=u;
        }
    }
    if(u==x){
        if(vis[y]){
            printf("%d\n",find(y));
            return;
        }
    }
    if(u==y){
        if(vis[x]){
            printf("%d\n",find(x));
            return;
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(vis,false,sizeof(vis));
        memset(in,false,sizeof(in));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            root[i]=i;
            v[i].clear();
        }
        for(int i=1;i<=n-1;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            in[b]=true;
        }
        scanf("%d%d",&x,&y);
        for(int i=1;i<=n;i++){
            if(!in[i])  lca(i);
        }
    }
    return 0;
}
