#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;

struct qnode{
    int to,id,next;
}q[M*2];

struct node{
    int to,w,next;
}edge[N*2];

int n,m,cnt,num,idx1,idx2;
int res[M],root[N],vis[N],dis[N],head1[N],head2[N];

void addedge(int u,int v,int w){
    edge[idx1].to=v;
    edge[idx1].w=w;
    edge[idx1].next=head1[u];
    head1[u]=idx1++;
}

void addq(int u,int v,int id){
    q[idx2].to=v;
    q[idx2].id=id;
    q[idx2].next=head2[u];
    head2[u]=idx2++;
}

int find(int x){
    return root[x]==x?x:root[x]=find(root[x]);
}

void init(){
    cnt=num=0;
    idx1=idx2=1;
    for(int i=1;i<=n;i++) root[i]=i;
    memset(res,-1,sizeof(res));
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    memset(head1,0,sizeof(head1));
    memset(head2,0,sizeof(head2));
}

void lca(int u,int num){
    //注意这里vis[u]标记的是树的编号,为了判断点是否在同一颗树上
    vis[u]=num;
    //root[u]=u;
    for(int i=head1[u];i;i=edge[i].next){
        node t=edge[i];
        if(!vis[t.to]){
            dis[t.to]=dis[u]+t.w;
            lca(t.to,num);
            root[t.to]=u;
        }
    }
    for(int i=head2[u];i;i=q[i].next){
        qnode t=q[i];
        //属于同一颗树
        if(vis[t.to]==num)
            res[t.id]=dis[t.to]+dis[u]-2*dis[find(t.to)];
    }
}

int main(){
    int t;
    while(~scanf("%d%d%d",&n,&m,&t)){
        init();
        for(int i=1;i<=m;i++){
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            addedge(a,b,w);
            addedge(b,a,w);
        }
        for(int i=1;i<=t;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            addq(a,b,i);
            addq(b,a,i);
        }
        //森林
        for(int i=1;i<=n;i++){
            if(!vis[i]) lca(i,i);
        }
        for(int i=1;i<=t;i++){
            if(res[i]==-1)
                puts("Not connected");
            else
                printf("%d\n",res[i]);
        }
    }
    return 0;
}
