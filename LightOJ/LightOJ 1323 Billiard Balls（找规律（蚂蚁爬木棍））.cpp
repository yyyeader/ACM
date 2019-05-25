#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long LL;
const int N=1005;

struct node{
	int x,y;
}res[N];

bool cmp(node a,node b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
//¹æÂÉ 
int cal(int x,int h,int t){
	t%=2*h;
	if(t<h-x)
		return x+t;
	if(t<2*h-x)
		return 2*h-t-x;
	return x+t-2*h;
}

int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int L,W,n,K;
		scanf("%d%d%d%d",&L,&W,&n,&K);		
		for(int i=1;i<=n;i++){
			char s[5];
			int x,y;
			scanf("%d%d%s",&x,&y,s);
			if(s[0]=='N')
				y=cal(y,W,K);
			else if(s[0]=='S')
				y=W-cal(W-y,W,K);
			if(s[1]=='E')
				x=cal(x,L,K);
			else if(s[1]=='W')
				x=L-cal(L-x,L,K);
			res[i].x=x;
			res[i].y=y;
		}
		sort(res+1,res+1+n,cmp);
		printf("Case %d:\n",++cas);
		for(int i=1;i<=n;i++){
			printf("%d %d\n",res[i].x,res[i].y);
		}
	}
}
 
