#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define LL long long
using namespace std;

int sum[5005][5005];

int main(){
	int n,R,r,c;
	scanf("%d%d",&n,&R);
	r=c=R;
	for(int i=1;i<=n;i++){
		int x,y,val;
		scanf("%d%d%d",&x,&y,&val);
		x++,y++;
		sum[x][y]=val;
		r=max(r,x),c=max(c,y);
	}

	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sum[i][j];
		}
	}
	
	int ans=0;
	for(int i=R;i<=r;i++){
		for(int j=R;j<=c;j++){
			int res=sum[i][j]-sum[i-R][j]-sum[i][j-R]+sum[i-R][j-R];
			ans=max(ans,res);
		}
	}
	printf("%d\n",ans);
	return 0;
}
