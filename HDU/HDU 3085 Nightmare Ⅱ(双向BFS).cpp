#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=805;

int n,m,t;
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char map[N][N];
int vis[N][N];

struct node{
	int x,y;
}M,G,pre,now,a[3];
queue<node>q[3];

bool judge(int x,int y){
	if(x<1||y<1||x>n||y>m||map[x][y]=='X')
		return false;
	//���������پ����ж��Ƿ�ᱻ��ץ�� 
	for(int i=1;i<=2;i++){
		if(abs(x-a[i].x)+abs(y-a[i].y)<=2*t)
			return false;
	}
	return true;
}

bool bfs(int mark){
	//С���ɣ�����size�Ϳ��Կ��Ƴ��ӵĶ�����һ���ģ������Ὣ��һ����Ҳ���ӣ�����ʵ����3���ˡ� 
	int size=q[mark].size(); 
	while(size--){
		pre=q[mark].front();
		q[mark].pop();
		//������֮ǰ�ж���ʱ��ÿ����1�����жϹ��ܲ��ܰ��˳Ե�
		if(!judge(pre.x,pre.y)) 
			continue;
		for(int i=0;i<4;i++){
			int xx=pre.x+d[i][0];
			int yy=pre.y+d[i][1];
			if(!judge(xx,yy))
				continue;
			//������ͬ���˵���������� 
			if(vis[xx][yy]){
				if(vis[xx][yy]!=mark)
					return true;
				else
					continue;
			}
			vis[xx][yy]=mark;
			now.x=xx;
			now.y=yy;
			q[mark].push(now);
		}
	}
	return false;
}

int solve(){
	//��ն��� 
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	q[1].push(M);
	q[2].push(G);
	vis[M.x][M.y]=1,vis[G.x][G.y]=2;
	t=0;
	//˫��bfs 
	while(!q[1].empty()||!q[2].empty()){
		t++;
		for(int i=1;i<=3;i++){
			if(bfs(1))
				return t;
		}		
		if(bfs(2))
			return t;
	}
	return -1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		//ע����scanf("%c",map[i][j])�ᳬʱ 
		for(int i=1,cnt=0;i<=n;i++){
			scanf("%s",map[i]+1);
			for(int j=1;j<=m;j++){
				if(map[i][j]=='M')
					M.x=i,M.y=j;
				if(map[i][j]=='G')
					G.x=i,G.y=j;
				if(map[i][j]=='Z')
					a[++cnt].x=i,a[cnt].y=j;
			}
		}
		printf("%d\n",solve());
	}
	return 0;
}
