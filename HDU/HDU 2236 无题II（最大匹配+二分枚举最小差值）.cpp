#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e3+5;
const int INF=0x3f3f3f3f;

int n,m,uN,low,limit;
int link[N];
bool vis[N];

struct node{
    int to,w;
    node(int to,int w):to(to),w(w){}
};
vector<node>v[N];

bool dfs(int u){
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i].to;
		int w=v[u][i].w;
		if(!vis[t]&&low<=w&&w<=low+limit){
			vis[t]=true;
			if(link[t]==-1||dfs(link[t])){
				link[t]=u;
				return true;
			}
		}
	}
	return false;
}

bool max_match(){
	memset(link,-1,sizeof(link));
	int ans=0;
	for(int i=1;i<=uN;i++){
		memset(vis,false,sizeof(vis));
		if(!dfs(i)) return false;
	}
	return true;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,mmax=-INF,mmin=INF;
        scanf("%d",&n);
        for(int i=0;i<=n;i++) v[i].clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int x;
                scanf("%d",&x);
                mmax=max(mmax,x);
                mmin=min(mmin,x);
                v[i].push_back(node(j,x));
            }
        }
        uN=n;
        int l=0,r=mmax-mmin,ans;
        while(l<=r){
            limit=(l+r)/2;
            bool flag=false;
            for(low=mmin;low+limit<=mmax;low++){
                if(max_match()){
                    flag=true;
                    break;
                }
            }
            if(flag){
                ans=limit;
                r=limit-1;
            }
            else l=limit+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
