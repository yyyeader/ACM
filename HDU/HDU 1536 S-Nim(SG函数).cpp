#include<cstdio>
#include<cstring>
const int N=1e4+5;
int sg[N];//存储各个点的SG值
bool vis[N];//vis一定要是bool型,否则memset会超时,vis[i]=true,表示在集合S内 
int s[105];

//sg函数 
void sg_solve(int k){
	memset(sg,0,sizeof(sg));
	for(int i=0;i<N;i++){
		memset(vis,false,sizeof(vis));
		for(int j=1;j<=k;j++){
			//将能够一步到达的状态的SG值存入集合S 
			if(i-s[j]>=0)
				vis[sg[i-s[j]]]=true;
		}
		for(int j=0;;j++){
			if(!vis[j]){
				sg[i]=j;
				break;
			}
		}
	}
}

int main(){
	int k;
	while(~scanf("%d",&k)&&k){
		for(int i=1;i<=k;i++){
			scanf("%d",&s[i]);
		}
		sg_solve(k);
		int n;
		scanf("%d",&n);
		while(n--){
			int m,sum=0;
			scanf("%d",&m);
			for(int i=1;i<=m;i++){
				int x;
				scanf("%d",&x);
				sum^=sg[x];
			}
			if(sum)
				printf("W");
			else
				printf("L");
		}
		printf("\n");
	}
}
