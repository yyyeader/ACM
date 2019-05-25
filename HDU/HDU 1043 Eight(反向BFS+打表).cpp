#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
typedef long long ll; 
const int N=4e5+5;

int vis[N];
string path[N];
char map[15];
char index[5]="udrl";//因为是逆向所以方向要反一下 
int d[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int fac[15]={1,1,2,6,24,120,720,5040,40320};

struct node{
	char num[10];
	int pos;
	string path;
}pre,now;

//求康托展开值 
int cantor(char s[]){
	int sum=0;
	int n=strlen(s);
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=i+1;j<n;j++){
			if(s[i]>s[j])
				cnt++;
		}
		sum+=cnt*fac[n-i-1];
	}
	return sum+1;
}
//从12345678x逆向BFS打表 
void bfs(){
	queue<node>q;
	now.pos=8;
	for(int i=0;i<8;i++)
		now.num[i]=i+1+'0';
	now.num[8]='0';
	now.num[9]='\0';
	q.push(now);
	while(!q.empty()){
		pre=q.front();
		q.pop();
		int pos=pre.pos;
		//转换成二维坐标 
		int x=pos/3;
		int y=pos%3;	
		for(int i=0;i<4;i++){
			int xx=x+d[i][0];
			int yy=y+d[i][1];
			if(xx<0||yy<0||xx>2||yy>2)
				continue;
			//转换回一维坐标 
			int new_pos=xx*3+yy;
			now=pre;
			swap(now.num[pos],now.num[new_pos]);
			int tmp=cantor(now.num);
			if(!vis[tmp]){
				now.pos=new_pos;
				//index[i]要加在前面，反的嘛 
				now.path=index[i]+now.path;
				vis[tmp]=1;
				//存储路径 
				path[tmp]=now.path;
				q.push(now);
			}
		}
	}
}

int main(){
	char c;
	bfs();
	while(cin>>c){
		//x转换成0便于康托展开 
		if(c=='x')
			map[0]='0';
		else
			map[0]=c;
		for(int i=1;i<9;i++){
			cin>>map[i];
			if(map[i]=='x')
				map[i]='0';
		}
		int aim=cantor(map);
		if(vis[aim])
			cout<<path[aim]<<endl;
		else
			cout<<"unsolvable"<<endl;
	}
}
