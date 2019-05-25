#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
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
const int N=5e6+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int n,ans,flag;
bool vis[105][105];

bool judge(int x,int y){
	if(x>=1&&y>=1&&x<=n&&y<=4&&!vis[x][y]) return true;
	return false;
} 

void dfs(int count){
	//flag表示是否已经放置曹操,题目要求曹操一定要有 
	if(count==n*4&&flag){
		ans++;
		return;
	}
	//枚举放置四种方块 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=4;j++){
			if(judge(i,j)&&judge(i,j+1)&&judge(i+1,j)&&judge(i+1,j+1)&&!flag){
				flag=1;
				vis[i][j]=vis[i][j+1]=vis[i+1][j]=vis[i+1][j+1]=true;
				dfs(count+4);
				flag=0;
				vis[i][j]=vis[i][j+1]=vis[i+1][j]=vis[i+1][j+1]=0;
			}
			if(judge(i,j)&&judge(i,j+1)){
				vis[i][j]=vis[i][j+1]=1;
				dfs(count+2);
				vis[i][j]=vis[i][j+1]=0;
			}
			if(judge(i,j)&&judge(i+1,j)){
				vis[i][j]=vis[i+1][j]=1;
				dfs(count+2);
				vis[i][j]=vis[i+1][j]=0;
			}
			if(judge(i,j)){
				vis[i][j]=1;
				dfs(count+1);
				vis[i][j]=0;
				return;		//注意这里要加return  
			}
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ans=flag=0;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}

