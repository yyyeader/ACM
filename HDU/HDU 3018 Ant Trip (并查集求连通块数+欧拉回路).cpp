#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define CLR(arr,val)  memset(arr,val,sizeof(arr))
using namespace std; 
const int N=1e6+5;

int n,m;
int deg[N],root[N],num[N];//num[i]记录集合i内的奇数点个数

void init(){
	CLR(deg,0);
	CLR(num,0);
	for(int i=1;i<=n;i++)
		root[i]=i;
}

int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			int u,v,x,y;
			scanf("%d%d",&u,&v);
			x=find(u);
			y=find(v);
			deg[u]++;
			deg[v]++;
			if(x!=y)
				root[x]=y;
		}
		for(int i=1;i<=n;i++){
			if(deg[i]%2==1)
				num[find(i)]++;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(deg[i]==0)
				continue;
			if(find(i)==i){
				if(num[i]==0)
					ans++;
				else
					ans+=num[i]/2;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
