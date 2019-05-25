#include<cstdio>
#include<algorithm>
using namespace std; 

struct node{
	int x,y,z;
}a[300];

bool cmp(node a,node b){
	return a.x==b.x?a.y>b.y:a.x<b.x;
}

void add(int x,int y,int z,int i){
	a[i].x=x;
	a[i].y=y;
	a[i].z=z;
}

int main(){
	int n;
	int cas=0;
	while(~scanf("%d",&n)&&n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z,++cnt) ;
			add(x,z,y,++cnt);
			add(y,z,x,++cnt);
			add(y,x,z,++cnt);
			add(z,y,x,++cnt);
			add(z,x,y,++cnt);
		}
			
		sort(a+1,a+1+cnt,cmp);
		int ans=0;
		int dp[300]={0};
		for(int i=1;i<=cnt;i++){
			dp[i]=a[i].z;
			for(int j=1;j<i;j++){
				if(a[i].y>a[j].y){
					dp[i]=max(dp[i],dp[j]+a[i].z);
				}			
			}
			ans=max(dp[i],ans);
		}
		printf("Case %d: maximum height = %d\n",++cas,ans);
	}
}
