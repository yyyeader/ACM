#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=3e2+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int n,m;
int num[105][N][N],mp[N][N];

inline int lowbit(int x){return x&-x;}

inline void update(int x,int y,int col,int val){
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))
			num[col][i][j]+=val;
}

inline int query(int x,int y,int col){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			sum+=num[col][i][j];
	return sum;
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		rep(j,1,m){
			scanf("%d",&mp[i][j]);
			update(i,j,mp[i][j],1);
		}
	}
	int q;
	scanf("%d",&q);
	rep(i,1,q){
		int op,x1,y1,x2,y2,c;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d",&x1,&y1,&c);
			update(x1,y1,mp[x1][y1],-1);
			update(x1,y1,c,1);
			mp[x1][y1]=c;
		}
		else{
			scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&c);
			int ans=query(x2,y2,c)+query(x1-1,y1-1,c);
			ans-=query(x2,y1-1,c)+query(x1-1,y2,c);
			printf("%d\n",ans);
		}
	}
	return 0;
}

