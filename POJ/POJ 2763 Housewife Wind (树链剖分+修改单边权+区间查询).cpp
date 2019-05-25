#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lc(p) (p<<1)
#define rc(p)  (p<<1|1)
#define MID(a,b) ((a+b)>>1)
#define clr(arr,val) memset(arr,val,sizeof(arr))
using namespace std;
const int N=1e5+5;

struct tnode{
    int l,r,sum;
}tree[N<<2];

struct node{
    int to,next;
}edge[N<<1];

struct enode{
    int x,y,w;
}e[N];

int idx,cnt,ans;
int dfn[N],fa[N],son[N],top[N],head[N],sze[N],dep[N],val[N];;

void init(){
    cnt=0;
    idx=1;
    clr(head,0);
    clr(son,-1);
    clr(fa,-1);
    clr(dep,0);
    clr(val,0);
}

void addedge(int u,int v){
    edge[idx].to=v;
    edge[idx].next=head[u];
    head[u]=idx++;
}

void pushup(int p){
    tree[p].sum=tree[lc(p)].sum+tree[rc(p)].sum;
}

void build(int p,int l,int r){
    tree[p].l=l;
    tree[p].r=r;
    if(l==r){
        tree[p].sum=val[l];
        return;
    }
    int mid=MID(l,r);
    build(lc(p),l,mid);
    build(rc(p),mid+1,r);
    pushup(p);
}

void update(int p,int l,int r,int add){
    if(tree[p].l>r||tree[p].r<l)
        return;
    if(l<=tree[p].l&&tree[p].r<=r){
        tree[p].sum=add;
        return;
    }
    update(lc(p),l,r,add);
    update(rc(p),l,r,add);
    pushup(p);
}

void query(int p,int l,int r){
    if(tree[p].l>r||tree[p].r<l)
        return;
    if(l<=tree[p].l&&tree[p].r<=r){
        ans+=tree[p].sum;
        return;
    }
    query(lc(p),l,r);
    query(rc(p),l,r);
}

//构造重边
void dfs1(int u){
    sze[u]=1;
    for(int i=head[u];i;i=edge[i].next){
        node t=edge[i];
        if(t.to!=fa[u]){
            fa[t.to]=u;
            dep[t.to]=dep[u]+1;
            dfs1(t.to);
            sze[u]+=sze[t.to];
            if(son[u]==-1||sze[son[u]]<sze[t.to])
                son[u]=t.to;
        }
    }
}

//构造重链
void dfs2(int u,int tp){
    top[u]=tp;
    dfn[u]=++cnt;
    if(son[u]==-1) return;
    dfs2(son[u],tp);
    for(int i=head[u];i;i=edge[i].next){
        node t=edge[i];
        if(t.to!=fa[u]){
            if(t.to!=son[u])
                dfs2(t.to,t.to);
        }
    }
}

void go_path(int x,int y){
    //将x、y移动到同一条重链上
    while(top[x]!=top[y]){
        //top[x]的深度始终小于top[y]
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        query(1,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    //LCA为当前点则不统计，因为此时的边权不会被访问到
    if(x==y) return;
    if(dep[x]>dep[y])
        swap(x,y);
    query(1,dfn[son[x]],dfn[y]);
}

int main(){
    int n,q,s;
    while(~scanf("%d%d%d",&n,&q,&s)){
        init();
        for(int i=1;i<=n-1;i++){
            int a,b,w;
            scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
            addedge(e[i].x,e[i].y);
            addedge(e[i].y,e[i].x);
        }
        dfs1(1);
        dfs2(1,1);
        //映射树边值到线段树上，如边2->3则val[3]=w
        //因为对于边来说，除了根节点外，其他所有的边都可以与其子节点一一对应
        for(int i=1;i<=n-1;i++){
            if(dep[e[i].x]<dep[e[i].y])
                swap(e[i].x,e[i].y);
            val[dfn[e[i].x]]=e[i].w;
        }
        build(1,1,n);
        for(int i=1;i<=q;i++){
            int op;
            scanf("%d",&op);
            if(op==0){
                int u;
                scanf("%d",&u);
                ans=0;
                go_path(s,u);          //s->x
                s=u;
                printf("%d\n",ans);
            }
            else if(op==1){
                int id,w;
                scanf("%d%d",&id,&w);
                update(1,dfn[e[id].x],dfn[e[id].x],w);
            }
        }
    }
    return 0;
}
