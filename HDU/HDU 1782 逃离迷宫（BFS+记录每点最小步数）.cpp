#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=105;

int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,k,sx,sy,ex,ey;
int a[N][N],vis[N][N][4];
char str[N][N];
bool flag;

void dfs(int x,int y,int dir,int s){
    if(s>k||flag)
        return;
    if(dir==-1)
        ;
    else if(vis[x][y][dir]>s)
        vis[x][y][dir]=s;
    else
        return;
    if(x==ex&&y==ey){
        flag=true;
        return;
    }
    for(int i=0;i<4;i++){
        int xx=x+d[i][0];
        int yy=y+d[i][1];
        if(a[xx][yy])
            continue;
        if(i!=dir&&dir!=-1)
            dfs(xx,yy,i,s+1);
        else
            dfs(xx,yy,i,s);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(vis,0x3f,sizeof(vis));
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                a[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            scanf("%s",str[i]+1);
            for(int j=1;j<=m;j++){
                if(str[i][j]=='.')
                    a[i][j]=0;
            }
        }
        scanf("%d%d%d%d%d",&k,&sy,&sx,&ey,&ex);
        flag=false;
        dfs(sx,sy,-1,0);
        if(flag)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
