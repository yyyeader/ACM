#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int next,to,w;
}edge[M*2];

struct qnode{
	LL id,num;
};

int cnt,n,m,k;
int head[N],vis[N];
bool vs[N];
LL dis[N],used[N];//used[i]表示第i条边作为最短路径被经过的次数
vector<qnode>ans;

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
	memset(used,0,sizeof(used));
	memset(vis,false,sizeof(vis));
	ans.clear();
}

void add(int u,int v,int w){
	edge[cnt]=node{head[u],v,w};
	head[u]=cnt++;
}

bool cmp(qnode a,qnode b){
	return a.num>b.num;
}
//spfa会超时 
void dij(int st){
	memset(dis,INF,sizeof(dis));
	dis[st]=0;
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push(pii(0,st));
	while(!q.empty()){
		int u=q.top().second;
		int d=q.top().first;
		q.pop();
		if(d>dis[u]) continue;
		for(int i=head[u];i;i=edge[i].next){
			node t=edge[i];
			if(dis[u]+t.w<dis[t.to]){
				dis[t.to]=dis[u]+t.w;
				q.push(pii(dis[t.to],t.to));
			}
		}
	}
}


int dfs(int u){
	vis[u]=true;
	int sum=1;
	for(int i=head[u];i;i=edge[i].next){
		node t=edge[i];
		if(!vis[t.to]&&dis[u]+t.w==dis[t.to]){
			used[i/2]+=dfs(t.to);
			sum+=used[i/2];
		}
	}
	return sum;
}

int main(){
	while(~scanf("%d%d%d",&n,&m,&k)){
		init();
		for(int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		spfa(1);
		dfs(1);
		for(int i=1;i<=m;i++){
			if(used[i])
				ans.push_back(qnode{i,used[i]});
		}
		//按used进行排序 
		sort(ans.begin(),ans.end(),cmp);
		printf("%d\n",min(k,(int)ans.size()));
		for(int i=0;i<min(k,(int)ans.size());i++){
			if(i!=0)
				printf(" %d",ans[i].id);
			else
				printf("%d",ans[i].id);
		}
		puts("");
	}
	return 0;
}
