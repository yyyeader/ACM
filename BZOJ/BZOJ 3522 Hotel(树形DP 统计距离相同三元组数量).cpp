#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
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
const int N=5e3+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int next,to;
}edge[2*M];

int cnt;
int head[N],dep[N],tmp[N];
LL s1[N],s2[N];//s2[j]表示目前为止距离为j的二元组个数 

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
}

void add(int u,int v){
	edge[cnt]=node{head[u],v};
	head[u]=cnt++;
}

void dfs(int u,int fa) {
	tmp[dep[u]]++;
	for(int i=head[u];i;i=edge[i].next){
		node t=edge[i];
		if(t.to==fa) continue;
		dep[t.to]=dep[u]+1;
		dfs(t.to,u);
	}
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		init();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		LL ans=0;
		for(int i=1;i<=n;i++){
			memset(s1,0,sizeof(s1));
			memset(s2,0,sizeof(s2));
			for(int j=head[i];j;j=edge[j].next){
				int t=edge[j].to;
				dep[t]=1;
				dfs(t,i);
				for(int k=1;k<=n;k++){
					ans+=tmp[k]*s2[k];
					s2[k]+=tmp[k]*s1[k];
					s1[k]+=tmp[k];
				}
				memset(tmp,0,sizeof(tmp));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

