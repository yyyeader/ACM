#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define lc(p) (p<<1)
#define rc(p) (p<<1|1)
#define MID(a,b) ((a+b)>>1)
#define clr(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
const int N=1e4+5;
const int INF=0x3f3f3f3f;

struct tnode{
    int l,r,mmax,mmin,flag;
}tree[N<<2];

struct enode{
    int x,y,w;
    enode(){}
    enode(int x,int y,int w):x(x),y(y),w(w){}
}e[N];

vector<int>v[N];

int n,mmax,cnt;
int dfn[N],son[N],sze[N],top[N],dep[N],fa[N],val[N];

void init(){
    cnt=0;
    for(int i=1;i<=n;i++) v[i].clear();
    clr(son,-1);
    clr(dep,0);
    clr(fa,-1);
    clr(val,0);
    clr(dfn,0);
    clr(sze,0);
    clr(top,-1);
}

void pushup(int p){
    tree[p].mmax=max(tree[lc(p)].mmax,tree[rc(p)].mmax);
    tree[p].mmin=min(tree[lc(p)].mmin,tree[rc(p)].mmin);
}

void pushdown(int p){
    tnode &lc=tree[lc(p)],&rc=tree[rc(p)],&tp=tree[p];
    if(tp.flag){
        lc.flag=!lc.flag;
        rc.flag=!rc.flag;
        int t=lc.mmax;
        lc.mmax=-lc.mmin;
        lc.mmin=-t;
        t=rc.mmax;
        rc.mmax=-rc.mmin;
        rc.mmin=-t;
        tp.flag=0;
    }
}

void build(int p,int l,int r){
    tree[p].l=l;
    tree[p].r=r;
    tree[p].flag=0;
    if(l==r){
        tree[p].mmin=tree[p].mmax=val[l];
        return;
    }
    int mid=MID(l,r);
    build(lc(p),l,mid);
    build(rc(p),mid+1,r);
    pushup(p);
}

void update(int p,int l,int r,int op,int add){
    if(tree[p].r<l||tree[p].l>r)
        return;
    if(l<=tree[p].l&&tree[p].r<=r){
        if(op==1)
            tree[p].mmax=tree[p].mmin=add;
        else{
            tree[p].flag=!tree[p].flag;
            int t=tree[p].mmax;
            tree[p].mmax=-tree[p].mmin;
            tree[p].mmin=-t;
        }
        return;
    }
    pushdown(p);
    update(lc(p),l,r,op,add);
    update(rc(p),l,r,op,add);
    pushup(p);
}

void query(int p,int l,int r){
    if(tree[p].r<l||tree[p].l>r)
        return;
    if(l<=tree[p].l&&tree[p].r<=r){
        mmax=max(mmax,tree[p].mmax);
        return;
    }
    pushdown(p);
    query(lc(p),l,r);
    query(rc(p),l,r);
    pushup(p);
}

void dfs1(int u){
    sze[u]=1;
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(t!=fa[u]){
            fa[t]=u;
            dep[t]=dep[u]+1;
            dfs1(t);
            sze[u]+=sze[t];
            if(son[u]==-1||sze[son[u]]<son[t])
                son[u]=t;
        }
    }
}

void dfs2(int u,int tp){
    top[u]=tp;
    dfn[u]=++cnt;
    if(son[u]==-1) return;
    dfs2(son[u],tp);
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(t!=son[u]&&t!=fa[u])
            dfs2(t,t);
    }
}

void _find(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        query(1,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    if(x==y) return;
    if(dep[x]>dep[y])
        swap(x,y);
    query(1,dfn[x]+1,dfn[y]);
}

void Negate(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        update(1,dfn[top[x]],dfn[x],2,0);
        x=fa[top[x]];
    }
    if(x==y) return;
    if(dep[x]>dep[y])
        swap(x,y);
    update(1,dfn[x]+1,dfn[y],2,0);
}

int main(){
    int t;
    while(~scanf("%d",&t)){
        while(t--){
            scanf("%d",&n);
            init();
            for(int i=1;i<=n-1;i++){
                int a,b,w;
                scanf("%d%d%d",&a,&b,&w);
                e[i]=enode(a,b,w);
                v[a].push_back(b);
                v[b].push_back(a);
            }
            dfs1(1);
            dfs2(1,1);
            for(int i=1;i<=n-1;i++){
                if(dep[e[i].x]<dep[e[i].y])
                    swap(e[i].x,e[i].y);
                val[dfn[e[i].x]]=e[i].w;
            }
            build(1,1,n);
            char op[10];
            while(~scanf("%s",op)&&strcmp(op,"DONE")){
                if(op[0]=='Q'){
                    int x,y;
                    scanf("%d%d",&x,&y);
                    mmax=-INF;
                    _find(x,y);
                    printf("%d\n",mmax);
                }
                else if(op[0]=='C'){
                    int id,w;
                    scanf("%d%d",&id,&w);
                    update(1,dfn[e[id].x],dfn[e[id].x],1,w);
                }
                else{
                    int x,y;
                    scanf("%d%d",&x,&y);
                    Negate(x,y);
                }
            }
        }
    }
    return 0;
}
