#include<iostream>
#include<cstdio> 
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char map[55][55];
int idx[55][55]; 
int m,n,num,flag,cnt=0;
struct node{
	int num,color;
}lake[3005];

void dfs(int x,int y){
	if(idx[x][y]||map[x][y]!='.')
		return;
	if(x<0||y<0||x>=m||y>=n){
		return;
	}
	if(x==0||y==0||x==m-1||y==n-1)
		flag=1;//标记是否到达边界，连到边界就不算是湖了 
	num++;
	idx[x][y]=cnt;
	for(int i=0;i<4;i++){
		dfs(x+d[i][0],y+d[i][1]);
	}
}

bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
//	freopen("in.txt","r",stdin);
	int k,i,j,end,ans=0,count=1;
	cin>>m>>n>>k;
	getchar();
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%c",&map[i][j]);
		}
		getchar();
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(!idx[i][j]&&map[i][j]=='.'){
				cnt++;
				flag=num=0;//**每次dfs前边界标记，和水洼计数都要初始化 
				dfs(i,j);
				if(!flag){//如果没有连到边缘，那就是湖 
					lake[count].color=cnt;//属于同一个湖的水洼染同一种颜色 
					lake[count].num=num;//水洼个数 
					count++;
				}
			}	
		}
	}
	count-=1;
	sort(lake+1,lake+count+1,cmp);//按照每个湖要填的水洼个数从大到小排序 
	k=count-k;//要填的湖的个数
	for(i=count;i>=1;i--){
		if(k==0)
			break;
		//把所有染色相同的地方填上，即标为-1 
		for(j=0;j<m;j++){
			for(int k=0;k<n;k++){
				if(idx[j][k]==lake[i].color)
					idx[j][k]=-1;
			}
		}
		ans+=lake[i].num;//记录所需填的总数 
		k--;
	}
	
	cout<<ans<<endl;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(idx[i][j]==-1){
				cout<<'*';
			}		
			else
				cout<<map[i][j];
		}
		cout<<endl;
	}
}
