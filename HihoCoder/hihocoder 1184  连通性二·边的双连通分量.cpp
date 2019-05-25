#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int N=2e4+5;
vector<int>v[N];
stack<int>sk;
int num,cnt;
int low[N],dfn[N],fa[N],ans[N];

void init(){
    cnt=num=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(fa,0,sizeof(fa));
    memset(ans,0,sizeof(ans));
}

void dfs(int u,int f){
    low[u]=dfn[u]=++cnt;
    sk.push(u);
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!dfn[t]){
            dfs(t,u);
            low[u]=min(low[u],low[t]);
        }
        else if(t!=f) low[u]=min(low[u],dfn[t]);      //无向图不需要判断是否在栈中
    }
    // 因为low[u] == dfn[u]，对(parent[u],u)来说有dfn[u] > dfn[ parent[u] ]，因此low[u] > dfn[ parent[u] ]
    // 所以(parent[u],u)一定是一个桥，那么此时栈内在u之前入栈的点和u被该桥分割开
    // 则u和之后入栈的节点属于同一个组
    //最后剩下的一个(或者说第一个)组虽然前面没有割边，但是也适用于这个判断
    if(low[u]==dfn[u]){
        ++num;
        while(!sk.empty()){
            int t=sk.top();
            sk.pop();
            fa[t]=num;                  //将t分配到num组
            if(ans[num]==0||ans[num]>t)
                ans[num]=t;
            if(t==u)
                break;
        }
    }
}

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        init();
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1,-1);
        printf("%d\n",num);
        for(int i=1;i<=n;i++){
            printf("%d%c",ans[fa[i]],i==n?'\n':' ');
        }
    }
    return 0;
}
