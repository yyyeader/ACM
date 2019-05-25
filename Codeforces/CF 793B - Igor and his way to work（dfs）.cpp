#include<iostream>
#include<cstring>
using namespace std;
const int N=1e3+5;
int m,n;
bool flag=false;
char map[N][N];
int vis[N][N][5];//*�ؼ�*��������߹��ĵ㣬��¼�õ㳯�Ÿ�����ת���� 
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x,int y,int dir,int cnt){
	if(x<=0||x>m||y<=0||y>n||cnt>2)
		return;	
	if(vis[x][y][dir]<=cnt)//������λ����������Ѿ��߹��������˸�С��ת�������ǾͲ��������������
		return;
	if(map[x][y]=='T'){
		flag=true;
		return;
	}	
	if(map[x][y]!='.'&&map[x][y]!='S')
		return;
	vis[x][y][dir]=cnt;
	for(int i=0;i<4;i++) {
		int x1=x+d[i][0];
		int y1=y+d[i][1];
		if(dir==-1)
			dfs(x1,y1,i,cnt);
		else if(dir!=i)
			dfs(x1,y1,i,cnt+1);
		else
			dfs(x1,y1,i,cnt);
	}
}

int main(){
	int index,indey;
	scanf("%d %d",&m,&n);
	getchar();
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%c",&map[i][j]);
			if(map[i][j]=='S'){
				index=i;
				indey=j;
			}
		}
		getchar();
	}
	memset(vis,0x3f,sizeof(vis));//ת������ʼ��Ϊ���޴� 
	dfs(index,indey,-1,0);//-1��ʾ��ʼλ��û�з���
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
}
