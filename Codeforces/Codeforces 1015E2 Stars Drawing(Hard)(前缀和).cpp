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

int t[N][N],d[N][N],l[N][N],r[N][N],sz[N][N];
bool vis[N][N];
char mp[N][N];

struct node{
	int x,y,s;
};

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		scanf("%s",mp[i]+1);
	}
	rep(i,1,n){
		int cnt=0;
		rep(j,1,m){
			if(mp[i][j]=='*'&&cnt!=-1) cnt++;
			else cnt=0;
			l[i][j]=cnt;
		}
		cnt=0;
		per(j,m,1){
			if(mp[i][j]=='*'&&cnt!=-1) cnt++;
			else cnt=0;
			r[i][j]=cnt;
		}
	}
	rep(j,1,m){
		int cnt=0;
		rep(i,1,n){
			if(mp[i][j]=='*'&&cnt!=-1) cnt++;
			else cnt=0;
			t[i][j]=cnt;
		}
		cnt=0;
		per(i,n,1){
			if(mp[i][j]=='*'&&cnt!=-1) cnt++;
			else cnt=0;
			d[i][j]=cnt;
		}
	}
	int ans=0;
	rep(i,1,n){
		rep(j,1,m){
			if(mp[i][j]=='.') continue;
			int s=l[i][j];
			s=min(s,r[i][j]);
			s=min(s,t[i][j]);
			s=min(s,d[i][j]);
			sz[i][j]=s-1;
			if(s>1)
				ans++;
		}
	}
	bool flag=true;
	rep(i,1,n){
		int cur=0;
		rep(j,1,m){
			if(mp[i][j]=='.') continue;
			if(sz[i][j])
				cur=max(cur,j+sz[i][j]);
			if(j<=cur)
				vis[i][j]=true;
		}
		cur=m+1;
		per(j,m,1){
			if(mp[i][j]=='.') continue;
			if(sz[i][j])
				cur=min(cur,j-sz[i][j]);
			if(j>=cur)
				vis[i][j]=true;
		}
	}
	rep(j,1,m){
		int cur=0;
		rep(i,1,n){
			if(mp[i][j]=='.') continue;
			if(sz[i][j])
				cur=max(cur,i+sz[i][j]);
			if(i<=cur)
				vis[i][j]=true;
		}
		cur=n+1;
		per(i,n,1){
			if(mp[i][j]=='.') continue;
			if(sz[i][j])
				cur=min(cur,i-sz[i][j]);
			if(i>=cur)
				vis[i][j]=true;
		}
	}
	rep(i,1,n){
		rep(j,1,m){
			if(mp[i][j]=='*'&&!vis[i][j]){
				flag=false;
				break;
			}
		}
	}
	if(!flag)
		puts("-1");
	else{
		printf("%d\n",ans);
		rep(i,1,n){
			rep(j,1,m){
				if(sz[i][j])
					printf("%d %d %d\n",i,j,sz[i][j]);
			}
		}
	}
	return 0;
}

