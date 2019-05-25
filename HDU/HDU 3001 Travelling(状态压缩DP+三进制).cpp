#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=6e4+5;

int n,m,ans;
int map[15][15];
int dp[N][15];
int bit[15]={1,3,9,27,81,243,729,2187,6561,19683,59049};
int num[N][15];

//计算所有数字10位以内三进制表示 
void make_tab(){
	for(int i=0;i<bit[10];i++){
		int b=i;
		for(int j=0;j<10;j++){
			num[i][j]=b%3;
			b/=3;
		}
	}
}

int main(){
	make_tab(); 
	while(~scanf("%d%d",&n,&m)){
		memset(map,0x3f,sizeof(map));
		memset(dp,0x3f,sizeof(dp));
		int ans=INF; 
		for(int i=1;i<=m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			a--,b--;
			//去重边 
			map[a][b]=min(map[a][b],c);
			map[b][a]=min(map[b][a],c);
		}
		for(int i=0;i<n;i++)
			dp[bit[i]][i]=0;//对每个点定位初始点0
		
		for(int i=0;i<bit[n];i++){
			bool flag=true;//表示所有位都是>=1，也就是每个城镇都走过了 
			for(int j=0;j<n;j++){
				if(num[i][j]==0)
					flag=false;
				if(dp[i][j]==INF)//判断是否走到j点 
					continue;
				for(int k=0;k<n;k++){
					//注意这个num[i][k]>=2,因为如果i状态在k点已经走过两次了显然是不能继续往下走的 
					if(j==k||num[i][k]>=2||map[j][k]==INF)
						continue;
					int next=i+bit[k];//从j点走到k点 
					dp[next][k]=min(dp[next][k],dp[i][j]+map[j][k]); 
				} 
			}
			//如果所有城镇都走了一遍则可以找出最小值 
			if(flag){
				for(int j=0;j<n;j++)
					ans=min(ans,dp[i][j]);
			}
		}
		if(ans==INF)
			puts("-1");
		else
			printf("%d\n",ans);
	}	
	return 0;
} 
