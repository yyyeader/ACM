#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e2+5;
vector<int>v[N*N];

int n,m,xN,yN;
int link[N*N],num[N][N],mp[N][N];
bool vis[N*N];
int dir[][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,0},{0,1},{1,0},{0,-1}};

bool dfs(int u){
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
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
    for(int i=1;i<=xN;i++){
        memset(vis,false,sizeof(vis));
        if(dfs(i)) ans++;
    }
    return ans;
}


bool check(int x,int y){
    if(x<=0||y<=0||x>n||y>m||mp[x][y]==-1) return false;
    return true;
}

 void init(){
    xN=yN=0;
    for(int i=0;i<=n*m;i++) v[i].clear();
 }

int main(){
    int cas=0;
    while(~scanf("%d%d",&n,&m)&&n&&m){
        init();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((i+j)%2==0) num[i][j]=++xN;
                else num[i][j]=++yN;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&mp[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]==-1) continue;
                for(int k=0;k<12;k++){
                    if(mp[i][j]&(1<<k)){
                        int x=i+dir[k][0];
                        int y=j+dir[k][1];
                        if(!check(x,y)) continue;
                        if((i+j)%2==0) v[num[i][j]].push_back(num[x][y]);
                        else v[num[x][y]].push_back(num[i][j]);
                    }
                }
            }
        }
        printf("%d. %d\n",++cas,max_match());
    }
    return 0;
}
