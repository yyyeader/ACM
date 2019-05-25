#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2e3+5;

int dis1[N],dis2[N];
int mp[N][N];
vector<int>v[N];

struct node{
    int pos,flag,dis;
    node(int pos,int flag,int dis):pos(pos),flag(flag),dis(dis){}
};

void init(){
    memset(dis1,0x3f,sizeof(dis1));
    memset(dis2,0x3f,sizeof(dis2));
    memset(mp,0,sizeof(mp));
}

void bfs(int st,int *dis){
    queue<int>q;
    q.push(st);
    dis[st]=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<v[t].size();i++){
            int k=v[t][i];
            if(dis[t]+1<dis[k]){
                dis[k]=dis[t]+1;
                q.push(k);
            }
        }
    }
}

int main(){
    init();
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
        mp[a][b]=mp[b][a]=1;
    }
    bfs(s,dis1);
    bfs(t,dis2);
    int mmin=dis1[t],ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(mp[i][j]) continue;
            if(min(dis1[i]+dis2[j]+1,dis2[i]+dis1[j]+1)>=mmin){
                ans++;
                mp[i][j]=mp[j][i]=1;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

