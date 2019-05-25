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

char mp[N][N],tmp[N][N];
int d[8][2]={1,0,0,1,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%s",mp[i]+1);
			for(int j=1;j<=m;j++) tmp[i][j]='.';
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				bool flag=true;
				for(int k=0;k<8;k++){
					int x=i+d[k][0];
					int y=j+d[k][1];
					if(x<1||y<1||x>n||y>m||mp[x][y]=='.'){
						flag=false;
						break;
					}
				}
				if(flag){
					for(int k=0;k<8;k++){
						int x=i+d[k][0];
						int y=j+d[k][1];
						tmp[x][y]='#';
					}
				}
			}
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(mp[i][j]!=tmp[i][j]){
					flag=false;
					break;
				}
			}
		}
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

