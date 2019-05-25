#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e3+5;
const int M=5e2+5;

int n,m,limit;
int link[M][N];
bool vis[M];
vector<int>v[N];

bool dfs(int u){
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(vis[t]) continue;
        vis[t]=true;
        if(link[t][0]<limit){
            link[t][++link[t][0]]=u;
            return true;
        }
        for(int i=1;i<=limit;i++){
            if(dfs(link[t][i])){
                link[t][i]=u;
                return true;
            }
        }
    }
    return false;
}
//多重匹配
bool mul_match(){
    for(int i=0;i<=m;i++) link[i][0]=0;
    for(int i=0;i<n;i++){
        memset(vis,false,sizeof(vis));
        if(!dfs(i)) return false;
    }
    return true;
}

int main(){
    while(~scanf("%d%d",&n,&m)&&n&&m){
        for(int i=0;i<=n;i++) v[i].clear();
        char op[25];
        for(int i=0;i<n;i++){
            scanf("%s",op);
            int x;
            while(getchar()==' '){
                scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        //二分枚举上限人数
        int l=1,r=1e3,ans=0;
        while(l<=r){
            limit=(l+r)/2;
            if(mul_match()){
                r=limit-1;
                ans=limit;
            }
            else l=limit+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
