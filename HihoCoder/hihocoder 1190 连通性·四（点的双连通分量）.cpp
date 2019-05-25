#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int N=2e4+5;			//最大点数
const int M=1e5+5;			//最大边数

struct node{
    int id,to;
    node(int id,int to):id(id),to(to){}
};
vector<node>v[N];
stack<int>sk;
int cnt,num;
int low[N],dfn[N],fa[M],mp[M];
//fa[i]为第i条边所属的点双连通分量编号
//mp[i]为编号为i的点双连通分量里编号最小的编号
//一定注意fa和mp的范围是边数的范围M,不是点数范围N
void tarjan(int u,int f){
    low[u]=dfn[u]=++cnt;
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i].to;
        int id=v[u][i].id;
        if(t==f) continue;
        if(!dfn[t]){	 	//树边
            sk.push(id);	//边入栈
            tarjan(t,u);
            low[u]=min(low[u],low[t]);
            if(dfn[u]<=low[t]){
                num++;
                while(!sk.empty()){
                    int cur=sk.top();
                    sk.pop();
                    fa[cur]=num;                //将cur分配到num组
                    if(mp[num]==0||mp[num]>cur)
                        mp[num]=cur;
                    if(cur==id) break;
                }
            }
        }
        else if(dfn[t]<dfn[u]){//回边
            low[u]=min(low[u],dfn[t]);
            sk.push(id);	//边入栈
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);;
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(node(i,b));
        v[b].push_back(node(i,a));
    }
    tarjan(1,-1);
    printf("%d\n",num);
    for(int i=1;i<=m;i++){
        printf("%d%c",mp[fa[i]],i==m?'\n':' ');
    }
    return 0;
}
