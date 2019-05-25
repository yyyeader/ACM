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
		flag=1;//����Ƿ񵽴�߽磬�����߽�Ͳ����Ǻ��� 
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
				flag=num=0;//**ÿ��dfsǰ�߽��ǣ���ˮ�ݼ�����Ҫ��ʼ�� 
				dfs(i,j);
				if(!flag){//���û��������Ե���Ǿ��Ǻ� 
					lake[count].color=cnt;//����ͬһ������ˮ��Ⱦͬһ����ɫ 
					lake[count].num=num;//ˮ�ݸ��� 
					count++;
				}
			}	
		}
	}
	count-=1;
	sort(lake+1,lake+count+1,cmp);//����ÿ����Ҫ���ˮ�ݸ����Ӵ�С���� 
	k=count-k;//Ҫ��ĺ��ĸ���
	for(i=count;i>=1;i--){
		if(k==0)
			break;
		//������Ⱦɫ��ͬ�ĵط����ϣ�����Ϊ-1 
		for(j=0;j<m;j++){
			for(int k=0;k<n;k++){
				if(idx[j][k]==lake[i].color)
					idx[j][k]=-1;
			}
		}
		ans+=lake[i].num;//��¼����������� 
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
