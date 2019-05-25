#include<iostream>
#include<vector>
#include<cstdio> 
using namespace std;
const int N=2e5+5;
vector<int>v[N];
int ans=0;
int acol[N];
int sta[N];
void dfs(int a,int col,int pcol){
	//printf("a=%d col=%d\n",a,col);
	int tcol=1;
	acol[a]=col;
	for(int i=0;i<v[a].size();i++){
		int t=v[a][i];
		if(sta[t]==0){
			sta[t]=1;
			while(tcol==col||tcol==pcol)
				tcol++;
			if(tcol>ans)
				ans=tcol;
			//printf("a=%d t=%d tcol=%d\n",a,t,tcol);
			dfs(t,tcol,col);
			tcol++;
		}		
	}
	return;	
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(sta[i]==0){
			sta[i]=1;
			acol[i]=1;
			dfs(i,1,0);
		}	
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		printf("%d ",acol[i]);
	}
	printf("\n");
	return 0;
}
