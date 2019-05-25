#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=5e3+50;		//最大顶点数

int n,m;                //n为顶点数、m为边数
int link[N];            //link[y]=x,即y与x匹配
bool vis[N];
char mp[105][105];
int idx[105][105],idy[105][105];
vector<int>v[N];

//用dfs寻找增广路
bool can(int u){
    for(int i=0;i<v[u].size();i++){
        int t=v[u][i];
        if(!vis[t]){
            vis[t]=true;
            if(link[t]==-1||can(link[t])){ //如果t尚未被匹配，或者link[t]即x可以找到其他能够替代的点,则把t点让给u匹配
                link[t]=u;
                return true;
            }
        }
    }
    return false;
}
//返回最大匹配数
int max_match(){
    memset(link,-1,sizeof(link));
    int ans=0;
    for(int i=1;i<N;i++){
        memset(vis,false,sizeof(vis));
        if(can(i))
            ans++;
    }
    return ans;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	int cnt,sum=0;
	for(int i=1;i<=n;i++){
		bool flag=false;
		cnt=0; 
		for(int j=1;j<=m;j++){	
			if(mp[i][j]=='o'){
				if(flag)
					cnt++,flag=false;
				idx[i][j]=i+cnt*n;
				sum++;
			}
			if(mp[i][j]=='+')
				flag=true;
		}
	}
	for(int j=1;j<=m;j++){
		bool flag=false;
		cnt=0;
		for(int i=1;i<=n;i++){
			if(mp[i][j]=='o'){
				if(flag)
					cnt++,flag=false;
				idy[i][j]=j+cnt*m;
			}
			if(mp[i][j]=='+')
				flag=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='o')
				v[idx[i][j]].push_back(idy[i][j]);
		}
	}
	cout<<sum-max_match()<<endl;
	return 0;
}
