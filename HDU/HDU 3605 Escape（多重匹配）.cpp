#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+5;
const int M=15;

int n,m;
int link[M][N],lim[M];
bool vis[M];
vector<int>v[N];

bool dfs(int u){
	for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(vis[t]) continue;
        vis[t]=true;
        //��t��ƥ������δ�ﵽ���ޣ���ֱ��ƥ��
		if(link[t][0]<lim[t]){
            link[t][++link[t][0]]=u;
            return true;
		}
		//Ѱ������·
		for(int i=1;i<=lim[t];i++){
            if(dfs(link[t][i])){
                link[t][i]=u;
                return true;
            }
		}
	}
	return false;
}

//����ƥ��
bool mul_match(){
	for(int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
		if(!dfs(i)) return false;
	}
	return true;
}

void init(){
    for(int i=0;i<=n;i++) v[i].clear();
    for(int i=1;i<=m;i++) link[i][0]=0;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        init();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x;
                scanf("%d",&x);
                if(x) v[i].push_back(j);
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&lim[i]);
        }
        if(mul_match()) puts("YES");
        else puts("NO");
    }
    return 0;
}
