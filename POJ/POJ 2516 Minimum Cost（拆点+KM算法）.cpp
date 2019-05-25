#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=55;
const int M=205;
const int INF=0x3f3f3f3f;

int nx,ny,d;
int offer[N][N],need[N][N],cost[N][N][N];//cost[k][i][j]表示将第k件物品从供应商j送到老板i的花费
int lx[M],ly[M],link[M],g[M][M],belongA[M],belongB[M];
bool visx[M],visy[M];

bool dfs(int x){
    visx[x]=true;
    for(int y=0;y<ny;y++){
        if(visy[y]||!g[x][y]) continue;
        int tmp=lx[x]+ly[y]-g[x][y];
        if(tmp==0){
            visy[y]=true;
            if(link[y]==-1||dfs(link[y])){
                link[y]=x;
                return true;
            }
        }
        else d=min(d,tmp);
    }
    return false;
}

int KM(){
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
    int ans=0;
    for(int i=0;i<ny;i++){
        if(link[i]!=-1){
            ans+=g[link[i]][i];
        }
    }
    return ans;
}

int main(){
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        if(n==0&&m==0&&k==0) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                scanf("%d",&need[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<k;j++){
                scanf("%d",&offer[i][j]);
            }
        }
        for(int t=0;t<k;t++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    scanf("%d",&cost[t][i][j]);
            }
        }
        bool flag=true;
        //首先对于一种商品，如果这种所有的存货不足需求就直接输出-1
        for(int t=0;t<k;t++){
            int sum1=0,sum2=0;
            for(int i=0;i<n;i++){
                sum1+=need[i][t];
            }
            for(int i=0;i<m;i++){
                sum2+=offer[i][t];
            }
            if(sum1>sum2){
                flag=false;
                break;
            }
        }
        if(!flag){
            puts("-1");
            continue;
        }
        int ans=0;
        for(int t=0;t<k;t++){
            int cntA=0,cntB=0;
            //拆点，
            for(int i=0;i<n;i++){
                for(int j=0;j<need[i][t];j++){
                    belongA[cntA++]=i;
                }
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<offer[i][t];j++){
                    belongB[cntB++]=i;
                }
            }
            for(int i=0;i<cntA;i++){
                for(int j=0;j<cntB;j++){
                    g[i][j]=-cost[t][belongA[i]][belongB[j]];
                }
            }
            nx=cntA,ny=cntB;
            ans+=KM();
        }
        printf("%d\n",-ans);
    }
    return 0;
}
