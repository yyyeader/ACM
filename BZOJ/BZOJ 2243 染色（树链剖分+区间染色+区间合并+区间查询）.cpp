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
const int N=3e5+5;

struct tnode{
    int l,r,lazy;
    int lcol,rcol,sum;//分别代表左右端点颜色、区间不同颜色的和 
}tree[N<<2];

vector<int>v[N];
int cnt,m,n,ans,Lc,Rc;//Lc和Rc表示当前链的左右端点颜色
int dfn[N],sze[N],son[N],dep[N],fa[N],top[N],col[N],rk[N];

void init(){
    cnt=0;
    for(int i=1;i<=n;i++) v[i].clear();
    clr(son,-1);
    clr(fa,-1);
    clr(dep,0);
}

void pushup(int p){
    tnode &lc=tree[lc(p)],&rc=tree[rc(p)],&tp=tree[p];
    tp.sum=lc.sum+rc.sum;
    if(lc.rcol==rc.lcol) tp.sum--;
    tp.lcol=lc.lcol;
    tp.rcol=rc.rcol; 
}

void pushdown(int p){
    if(tree[p].lazy!=-1){
        tnode &lc=tree[lc(p)],&rc=tree[rc(p)],&tp=tree[p];
        lc.lcol=lc.rcol=rc.lcol=rc.rcol=lc.lazy=rc.lazy=tp.lazy;
        lc.sum=rc.sum=1;
        tp.lazy=-1;
    }
}

void build(int p,int l,int r){
    tree[p].l=l;
    tree[p].r=r;
    tree[p].lazy=-1;
    if(l==r){
        tree[p].lcol=tree[p].rcol=col[rk[l]];
        tree[p].sum=1;
        return;
    }
    int mid=MID(l,r);
    build(lc(p),l,mid);
    build(rc(p),mid+1,r);
    pushup(p);
}

void update(int p,int l,int r,int c){
    if(tree[p].l>r||tree[p].r<l)
        return;
    if(l<=tree[p].l&&tree[p].r<=r){
        tree[p].lazy=tree[p].lcol=tree[p].rcol=c;
        tree[p].sum=1;
        return;
    }
    pushdown(p);
    update(lc(p),l,r,c);
    update(rc(p),l,r,c);
    pushup(p);
}

void query(int p,int l,int r){
    if(tree[p].l>r||tree[p].r<l)
        return;
    if(tree[p].l==l)
    	Lc=tree[p].lcol;
    if(tree[p].r==r)
    	Rc=tree[p].rcol;  
    if(l<=tree[p].l&&tree[p].r<=r){
		ans+=tree[p].sum;
        return;
    }
    int mid=MID(tree[p].l,tree[p].r);
    pushdown(p);   
	//注意要在pushdown()之后判断，因为访问的子区间的状态还未改变，看了一个多小时。。。 
	if(l<=mid&&r>mid&&tree[lc(p)].rcol==tree[rc(p)].lcol)
    	ans--;
    query(lc(p),l,r);
    query(rc(p),l,r);
    pushup(p);
}

void dfs1(int u){
    sze[u]=1;
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(t!=fa[u]){
            dep[t]=dep[u]+1;
            fa[t]=u;
            dfs1(t);
            sze[u]+=sze[t];
            if(son[u]==-1||sze[son[u]]<sze[t])
                son[u]=t;
        }
    }
}

void dfs2(int u,int tp){
    top[u]=tp;
    dfn[u]=++cnt;
    rk[cnt]=u;
    if(son[u]==-1) return;
    dfs2(son[u],tp);
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(t!=fa[u]&&t!=son[u])
            dfs2(t,t);
    }
}

void change(int x,int y,int c){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])
            swap(x,y);
        update(1,dfn[top[x]],dfn[x],c);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    update(1,dfn[x],dfn[y],c);
}

void _find(int x,int y){
	int ans1=-1,ans2=-1;      //ans1,ans2分别对应x链顶端的颜色、y链顶端的颜色 
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]){
        	swap(x,y);
        	swap(ans1,ans2);
		}
        query(1,dfn[top[x]],dfn[x]);
        if(ans1==Rc)	
        	ans--;			//之前把这里的ans写成了ans1看了一个多小时，吐血。。。 
    	ans1=Lc;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]){
    	swap(x,y);
    	swap(ans1,ans2);
	}
    query(1,dfn[x],dfn[y]);
    if(ans1==Lc)
    	ans--;
    if(ans2==Rc)
    	ans--;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        init();
        for(int i=1;i<=n;i++){
            scanf("%d",&col[i]);
        }
        for(int i=1;i<=n-1;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs1(1);
        dfs2(1,1);
        build(1,1,n);
        for(int i=1;i<=m;i++){
            char op[10];
            scanf("%s",op);
            int x,y,c;
            if(op[0]=='Q'){
                scanf("%d%d",&x,&y);
                ans=0; 
                _find(x,y);
                printf("%d\n",ans);
            }
            else{
                scanf("%d%d%d",&x,&y,&c);
                change(x,y,c);
            }
        }
    }
    return 0;
}
