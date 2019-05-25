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
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=5e4+5;
const int M=1e6+5;
const int MOD=300;
const int INF=0x3f3f3f3f;

int root[N],val[N];

void init(int n){
	for(int i=0;i<=n;i++) root[i]=i;
	memset(val,0,sizeof(val));
}

int find(int x){
	int tmp=root[x];
	if(x!=root[x])
		root[x]=find(root[x]);
	val[x]=(val[x]+val[tmp])%MOD;
	return root[x];
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		init(n);
		int ans=0;
		for(int i=1;i<=m;i++){
			int a,b,x;
			scanf("%d%d%d",&a,&b,&x);
			int t1=find(a),t2=find(b);
			if(t1==t2){
				if(val[b]!=(val[a]+x)%MOD)
					ans++;
				continue;
			}
			root[t2]=t1;
			val[t2]=(val[a]-val[b]+x+MOD)%MOD;
		}
		printf("%d\n",ans);
	}
	return 0;
}

