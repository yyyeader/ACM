#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=505;

int n;
int link[N];
bool vis[N];
vector<int>v[N];

struct node{
    int time,a,b,c,d;
}a[N];

bool dfs(int u){
	for(int i=0;i<v[u].size();i++){
		int t=v[u][i];
		if(!vis[t]){
			vis[t]=true;
			if(link[t]==-1||dfs(link[t])){
				link[t]=u;
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
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=n;i++){
            int h,m;
            scanf("%d:%d %d%d%d%d",&h,&m,&a[i].a,&a[i].b,&a[i].c,&a[i].d);
            a[i].time=h*60+m;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                node t1=a[i],t2=a[j];
                int cost1=abs(t1.a-t1.c)+abs(t1.b-t1.d);
                int cost2=abs(t1.c-t2.a)+abs(t1.d-t2.b);
                if(t1.time+cost1+cost2<t2.time){
                    v[i].push_back(j);
                }
            }
        }
        printf("%d\n",n-max_match());
    }
}
