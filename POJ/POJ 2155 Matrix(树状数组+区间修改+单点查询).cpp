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
const int N=1e3+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int n,q;
int sum[N][N];

inline int lowbit(int x){return x&-x;}

inline void add(int x,int y) {
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))
			sum[i][j]++;
}

inline int query(int x,int y){
	int res=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			res+=sum[i][j];
	return res;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){ 
		memset(sum,0,sizeof(sum));
		scanf("%d%d",&n,&q);
		rep(i,1,q){
			char s[5];
			int x1,y1,x2,y2;
			scanf("%s",s);
			if(s[0]=='C'){
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				add(x1,y1);
				add(x1,y2+1);
				add(x2+1,y1);
				add(x2+1,y2+1);
			}
			else{
				scanf("%d%d",&x1,&y1);
				printf("%d\n",query(x1,y1)%2);
			}
		}
		puts("");
	}
	return 0;
}

