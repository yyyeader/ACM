#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=2e3+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int n,m,sx,sy,l,r;
int d[4][2]={1,0,-1,0,0,1,0,-1};
char mp[N][N];
bool vis[N][N];

struct node{
	int x,y,l,r;
};

//使用双端队列,向上下走就加入队首,向左右走就加入队尾，保证剩余的向左右走的次数是最多的 
void bfs(){
	deque<node>q;
	q.push_front(node{sx,sy,l,r});
	vis[sx][sy]=true; 
	while(!q.empty()){
		node pre=q.front();
		q.pop_front();
		for(int i=0;i<4;i++){
			int xx=pre.x+d[i][0],yy=pre.y+d[i][1];
			if(i==2&&pre.r==0) continue;
			if(i==3&&pre.l==0) continue;
			if(xx<1||yy<1||xx>n||yy>m||vis[xx][yy]||mp[xx][yy]=='*') continue;
			vis[xx][yy]=true;
			if(i==2)
				q.push_back(node{xx,yy,pre.l,pre.r-1});
			else if(i==3)
				q.push_back(node{xx,yy,pre.l-1,pre.r});
			else
				q.push_front(node{xx,yy,pre.l,pre.r});
		}
	}
}

int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&l,&r);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	bfs();
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans+=vis[i][j];
		}
	}
	printf("%d\n",ans);
	return 0;
} 

