#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e2+5;
const int INF=0x3f3f3f3f;

int ny,nx;
int lx[N],ly[N],link[N],slack[N],g[N][N];
bool visx[N],visy[N];

struct node{
    int x,y;
    node(){}
    node(int x,int y):x(x),y(y){}
}a[N],b[N];

bool dfs(int x){
    visx[x]=true;
    for(int y=0;y<ny;y++){
        if(visy[y]) continue;
        int tmp=lx[x]+ly[y]-g[x][y];
        if(tmp==0){
            visy[y]=true;
            if(link[y]==-1||dfs(link[y])){
                link[y]=x;
                return true;
            }
        }
        else if(slack[y]>tmp)
            slack[y]=tmp;
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
        for(int i=0;i<ny;i++){
            slack[i]=INF;
        }
        while(true){
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(dfs(x)) break;
            int d=INF;
            for(int i=0;i<ny;i++){
                if(!visy[i]&&slack[i]<d)
                    d=slack[i];
            }
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
        if(link[i]!=-1)
            ans+=g[link[i]][i];
    }
    return ans;
}


int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0) break;
        nx=ny=0;
        char str[N];
        for(int i=0;i<n;i++){
            scanf("%s",str);
            for(int j=0;j<m;j++){
                if(str[j]=='m'){
                    a[nx++]=node(i,j);
                }
                else if(str[j]=='H'){
                    b[ny++]=node(i,j);
                }
            }
        }
        for(int i=0;i<nx;i++){
            for(int j=0;j<ny;j++){
                g[i][j]=-(abs(a[i].x-b[j].x)+abs(a[i].y-b[j].y));
            }
        }
        printf("%d\n",-KM());
    }
    return 0;
}

