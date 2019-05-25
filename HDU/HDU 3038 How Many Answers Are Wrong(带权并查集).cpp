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
const int N=1e6+5;
const int M=1e6+5;
const int MOD=2;
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
	val[x]=val[x]+val[tmp];
	return root[x];
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		init(n);
		int ans=0;
		for(int i=1;i<=m;i++){
			int x,y,d;
			scanf("%d%d%d",&x,&y,&d);
			x--;
			int t1=find(x),t2=find(y);
			if(t1==t2){
				if(val[y]-val[x]!=d)
					ans++;
				continue;
			}
			root[t2]=t1;
			val[t2]=val[x]-val[y]+d;
		}
		printf("%d\n",ans);
	}
	return 0;
}

