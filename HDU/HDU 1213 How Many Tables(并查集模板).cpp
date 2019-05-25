#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N=1e3+5;

int root[N];

int find(int x){
	int tmp=x;
	while(root[x]!=x){
		x=root[x];
	}
	root[tmp]=x;
	return x;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			root[i]=i;
		}
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			int x=find(a);
			int y=find(b);
			if(x!=y)
				root[x]=y;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(root[i]==i)
				ans++;
		}
		printf("%d\n",ans);
	}
}
