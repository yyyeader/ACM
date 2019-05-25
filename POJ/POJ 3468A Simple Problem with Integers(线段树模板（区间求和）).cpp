#include<iostream>
#include<cstdio>
#define LL long long
#define lc(p) p<<1
#define rc(p) p<<1|1
#define MID(l,r) ((l+r)>>1)
using namespace std;
const int N=1e5+5;

LL ans;

struct node{
    int l,r;
    LL sum,add;
}tree[N*4];

void pushup(int p){
    tree[p].sum=tree[lc(p)].sum+tree[rc(p)].sum;
}

void pushdown(int p){
    node &lc=tree[lc(p)],&rc=tree[rc(p)],&rt=tree[p];
    lc.sum+=rt.add*(lc.r-lc.l+1);
    rc.sum+=rt.add*(rc.r-rc.l+1);
    lc.add+=rt.add;
    rc.add+=rt.add;
    rt.add=0;
}

void build(int p,int l,int r){
    tree[p].l=l;
    tree[p].r=r;
    tree[p].add=tree[p].sum=0;
    if(l==r){
    	//注意用%lld不然类型不对会报错 
        scanf("%lld",&tree[p].sum);
        return;
    }
    build(lc(p),l,MID(l,r));
    build(rc(p),MID(l,r)+1,r);
    pushup(p);
}

void update(int p,int l,int r,int c){
    if(tree[p].r<l||tree[p].l>r) return;
    if(l<=tree[p].l&&tree[p].r<=r){
        tree[p].sum+=c*(tree[p].r-tree[p].l+1);
        tree[p].add+=c;
        return;
    }
    if(tree[p].add) pushdown(p);
    update(lc(p),l,r,c);
    update(rc(p),l,r,c);
    pushup(p);
}

void query(int p,int l,int r){
    if(tree[p].r<l||tree[p].l>r) return;
    if(l<=tree[p].l&&tree[p].r<=r){
        ans+=tree[p].sum;
        return;
    }
    if(tree[p].add) pushdown(p);
    query(lc(p),l,r);
    query(rc(p),l,r);
}

int main(){
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        build(1,1,n);
        for(int i=1;i<=q;i++){
            char op[5];
            int l,r,c;
            scanf("%s%d%d",&op,&l,&r);
            if(op[0]=='Q'){
                ans=0;
                query(1,l,r);
                printf("%lld\n",ans);
            }
            else{
                scanf("%d",&c);
                update(1,l,r,c);
            }
        }
    }
    return 0;
}
