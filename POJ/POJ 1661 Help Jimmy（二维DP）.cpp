#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e3+5;
const int INF=0x3f3f3f3f;

int dp[N][2];//dp[i][0]表示走到第i块板左端点最小花费，dp[i][0]表示走到右端点最小花费 

struct node{
	int l,r,h;
}a[N];

bool cmp(node a,node b){
	return a.h>b.h;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,0x3f,sizeof(dp));
		int n,x,y,lim,ans=INF;
		scanf("%d%d%d%d",&n,&x,&y,&lim);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].h);
		}
		sort(a+1,a+1+n,cmp);
		a[0].l=a[0].r=x,a[0].h=y;
		dp[0][0]=dp[0][1]=0;
		for(int i=0;i<=n;i++){
			//flag表示从木板i下去是否有碰到其他木板 
			bool flag=true;
			//往左走
			for(int j=i+1;j<=n;j++){
				//碰到可以落脚的木板 
				if(a[j].l<=a[i].l&&a[j].r>=a[i].l&&a[i].h-a[j].h<=lim){
					dp[j][0]=min(dp[j][0],a[i].l-a[j].l+dp[i][0]);
					dp[j][1]=min(dp[j][1],a[j].r-a[i].l+dp[i][0]);
					flag=false;
					break;
				}
			}
			//如果没有其他木板挡着,判断离地高度是否大于限制,从而确定是否可以直接落地
			if(flag&&a[i].h<=lim){
				ans=min(dp[i][0],ans);
			}
			flag=true;
			//往右走，同理 
			for(int j=i+1;j<=n;j++){
				if(a[j].r>=a[i].r&&a[j].l<=a[i].r&&a[i].h-a[j].h<=lim){
					dp[j][0]=min(dp[j][0],a[i].r-a[j].l+dp[i][1]);
					dp[j][1]=min(dp[j][1],a[j].r-a[i].r+dp[i][1]);
					flag=false;
					break;
				}
			}
			if(flag&&a[i].h<=lim){
				ans=min(dp[i][1],ans);
			}
		}
		//只用算出水平走的时间即可，因为无论如何下落到地面的高度都是y,是不变的。
		printf("%d\n",ans+y);
	}
	return 0;
}
