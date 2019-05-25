#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e2+5;

int n,m,cnt,idx;
int mp[N][N],link[N],head[N];
bool vis[N];
int d[4][2]={0,1,1,0,-1,0,0,-1};

struct node{
    int x,y;
    node(){}
    node(int x,int y):x(x),y(y){}
}a[N*N];

struct enode{
    int to,next;
}edge[N*N];

void init(){
    cnt=0;
    idx=1;
    memset(mp,0,sizeof(mp));
    memset(head,0,sizeof(head));
}

void addedge(int u,int v){
    edge[idx].to=v;
    edge[idx].next=head[u];
    head[u]=idx++;
}

bool dfs(int u){
    for(int i=head[u];i;i=edge[i].next){
        int t=edge[i].to;
        if(!vis[t]){
            vis[t]=true;
            if(link[t]==-1||dfs(link[t])){
                link[t]=u;
                return true;
            }
        }
    }
    return false;
}

int max_match(){
    memset(link,-1,sizeof(link));
    int ans=0;
    for(int i=1;i<=cnt;i++){
        memset(vis,false,sizeof(vis));
        if(dfs(i)) ans++;
    }
    return ans;
}

int main(){
    while(~scanf("%d%d",&n,&m)&&n&&m){
        init();
        int k;
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            mp[x][y]=-1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]!=-1){
                    mp[i][j]=++cnt;
                    a[cnt]=node(i,j);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //加了(i+j)%2这句分奇偶就对了，不知道为什么不分会错。。。。
                if(mp[i][j]!=-1&&(i+j)%2==1){
                    for(int k=0;k<4;k++){
                        int x=i+d[k][0];
                        int y=j+d[k][1];
                        if(x<=0||y<=0||x>n||y>m||mp[x][y]==-1) continue;
                        addedge(mp[i][j],mp[x][y]);
                    }
                }
            }
        }
        printf("%d\n",max_match());
        vector<node>ans;
        for(int i=1;i<=cnt;i++){
            if(link[i]!=-1){
                ans.push_back(node(i,link[i]));
                link[i]=link[link[i]]=-1;
            }
        }
        for(int i=0;i<ans.size();i++){
            int p1=ans[i].x,p2=ans[i].y;
            printf("(%d,%d)--(%d,%d)\n",a[p1].x,a[p1].y,a[p2].x,a[p2].y);
        }
        printf("\n");
    }
    return 0;
}
