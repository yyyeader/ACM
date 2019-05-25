#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
/* *******************************
 * 二分图匹配（Hopcroft-Carp算法）
 * 复杂度O(sqrt(n)*E)
 * 邻接表存图，vector实现
 * vector先初始化，然后假入边
 * uN 为左端的顶点数,使用前赋值(点编号0开始)
 */
const int N = 3030;
const int INF = 0x3f3f3f3f;
vector<int>G[N];

int uN,dis;
int Mx[N],My[N],dx[N],dy[N];
bool used[N];

struct gnode{
    int x,y,speed;
}guest[N];

struct unode{
    int x,y;
}ubm[N];

bool SearchP()
{
    queue<int>Q;
    dis = INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i = 0 ; i < uN; i++)
        if(Mx[i] == -1)
        {
            Q.push(i);
            dx[i] = 0;
        }
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if(dx[u] > dis)break;
        int sz = G[u].size();
        for(int i = 0;i < sz;i++)
        {
            int v = G[u][i];
            if(dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if(My[v] == -1)dis = dy[v];
                else
                {
                    dx[My[v]] = dy[v] + 1;
                    Q.push(My[v]);
                }
            }
        }
    }
    return dis != INF;
}
bool DFS(int u)
{
    int sz = G[u].size();
    for(int i = 0;i < sz;i++)
    {
        int v = G[u][i];
        if(!used[v] && dy[v] == dx[u] + 1)
        {
            used[v] = true;
            if(My[v] != -1 && dy[v] == dis)continue;
            if(My[v] == -1 || DFS(My[v]))
            {
                My[v] = u;
                Mx[u] = v;
                return true;
            }
        }
    }
    return false;
}

int max_match()
{
    int res = 0;
    memset(Mx,-1,sizeof(Mx));
    memset(My,-1,sizeof(My));
    while(SearchP())
    {
        memset(used,false,sizeof(used));
        for(int i = 0;i < uN;i++)
            if(Mx[i] == -1 && DFS(i))
                res++;
    }
    return res;
}

int main(){
    int q,cas=0;
    scanf("%d",&q);
    while(q--){
        int time,n,m;
        scanf("%d%d",&time,&m);
        for(int i=0;i<=m;i++) G[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&guest[i].x,&guest[i].y,&guest[i].speed);
        }
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&ubm[i].x,&ubm[i].y);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                gnode t1=guest[i];
                unode t2=ubm[j];
                int dis=abs(t1.x-t2.x)+abs(t1.y-t2.y);
                if(1.0*dis/t1.speed<=time) G[i].push_back(j);
            }
        }
        uN=m;
        printf("Scenario #%d:\n%d\n\n",++cas,max_match());
    }
    return 0;
}
