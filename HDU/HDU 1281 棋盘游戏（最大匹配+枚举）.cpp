#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=205;

struct node{
    int x,y;
}a[N];

int n,m,k;
int link[N],mp[N][N];
bool vis[N];

bool dfs(int u){
	for(int i=1+n;i<=n+m;i++){
		if(mp[u][i]&&!vis[i]){
			vis[i]=true;
			if(link[i]==-1||dfs(link[i])){
				link[i]=u;
				return true;
			}
		}
	}
	return false;
}

int max_match(){
	memset(link,-1,sizeof(link));
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));
		if(dfs(i)) ans++;
	}
	return ans;
}

int main(){
    int cas=0;
    while(~scanf("%d%d%d",&n,&m,&k)){
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=k;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
            a[i].y+=n;
            mp[a[i].x][a[i].y]=1;
        }
        int mmax=max_match(),ans=0;
        //Ã¶¾ÙÉ¾³ýµã
        for(int i=1;i<=k;i++){
            int x=a[i].x,y=a[i].y;
            mp[x][y]=0;
            if(mmax!=max_match())
                ans++;
            mp[x][y]=1;
        }
        printf("Board %d have %d important blanks for %d chessmen.\n",++cas,ans,mmax);
    }
    return 0;
}
