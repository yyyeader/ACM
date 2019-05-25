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
const int N=1e4+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int next,to,w;
}edge[M*2];

int cnt;
int head[N],dis[N];
LL odd[N],even[N];

void init(){
	cnt=2;
	memset(head,0,sizeof(head));
	memset(odd,0,sizeof(odd));
	memset(even,0,sizeof(even));
}

void add(int u,int v,int w){
	edge[cnt]=node{head[u],v,w};
	head[u]=cnt++;
}

void dfs(int u,int fa){
	if(dis[u]%2==0)
		even[u]++;
	else
		odd[u]++;
	for(int i=head[u];i;i=edge[i].next){
		node t=edge[i];
		if(t.to==fa) continue;
		dis[t.to]=(dis[u]+t.w)%2;
		dfs(t.to,u);
		even[u]+=even[t.to];
		odd[u]+=odd[t.to];
	}
}

/*
三元组(x,y,z)
因为abs(d[x]-d[y])=abs(d[x]-d[z])
所以d[x]与d[z]的奇偶性相同
因为abs(d[x]-d[y])=abs(d[y]-d[z])
所以d[y]与d[x]奇偶性相同
所以d[x]、d[y]、d[z]奇偶性相同
所以分别所有深度为奇数的节点和所有深度为偶数的节点的可重排列之和即可。 
*/

int main(){
	int n;
	while(~scanf("%d",&n)){
		init();
		for(int i=1;i<=n-1;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add(v,u,w);
		}
		dfs(1,-1);
		LL ans=odd[1]*odd[1]*odd[1]+even[1]*even[1]*even[1];
		printf("%lld\n",ans);
	}
	return 0;
}

