#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define INF 0x3f3f3f3f
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define FOR(i,start,end) for(int i=start;i<=end;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=5*1e6+123;
typedef long long LL;
LL sum=0;

struct Tree
{
    LL l,r;
    LL gd;
};
Tree tree[N];

void pushup(LL x)
{
    tree[x].gd=__gcd(tree[LC(x)].gd,tree[RC(x)].gd);
}

void build(LL l,LL r,LL x)
{
    tree[x].l=l;
    tree[x].r=r;
    if(l==r)
    {
        scanf("%lld",&tree[x].gd);
        return ;
    }
    LL mid=(l+r)>>1;
    build(l,mid,LC(x));
    build(mid+1,r,RC(x));
    pushup(x);
}

void update(LL l,LL r,LL c,LL x)
{
    if(r<tree[x].l||l>tree[x].r) return ;
    if(l<=tree[x].l&&r>=tree[x].r)
    {
        tree[x].gd=c;
        return ;
    }
    LL mid=(tree[x].l+tree[x].r)>>1;
    if(r<=mid) update(l,r,c,LC(x));
    else if(l>mid) update(l,r,c,RC(x));
    else
    {
        update(l,mid,c,LC(x));
        update(mid+1,r,c,RC(x));
    }
    pushup(x);
}

void query(LL l,LL r,LL x,LL G)
{
	if(sum>1) return;
    if(r<tree[x].l||l>tree[x].r) return;
    if(l<=tree[x].l&&r>=tree[x].r){
        if(tree[x].gd%G==0) return;
        if(tree[x].l==tree[x].r) sum++;
    }
    LL mid=(tree[x].l+tree[x].r)>>1;
    if(r<=mid) query(l,r,LC(x),G);
    else if(l>mid) query(l,r,RC(x),G);
    else
    {
        query(l,mid,LC(x),G);
        query(mid+1,r,RC(x),G);
    }
}

int main(){
    LL n,q,op;
    scanf("%lld",&n);
    build(1,n,1);
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&op);
        if(op==1){
            sum=0;
            LL l,r,x;
            scanf("%lld %lld %lld",&l,&r,&x);
            query(l,r,1,x);
            if(sum>1) printf("NO\n");
            else printf("YES\n");
        }
        else if(op==2){
        	LL l,x;
            scanf("%lld %lld",&l,&x);
            update(l,l,x,1);
        }
    }
    return 0;
}
