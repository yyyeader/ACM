#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e3+5;

int n;
int link[N];
bool vis[N];
vector<int>v[N];
struct node{
    int x,y;
    node(int x,int y):x(x),y(y){}
};

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
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int x;
                scanf("%d",&x);
                if(x) v[i].push_back(j);
            }
        }
        if(max_match()<n)
            puts("-1");
        else{
            vector<node>ans;
            for(int i=1;i<=n;i++){
                //若link[i]!=i则找到对应的link[j]==i与之交换，满足link[i]=i
                if(link[i]!=i){
                    for(int j=1;j<=n;j++){
                        if(link[j]==i){
                            swap(link[i],link[j]);
                            ans.push_back(node(i,j));
                        }
                    }
                }
            }
            printf("%d\n",ans.size());
            for(int i=0;i<ans.size();i++){
                printf("C %d %d\n",ans[i].x,ans[i].y);
            }
        }
    }
    return 0;
}
