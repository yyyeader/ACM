#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3e3+5;
const int INF=0x3f3f3f3f;

int nx,ny,d; //nx,ny对应两个集合的点数
int link[N],lx[N],ly[N];//lx,ly为顶标，nx,ny为x点集y点集的个数
int g[N][N];            //g[i][j]表示集合X中的i点到集合Y中的j点的距离
bool visx[N],visy[N];

bool dfs(int x){
    visx[x]=true;
    for(int y=0;y<ny;y++){
        if(visy[y]) continue;
        int tmp=lx[x]+ly[y]-g[x][y];
        //tmp=0表示边(x,y)在当前子图中
        if(tmp==0){
            visy[y]=true;
            if(link[y]==-1||dfs(link[y])){
                link[y]=x;
                return true;
            }
        }
        else d=min(tmp,d);  //d取最小
    }
    return false;
}

int KM(){
    //初始化
    memset(link,-1,sizeof(link));
    memset(ly,0,sizeof(ly));
    for(int i=0;i<nx;i++){
        lx[i]=-INF;
        for(int j=0;j<ny;j++){
            if(g[i][j]>lx[i])
                lx[i]=g[i][j];
        }
    }

    for(int x=0;x<nx;x++){
        while(true){
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            d=INF;
            if(dfs(x)) break;
            //如果找不到增广路，则通过更改顶标，将新的边加入子图
            //d=min{lx[i]+ly[i]-w[i][j]}
            for(int i=0;i<nx;i++){
                if(visx[i])
                    lx[i]-=d;
            }
            for(int i=0;i<ny;i++){
                if(visy[i])
                    ly[i]+=d;
            }
        }
    }
    int res=0;
    for(int i=0;i<ny;i++){
        if(link[i]!=-1)
            res+=g[link[i]][i];
    }
    return res;
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&g[i][j]);
            }
        }
        nx=ny=n;
        printf("%d\n",KM());
    }
    return 0;
}
