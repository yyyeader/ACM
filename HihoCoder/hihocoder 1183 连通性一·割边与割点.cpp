#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int N=5e4+5;

struct node{
    int u,v;
    node(int u,int v):u(u),v(v){}
};
vector<int>v[N];
set<int>ans1;
vector<node>ans2;
int n,m,cnt;                          //cntΪdfs��
int low[N],dfn[N];
bool vis[N];

void init(){
    cnt=0;
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(vis,false,sizeof(vis));
    ans2.clear();
    ans1.clear();
    for(int i=1;i<=n;i++) v[i].clear();
}

void gd_and_gb(int u,int f){
    vis[u]=true;
    low[u]=dfn[u]=++cnt;
    int child=0;
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!vis[t]){
            child++;
            gd_and_gb(t,u);
            low[u]=min(low[u],low[t]);
            if(dfn[u]<=low[t]&&f!=-1)                    //�жϸ������,���ܽ����Σ���set
                ans1.insert(u);
            if(dfn[u]<low[t])                            //�жϸ������
                ans2.push_back(node(min(u,t),max(u,t)));

        }
        else if(t!=f) low[u]=min(low[u],dfn[t]);
    }
    if(f==-1&&child>1) ans1.insert(u);                  //���ڵ������ӣ���������������1����Ϊ���
}

bool cmp(node a,node b){
    return a.u==b.u?a.v<b.v:a.u<b.u;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        init();
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        gd_and_gb(1,-1);
        sort(ans2.begin(),ans2.end(),cmp);
        if(ans1.size()==0)
            puts("Null");
        else{
            for(auto it=ans1.begin();it!=ans1.end();it++)
                printf("%d ",*it);
            printf("\n");
        }
        for(int i=0;i<ans2.size();i++){
            printf("%d %d\n",ans2[i].u,ans2[i].v);
        }
    }
    return 0;
}
