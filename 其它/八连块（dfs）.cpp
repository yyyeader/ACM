#include<stdio.h>
#include<string.h>
#define MAXN 105
char pic[MAXN][MAXN];
int idx[MAXN][MAXN];
int m,n;

void dfs(int i,int j,int id){
	if(idx[i][j]>0||pic[i][j]!='@') return;
	if(i<0||i>=m||j<0||j>=n) return;
	idx[i][j]=id;
	for(int q=-1;q<=1;q++)
		for(int k=-1;k<=1;k++)
			if(q!=0||k!=0) dfs(i+q,j+k,id);
}

int main() {
	int i,j;
	while(scanf("%d %d",&m,&n)&&m&&n){
		for(i=0;i<m;i++) scanf("%s",pic[i]);
		int cnt=0;
		memset(idx,0,sizeof(idx));
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(pic[i][j]=='@'&&idx[i][j]==0) dfs(i,j,++cnt);
		printf("%d\n",cnt);
	}
	return 0;
}
