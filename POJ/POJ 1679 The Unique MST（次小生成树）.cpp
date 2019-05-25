#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e2+5;
const int INF=0x3f3f3f3f;

int n,m;
int cost[N][N],low[N],pre[N],Max[N][N];//����Max[i][j]��ʾMST��i��j����Ȩֵ,����Сƿ��· 
bool vis[N];

//����С������������Сƿ��· 
int Prim(){
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++){
		low[i]=cost[1][i];
		pre[i]=1;
	}
	int ans=0;
	vis[1]=true;
	pre[1]=-1;
	//���n-1���� 
	for(int i=1;i<n;i++){
		int k=-1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&(k==-1||low[k]>low[j])){
				k=j;
			}
		}
		if(k==-1||low[k]==INF) 	return -1;
		ans+=low[k];
		cost[pre[k]][k]=cost[k][pre[k]]=INF;
		//ע���ȼ�����Max[k][j],��vis[k] =true;
		for(int j=1;j<=n;j++){
			if(vis[j])
				Max[k][j]=Max[j][k]=max(Max[pre[k]][j],low[k]);
		}
		vis[k]=true;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&low[j]>cost[k][j]){
				low[j]=cost[k][j];
				pre[j]=k;
			}
		}
	}
	return ans;
}
//���С������ 
int smst(int ans){
	int Min=INF;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cost[i][j]!=INF)
				Min=min(Min,ans+cost[i][j]-Max[i][j]);
		}
	}
	return Min;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(cost,0x3f,sizeof(cost));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			cost[a][b]=cost[b][a]=c;
		}
		int ans=Prim();
		if(ans==-1)
			puts("Not Unique!");
		else if(ans==smst(ans))
			puts("Not Unique!");
		else
			printf("%d\n",ans);
	}
	return 0;
}
