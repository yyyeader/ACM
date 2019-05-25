#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int N=2e4+5;
vector<int>v[N];
stack<int>sk;
int num,cnt;
int low[N],dfn[N],fa[N],ans[N];

void init(){
    cnt=num=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(fa,0,sizeof(fa));
    memset(ans,0,sizeof(ans));
}

void dfs(int u,int f){
    low[u]=dfn[u]=++cnt;
    sk.push(u);
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!dfn[t]){
            dfs(t,u);
            low[u]=min(low[u],low[t]);
        }
        else if(t!=f) low[u]=min(low[u],dfn[t]);      //����ͼ����Ҫ�ж��Ƿ���ջ��
    }
    // ��Ϊlow[u] == dfn[u]����(parent[u],u)��˵��dfn[u] > dfn[ parent[u] ]�����low[u] > dfn[ parent[u] ]
    // ����(parent[u],u)һ����һ���ţ���ô��ʱջ����u֮ǰ��ջ�ĵ��u�����ŷָ
    // ��u��֮����ջ�Ľڵ�����ͬһ����
    //���ʣ�µ�һ��(����˵��һ��)����Ȼǰ��û�и�ߣ�����Ҳ����������ж�
    if(low[u]==dfn[u]){
        ++num;
        while(!sk.empty()){
            int t=sk.top();
            sk.pop();
            fa[t]=num;                  //��t���䵽num��
            if(ans[num]==0||ans[num]>t)
                ans[num]=t;
            if(t==u)
                break;
        }
    }
}

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        init();
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1,-1);
        printf("%d\n",num);
        for(int i=1;i<=n;i++){
            printf("%d%c",ans[fa[i]],i==n?'\n':' ');
        }
    }
    return 0;
}
