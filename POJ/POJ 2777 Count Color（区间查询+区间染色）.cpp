#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define lc(p) p<<1
#define rc(p) p<<1|1
#define MID(l,r) ((l+r)>>1)
using namespace std;
const int N=1e5+5;

struct node{
    int l,r,col;
}tree[N*4];

int a[50];

void pushup(int p){
    tree[p].col=tree[lc(p)].col==tree[rc(p)].col?tree[lc(p)].col:-1;
}

void pushdown(int p){
    tree[lc(p)].col=tree[rc(p)].col=tree[p].col;
}

void build(int p,int l,int r){
    tree[p].l=l,tree[p].r=r;
    if(l==r){
        tree[p].col=1;
        return;
    }
    build(lc(p),l,MID(l,r));
    build(rc(p),MID(l,r)+1,r);
    pushup(p);
}

void update(int p,int l,int r,int col){
    if(tree[p].r<l||tree[p].l>r) return;
    if(l<=tree[p].l&&tree[p].r<=r){
        tree[p].col=col;
        return;
    }
    if(tree[p].col!=-1) pushdown(p);
    update(lc(p),l,r,col);
    update(rc(p),l,r,col);
    pushup(p);
}

void query(int p,int l,int r){
    if(tree[p].r<l||tree[p].l>r) return;
    if(tree[p].col!=-1){
        a[tree[p].col]=1;
        return;
    }
    query(lc(p),l,r);
    query(rc(p),l,r);
}

int main(){
    int n,t,q;
    scanf("%d%d%d",&n,&t,&q);
    build(1,1,n);
    for(int i=1;i<=q;i++){
        char op[5];
        int l,r,col;
        scanf("%s%d%d",&op,&l,&r);
        if(l>r) swap(l,r);
        if(op[0]=='C'){
            scanf("%d",&col);
            update(1,l,r,col);
        }
        if(op[0]=='P'){
            memset(a,0,sizeof(a));
            query(1,l,r);
            int ans=0;
            for(int i=1;i<=t;i++){
                ans+=a[i];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
