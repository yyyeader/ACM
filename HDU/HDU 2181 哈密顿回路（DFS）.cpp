#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int point,cnt; 
int map[25][25];
int vis[25],path[25];

void dfs(int pos,int len){
	vis[pos]=1;
	//下一个点按字序号从小到大的顺序走 
	for(int i=1;i<=20;i++){
		if(map[pos][i]){
			path[len]=pos;
			if(i==point&&len==20){
				printf("%d:  ",++cnt);
				for(int i=1;i<=20;i++)
					printf("%d ",path[i]);
				printf("%d\n",point);
			}
			if(!vis[i])
				dfs(i,len+1);		
		}
	}
	vis[pos]=0;
}

int main(){
	int a,b,c;
	while(scanf("%d",&a)&&a){
		cnt=0;
		memset(map,0,sizeof(map));
		scanf("%d%d",&b,&c);
		map[1][a]=map[1][b]=map[1][c]=1;
		for(int i=2;i<=20;i++){
			scanf("%d%d%d",&a,&b,&c);
			map[i][a]=map[i][b]=map[i][c]=1;
		}
		scanf("%d",&point);
		dfs(point,1);
	}
	return 0;
}
