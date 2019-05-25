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
				//从最小生成树中的n-1条边，去掉最大的s-1条边（因为有s个卫星站，相当于s个点，则s-1条边）
				//剩下的n-s条边中，最大的边长即为所求
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

