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
const int N=1e3+5;

int dis[N],cost[N][N];
bool used[N];
int V,E;

void dij(int s){
	//≥ı ºªØ 
	for(int i=1;i<=V;i++){
		dis[i]=INF;
		used[i]=false;
	}
	dis[s]=0;
	
	while(true){
		int k=-1;
		for(int i=1;i<=V;i++){
			if(!used[i]&&(k==-1||dis[k]>dis[i]))
				k=i;
		}
		if(k==-1) break;
		used[k]=true;
		for(int i=1;i<=V;i++){
			dis[i]=min(dis[i],dis[k]+cost[k][i]);
		}
	}
}

int main(){
	memset(cost,0x3f,sizeof(cost));
	scanf("%d%d",&E,&V);
	for(int i=1;i<=E;i++){
		int a,b,len;
		scanf("%d%d%d",&a,&b,&len);
		//≈–÷ÿ±ﬂ 
		cost[a][b]=cost[b][a]=min(cost[a][b],len);	
	}
	dij(1);
	printf("%d\n",dis[V]);
	return 0;
}
