#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int vis[10][10],map[10][10];

struct node{
	string path;
	int x,y;
}pre,now,ans;

void bfs(){
	queue<node>q;
	now.x=1;
	now.y=1;
	now.path+="(0, 0)\n";
	q.push(now);
	while(!q.empty()){
		pre=q.front();
		q.pop();
		if(pre.x==5&&pre.y==5){
			ans=pre;
			return;
		}
		for(int i=0;i<4;i++){
			int xx=pre.x+d[i][0];
			int yy=pre.y+d[i][1];
			if(xx<1||yy<1||xx>5||yy>5||map[xx][yy]==1||vis[xx][yy])
				continue;
			vis[xx][yy]=1;	
			now.x=xx;
			now.y=yy;
			char a=xx-1+'0';
			char b=yy-1+'0';
			now.path=pre.path;
			now.path=now.path+"("+a+", "+b+")\n";
			q.push(now);
		}
	}
}

int main(){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			scanf("%d",&map[i][j]);
		}
	}
	bfs();
	cout<<ans.path<<endl;
} 
