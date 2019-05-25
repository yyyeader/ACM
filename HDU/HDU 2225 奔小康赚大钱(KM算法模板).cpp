#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3e3+5;
const int INF=0x3f3f3f3f;

int nx,ny,d; //nx,ny��Ӧ�������ϵĵ���
int link[N],lx[N],ly[N];//lx,lyΪ���꣬nx,nyΪx�㼯y�㼯�ĸ���
int g[N][N];            //g[i][j]��ʾ����X�е�i�㵽����Y�е�j��ľ���
bool visx[N],visy[N];

bool dfs(int x){
    visx[x]=true;
    for(int y=0;y<ny;y++){
        if(visy[y]) continue;
        int tmp=lx[x]+ly[y]-g[x][y];
        //tmp=0��ʾ��(x,y)�ڵ�ǰ��ͼ��
        if(tmp==0){
            visy[y]=true;
            if(link[y]==-1||dfs(link[y])){
                link[y]=x;
                return true;
            }
        }
        else d=min(tmp,d);  //dȡ��С
    }
    return false;
}

int KM(){
    //��ʼ��
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
            //����Ҳ�������·����ͨ�����Ķ��꣬���µı߼�����ͼ
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
