#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=700+5;

struct node{
	int x,y;
}a[N];

int res[N*N];

int dis(int i,int j){
	return (a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
}

int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int n;
		scanf("%d",&n);	
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
		}
		int cnt=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				res[++cnt]=dis(i,j);
			}
		}
		sort(res+1,res+cnt+1);
		int ans=cnt;
		for(int i=2;i<=cnt;i++){
			if(res[i]==res[i-1])
				ans--;
		}
		printf("Case %d: %d\n",++cas,ans+1);
	}
}
