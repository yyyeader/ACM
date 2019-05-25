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
const int N=1e5+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct node{
	int x,y,z;
}a[M];

int f[N];

int find(int x){
	return f[x]==x?x:find(f[x]);
}

bool cmp(node a,node b){
	return a.z>b.z;
}

int main(){
	int n,m,da,db;
	while(~scanf("%d%d%d%d",&n,&m,&da,&db)){
		for(int i=0;i<=2*n;i++) f[i]=i;
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		sort(a+1,a+1+m,cmp);
		int ans=0;
		for(int i=1;i<=m;i++){
			int t1=find(a[i].x),t2=find(a[i].y);
			if(t1==t2){
				ans=a[i].z;
				break;
			}
			int t3=find(a[i].x+n),t4=find(a[i].y+n);
			//x和y'在一个集合中表示x和y分在不同房间里 
			f[t1]=t4;
			f[t2]=t3;
		}
		if(da>=ans&&db>=ans) printf("Survive");
		else if(da>=ans&&db<ans) printf("TT Boom!");
		else if(db>=ans&&da<ans) printf("Mr. Cai Boom!");
		else printf("Boom! boom!! boom!!!");
		printf("\n%d\n",ans);
	}
	return 0;
}

