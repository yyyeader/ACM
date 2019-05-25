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
char index[5]="udrl";//��Ϊ���������Է���Ҫ��һ�� 
int d[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int fac[15]={1,1,2,6,24,120,720,5040,40320};

struct node{
	char num[10];
	int pos;
	string path;
}pre,now;

//����չ��ֵ 
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
//��12345678x����BFS��� 
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
		//ת���ɶ�ά���� 
		int x=pos/3;
		int y=pos%3;	
		for(int i=0;i<4;i++){
			int xx=x+d[i][0];
			int yy=y+d[i][1];
			if(xx<0||yy<0||xx>2||yy>2)
				continue;
			//ת����һά���� 
			int new_pos=xx*3+yy;
			now=pre;
			swap(now.num[pos],now.num[new_pos]);
			int tmp=cantor(now.num);
			if(!vis[tmp]){
				now.pos=new_pos;
				//index[i]Ҫ����ǰ�棬������ 
				now.path=index[i]+now.path;
				vis[tmp]=1;
				//�洢·�� 
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
		//xת����0���ڿ���չ�� 
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
