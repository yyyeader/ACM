#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define lc(p) (p<<1)
#define rc(p) (p<<1|1)
#define MID(a,b) ((a+b)>>1)
#define clr(arr,val) memset(arr,val,sizeof(arr));
using namespace std;
const int N=1e5+5;

int cnt,n,m,q,ans;
int sze[N],dfn[N],rk[N],son[N],depth[N],fa[N],top[N],a[N];
bool vis[N];
vector<int>v[N];

struct node{
    int l,r,sum,add;
}tree[N<<2];

void init(){
    cnt=0;
    for(int i=1;i<=n;i++) v[i].clear();
    clr(vis,false);
    clr(depth,0);
    clr(son,-1);
    clr(fa,-1);
    clr(top,-1);
}

//记录所有的重（zhong）边
void dfs1(int u){
    vis[u]=true;
    sze[u]=1;
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!vis[t]){
            depth[t]=depth[u]+1;
            fa[t]=u;
            dfs1(t);
            sze[u]+=sze[t];
            if(son[u]==-1||sze[t]>sze[son[u]])
                son[u]=t;
        }
    }
}

//构造重链
void dfs2(int u,int tp){
    top[u]=tp;
    vis[u]=true;
    dfn[u]=++cnt;
    rk[cnt]=u;
    if(son[u]==-1)  return;
    dfs2(son[u],tp);
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(t!=fa[u]){
            if(t!=son[u])
                dfs2(t,t);
        }
    }
}

void pushup(int p){
    tree[p].sum=tree[lc(p)].sum+tree[rc(p)].sum;
}

void pushdown(int p){
    int &tmp=tree[p].add;
    node &lc=tree[lc(p)],&rc=tree[rc(p)];
    lc.add+=tmp;
    rc.add+=tmp;
    lc.sum+=tmp*(lc.r-lc.l+1);
    rc.sum+=tmp*(rc.r-rc.l+1);
    tmp=0;
}

void build(int p,int l,int r){
    tree[p].add=0;
    tree[p].l=l;
    tree[p].r=r;
    if(l==r){
        tree[p].sum=a[rk[l]];
        return;
    }
    int mid=MID(l,r);
    build(lc(p),l,mid);
    build(rc(p),mid+1,r);
    pushup(p);
}

void update(int p,int l,int r,int add){
    if(l>tree[p].r||tree[p].l>r)
        return;
    if(l<=tree[p].l&&tree[p].r<=r){
        tree[p].sum+=add*(tree[p].r-tree[p].r+1);
        tree[p].add+=add;
        return;
    }
    pushdown(p);
    update(lc(p),l,r,add);
    update(rc(p),l,r,add);
    pushup(p);
}

void query(int p,int l,int r){
    if(l>tree[p].r||tree[p].l>r)
        return;
    if(l<=tree[p].l&&tree[p].r<=r){
        ans+=tree[p].sum;
        return;
    }
    pushdown(p);
    query(lc(p),l,r);
    query(rc(p),l,r);
    pushup(p);
}

void change(int x,int y,int add){
    //将x,y移动到同一条重链上
    while(top[x]!=top[y]){
        //top[x]的深度始终大于top[y]
        if(depth[top[x]]<depth[top[y]])
            swap(x,y);
        update(1,dfn[top[x]],dfn[x],add);
        x=fa[top[x]];
    }
    if(depth[x]>depth[y])
        swap(x,y);
    update(1,dfn[x],dfn[y],add);
}

int main(){
    while(~scanf("%d%d%d",&n,&m,&q)){
        init();
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs1(1);
        dfs2(1,1);
        build(1,1,n);
        for(int i=1;i<=q;i++){
            int x,y,k;
            char op[5];
            scanf("%s",op);
            if(op[0]=='I'){
                scanf("%d%d%d",&x,&y,&k);
                change(x,y,k);
            }
            if(op[0]=='D'){
                scanf("%d%d%d",&x,&y,&k);
                change(x,y,-k);
            }
            if(op[0]=='Q'){
                scanf("%d",&k);
                ans=0;
                query(1,dfn[k],dfn[k]);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
