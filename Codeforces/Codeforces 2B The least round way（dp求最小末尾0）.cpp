#include<bits/stdc++.h>
#define lc(a) (a<<1)
#define rc(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=1e3+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int n;
int mp[N][N],dp[N][N][2],path[N][N][2];

struct node{
	int f,s;
	node(int f,int s):f(f),s(s){}
};

bool judge(int x,int y){
	if(x>0&&x<=n&&y>0&&y<=n) return true;
	return false;
}

void print(int x,int y,int type){
	if(path[x][y][type]==-1)
		return;	
	if(path[x][y][type]==0)
		print(x-1,y,type);
	else 
		print(x,y-1,type);
	printf("%c",path[x][y][type]==0?'D':'R');
}

node cal(int x){
	int f=0,s=0;
	while(x){
		if(x%5==0){
			f++;
			x/=5;
		}
		else break;
	}
	while(x){
		if(x%2==0){
			s++;
			x/=2;
		}
		else break;
	}
	return node(f,s);
}

int main(){
	scanf("%d",&n);
	int idx,idy;
	bool flag=false;
	memset(path,-1,sizeof(path));
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&mp[i][j]);
			if(mp[i][j]==0){
				idx=i;
				idy=j;
				flag=true;
			}
		}
	}
	dp[1][1][0]=dp[1][1][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			node t=cal(mp[i][j]);
			if(judge(i-1,j)){
				dp[i][j][0]=dp[i-1][j][0];
				dp[i][j][1]=dp[i-1][j][1];
				path[i][j][1]=path[i][j][0]=0;
			}
			if(judge(i,j-1)){
				if(dp[i][j][0]>dp[i][j-1][0]){
					dp[i][j][0]=dp[i][j-1][0];
					path[i][j][0]=1;
				}
				if(dp[i][j][1]>dp[i][j-1][1]){
					dp[i][j][1]=dp[i][j-1][1];
					path[i][j][1]=1;
				}
			}
			dp[i][j][0]+=t.f;
			dp[i][j][1]+=t.s;
		}
	}
	int ans=min(dp[n][n][0],dp[n][n][1]);
	if(ans>1&&flag){
		puts("1");
		for(int i=2;i<=idx;i++){
			printf("D");
		}
		for(int j=2;j<=n;j++){
			printf("R");
		}
		for(int i=idx+1;i<=n;i++){
			printf("D");
		}
		return 0;
	}
	printf("%d\n",ans);
	if(ans==dp[n][n][0])
		print(n,n,0);
	else
		print(n,n,1);
	return 0;
}

