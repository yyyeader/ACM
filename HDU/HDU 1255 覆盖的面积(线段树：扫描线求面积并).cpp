#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N=2e3+5;

struct node{
    double x1,x2,h,flag;
    node(){}
    node(double a,double b,double c,double d){
        x1=a;x2=b;h=c;flag=d;
    }
}a[N];

struct Node{
    int l,r,cnt;
    double sum;
}tree[4*N];

double X[N];

bool cmp(node a,node b){
    return a.h<b.h;
}

int bin_search(double num,int l,int r){
    while(l<=r){
        int mid=(l+r)/2;
        if(X[mid]==num)
            return mid;
        else if(X[mid]<num)
            l=mid+1;
        else
            r=mid-1;
    }
}

void pushup(int p){
    tree[p].cnt=(tree[LC(p)].cnt==tree[RC(p)].cnt?tree[LC(p)].cnt:-1);
    tree[p].sum=tree[LC(p)].sum+tree[RC(p)].sum;
}

void pushdown(int p){
    tree[LC(p)].cnt=tree[RC(p)].cnt=tree[p].cnt;
    //由cnt>0改为cnt>1 
    if(tree[p].cnt<=1)
        tree[LC(p)].sum=tree[RC(p)].sum=0;
    else{
        tree[LC(p)].sum=X[tree[LC(p)].r+1]-X[tree[LC(p)].l];
        tree[RC(p)].sum=X[tree[RC(p)].r+1]-X[tree[RC(p)].l];
    }        
}

void build(int p,int l,int r){
    tree[p].l=l;
    tree[p].r=r;
    tree[p].cnt=0;
    if(l==r){
        tree[p].sum=0;
        return;
    }
    build(LC(p),l,MID(l,r));
    build(RC(p),MID(l,r)+1,r);
    pushup(p);
}

void update(int p,int l,int r,int cnt){
    if(l>tree[p].r||r<tree[p].l)
        return;
    if(l<=tree[p].l&&r>=tree[p].r&&tree[p].cnt!=-1){
        tree[p].cnt+=cnt;
        if(tree[p].cnt>=2)
            tree[p].sum=X[tree[p].r+1]-X[tree[p].l];
        else
            tree[p].sum=0;
        return;
    }
    if(tree[p].cnt!=-1)
        pushdown(p);
    update(LC(p),l,r,cnt);
    update(RC(p),l,r,cnt);
    pushup(p);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int m1=0,m2=1;
        for(int i=1;i<=n;i++){
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            X[++m1]=x1;
            a[m1]=node(x1,x2,y1,1);
            X[++m1]=x2;
            a[m1]=node(x1,x2,y2,-1);
        }
        //横坐标离散化 
        sort(a+1,a+1+m1,cmp);
        sort(X+1,X+1+m1);
        for(int i=2;i<=m1;i++){
            if(X[i]!=X[i-1])
                X[++m2]=X[i];
        }
        build(1,1,m2-1);
        double ans=0;
        //依次读入扫描线求重叠两次及以上的面积并 
        for(int i=1;i<=m1-1;i++){
            int l=bin_search(a[i].x1,1,m2);
            int r=bin_search(a[i].x2,1,m2)-1;
            update(1,l,r,a[i].flag); 
            ans+=tree[1].sum*(a[i+1].h-a[i].h);
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
