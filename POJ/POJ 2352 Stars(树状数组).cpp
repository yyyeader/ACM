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
const int N=5e4+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int n;
int ans[N],sum[N];

inline int lowbit(int x){return x&-x;}

inline void add(int p){
	for(int i=p;i<N;i+=lowbit(i)) sum[i]++;
}

inline int query(int p){
	int res=0;
	for(int i=p;i>0;i-=lowbit(i)) res+=sum[i];
	return res;
}

inline void init(){
	memset(sum,0,sizeof(sum));
	memset(ans,0,sizeof(ans));
}

int main(){
	while(~scanf("%d",&n)){
		init();
		rep(i,1,n){
			int x,y;
			scanf("%d%d",&x,&y);x++; 
			//加入x+1,是为了避免为0,x是可能为0的 
			int res=query(x);
			ans[res]++;
			add(x);
		}
		rep(i,0,n-1)
			printf("%d\n",ans[i]);
	}
	return 0;
}

