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
const int N=5e4+5;

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
	int n,m;
	while(~scanf("%d%d",&n,&m)&&(m||n)){
		for(int i=0;i<=n-1;i++){
			root[i]=i;
		}
		while(m--){
			int gp;
			scanf("%d",&gp);
			int hd;
			scanf("%d",&hd);
			for(int i=2;i<=gp;i++){
				int x;
				scanf("%d",&x);
				root[find(x)]=find(hd);
			}
		}
		int ans=0;
		for(int i=0;i<=n-1;i++){
			if(find(i)==find(0))
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
