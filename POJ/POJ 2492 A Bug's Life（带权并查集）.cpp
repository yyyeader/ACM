#include<cstdio>
#include<cmath>
#include<cctype>
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
const int N=2e3+5;
int val[N],root[N];

int find(int x){
	if(root[x]==x)
		return x;
	int tmp=find(root[x]);
	val[x]=(val[x]+val[root[x]])%2;
	return root[x]=tmp;
}

int main(){
	int T,cas=0;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		memset(val,0,sizeof(val));
		for(int i=1;i<=n;i++){
			root[i]=i;
		}
		bool flag=true;
		printf("Scenario #%d:\n",++cas);
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			int t1=find(a);
			int t2=find(b);
			if(t1==t2){
				if(val[a]==val[b])
					flag=false;
			}
			root[t2]=t1;
			val[t2]=(val[a]-val[b]+1+2)%2;
		}
		if(flag)	
			puts("No suspicious bugs found!\n");
		else
			puts("Suspicious bugs found!\n");
	}
	return 0;
}
