/*计算传递闭包，若一头牛和其他n-1头牛都有关系，则它的排名可以确定*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e2+5;

int cost[N][N];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(cost,0,sizeof(cost));
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			cost[a][b]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(cost[i][k]==1&&cost[k][j]==1)
						cost[i][j]=1;
				}
			}
		}
		int ans=0;
		bool flag;
		for(int i=1;i<=n;i++){
			flag=true;
			for(int j=1;j<=n;j++){
				if(i==j)
					continue;	
				if(!cost[i][j]&&!cost[j][i]){
					flag=false;
					break;
				}
			}
			if(flag)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
