#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=2e3+5;
const int M=2e5+5;

struct node{
	LL from,to,w;
	bool operator < (const node& b)const{
		return w<b.w;
	}
}edge[M];

int n,m,root;
int rt[N];
bool used[M];
LL dis[N][N];//dis[i][j]表示最小生成树上i~j路径上的最长边 
vector<node>v[N];

int dfs(int u,int fa){
	for(int i=0;i<v[u].size();i++){
		node t=v[u][i];
		if(t.to==fa) continue;
		dis[root][t.to]=max(dis[root][u],t.w);
		dfs(t.to,u);
	}
}

void init(){
	rep(i,0,n) v[i].clear();
	rep(i,0,n) rt[i]=i;
	memset(used,false,sizeof(used));
	memset(dis,0,sizeof(dis));
}

int find(int x){
	return rt[x]==x?x:rt[x]=find(rt[x]);
}

int main(){
	FAST_IO;
	cin>>n>>m;
	init();
	rep(i,1,m){
		LL a,b,c;
		cin>>a>>b>>c;
		edge[i]=node{a,b,c};
	}
	sort(edge+1,edge+1+m);
	rep(i,1,m){
		node t=edge[i];
		int t1=find(t.from);
		int t2=find(t.to);
		if(t1!=t2){
			rt[t1]=t2;
			used[i]=true;
			v[t.from].push_back(node{0,t.to,t.w});
			v[t.to].push_back(node{0,t.from,t.w});
		}
	}
	//求出最小生成树上任意两点u,v之间的最大边 
	for(int i=1;i<=n;i++){
		root=i;
		dfs(i,-1);
	}
	bool flag=false;
	rep(i,1,m){
		if(used[i]) continue;
		node t=edge[i];
		if(dis[t.from][t.to]==t.w){
			flag=true;
			break;
		}
	}
	if(flag)
		cout<<"zin"<<endl;
	else
		cout<<"ogisosetsuna"<<endl;
	return 0;
}
