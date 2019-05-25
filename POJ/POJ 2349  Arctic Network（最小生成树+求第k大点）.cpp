#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e3+5;

struct node2{
	int x,y;
}a[N];

struct node{
	int x,y;
	double dis;
	node(){}
	node(int x,int y,double dis){
		this->x=x;
		this->y=y;
		this->dis=dis;
	}
	bool operator <(const node &b)const{
		return dis<b.dis;
	}
}edge[N*N];
int root[N];

int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int s,n;
		scanf("%d%d",&s,&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			root[i]=i;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				double dis=sqrt(1.0*(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
				edge[++cnt]=node(i,j,dis);
			}
		}
		sort(edge+1,edge+1+cnt);
		
		int	edge_num=0;
		double ans;
		for(int i=1;i<=cnt;i++){
			int x=find(edge[i].x);
			int y=find(edge[i].y);
			if(x!=y){
				edge_num++;
				root[x]=y;
				//����С�������е�n-1���ߣ�ȥ������s-1���ߣ���Ϊ��s������վ���൱��s���㣬��s-1���ߣ�
				//ʣ�µ�n-s�����У����ı߳���Ϊ����
				if(edge_num==n-s){
					ans=edge[i].dis;
					break;
				}
			}
		}
		printf("%.2f\n",ans);
	}
	return 0;
}

