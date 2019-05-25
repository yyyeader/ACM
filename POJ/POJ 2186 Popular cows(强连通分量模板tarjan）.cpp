#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int N=1e4+5;

int cnt,num;
int dfn[N],low[N],fa[N],sze[N],outdeg[N];  //dfn[i]为点i的dfs序，low[i]为点i能回到的最早的dfs序 
stack<int>sk;							   //fa[i]表示点i所属的强连通分量编号 
vector<int>v[N];

void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    sk.push(u);
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!dfn[t]){                                        //点t未被访问
            tarjan(t);
            low[u]=min(low[u],low[t]);
        }
        else if(!fa[t])  low[u]=min(low[u],dfn[t]);         //点t已被访问，且t还在栈中
    }
    if(low[u]==dfn[u]){
        num++;
        while(1){
            int t=sk.top();
            sk.pop();
            fa[t]=num;                                      //缩点操作，将这些点都归为点num
            sze[num]++;
            if(t==u) break;
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!fa[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            int t=v[i][j];
            if(fa[t]!=fa[i]) outdeg[fa[i]]++;
        }
    }
    //缩点后，出度为0的点只能有一个，否则不符合条件输出0
    int ans=0;
    for(int i=1;i<=num;i++){
        if(!outdeg[i]){
            if(ans>0){
                puts("0");
                return 0;
            }
            ans=sze[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
