#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
const int N=105;

int n,cnt,num;                            //cnt为当前dfs序，num为缩点编号
int low[N],dfn[N],fa[N],indeg[N],outdeg[N];//dfn为dfs序,low为节点能够通过返回的最早的祖先(注意这里跟求割边割点里的low不同)
vector<int>v[N];                           //fa为节点所属的强联通分量的编号.indeg和outdeg为缩点的入度、出度
stack<int>sk;

void init(){
    cnt=num=0;
    for(int i=1;i<=n;i++){
        v[i].clear();
    }
    memset(fa,0,sizeof(fa));
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(indeg,0,sizeof(indeg));
    memset(outdeg,0,sizeof(outdeg));
}

//求强联通分量
void tarjan(int u){
    low[u]=dfn[u]=++cnt;
    sk.push(u);
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!dfn[t]){                                //未被访问
            tarjan(t);
            low[u]=min(low[u],low[t]);
        }
        else if(!fa[t]) low[u]=min(low[u],dfn[t]); //被访问过且在栈中
    }
    if(low[u]==dfn[u]){
        num++;
        while(!sk.empty()){
            int t=sk.top();
            sk.pop();
            fa[t]=num;
            if(t==u) break;
        }
    }
}

int main(){
    while(~scanf("%d",&n)){
        init();
        for(int i=1;i<=n;i++){
            int x;
            while(~scanf("%d",&x)&&x) v[i].push_back(x);
        }
        for(int i=1;i<=n;i++){              //遍历所有点
            if(!dfn[i]) tarjan(i);
        }
        for(int i=1;i<=n;i++){              //缩点，并求出相应的出度入度是否为0(注意不是求出入度)
            for(int j=0;j<v[i].size();j++){
                int t=v[i][j];
                if(fa[t]!=fa[i]){
                    outdeg[fa[i]]=1;
                    indeg[fa[t]]=1;
                }
            }
        }
        int sum1=0,sum2=0;
        for(int i=1;i<=num;i++){
            if(outdeg[i]==0)
                sum1++;
            if(indeg[i]==0)
                sum2++;
        }
        if(num==1)                          //只有一个点时要特判
            puts("1\n0");
        else printf("%d\n%d\n",sum2,max(sum1,sum2));
    }
    return 0;
}
