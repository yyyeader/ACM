#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=4e4+5;

struct node{
    int to,w;
    node(int to,int w):to(to),w(w){}
};

struct qnode{
    int to,id;
    qnode(int to,int id):to(to),id(id){}
};

vector<node>v[N];
vector<qnode>q[N];
bool vis[N];                //vis[i]表示点i是否被访问过
int res[N],root[N],dis[N];  //res记录答案

int find(int x){
    return root[x]==x?x:root[x]=find(root[x]);
}

void lca(int u){
    vis[u]=true;
    for(int i=0;i<v[u].size();i++){
        node t=v[u][i];
        if(!vis[t.to]){
            dis[t.to]=dis[u]+t.w;
            lca(t.to);
            root[t.to]=u;
        }
    }
    for(int i=0;i<q[u].size();i++){
        qnode t=q[u][i];
        if(vis[t.to]){
            res[t.id]=dis[u]+dis[t.to]-2*dis[find(t.to)];
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        memset(vis,false,sizeof(vis));
        memset(dis,0,sizeof(dis));
        for(int i=1;i<=n;i++){
            root[i]=i;
            v[i].clear();
        }
        for(int i=1;i<=m;i++){
            q[i].clear();
        }
        for(int i=1;i<=n-1;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            v[a].push_back(node(b,c));
            v[b].push_back(node(a,c));
        }
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            q[a].push_back(qnode(b,i));
            q[b].push_back(qnode(a,i));
        }
        lca(1);
        for(int i=1;i<=m;i++){
            printf("%d\n",res[i]);
        }
    }
    return 0;
}
