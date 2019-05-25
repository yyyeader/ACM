#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=15;

int a[N],u[N*N],v[N*N];
int g1[N][N],g2[N][N];

int main(){
	FAST_IO;
	int n,m1,m2;
	while(cin>>n>>m1>>m2){
		memset(g1,0,sizeof(g1));
		memset(g2,0,sizeof(g2));
		for(int i=1;i<=m1;i++){
			cin>>u[i]>>v[i];
			g1[u[i]][v[i]]=g1[v[i]][u[i]]=1;
		}
		for(int i=1;i<=m2;i++){
			int a,b;
			cin>>a>>b;
			g2[a][b]=g2[b][a]=1;
		}
		
		for(int i=1;i<=n;i++) a[i]=i;
		int ans=0,cnt=0;//ans为g1同构到g2方案数，cnt为g1同构到g1方案数 
		do{
			bool f1=true,f2=true;
			for(int i=1;i<=m1;i++){
				int x=a[u[i]],y=a[v[i]];
				if(!g1[x][y]) f1=false;
				if(!g2[x][y]) f2=false;
			}
			if(f2)
				ans++;
			if(f1)
				cnt++;
		}while(next_permutation(a+1,a+1+n));
		cout<<ans/cnt<<endl;
	}
	return 0;
}

