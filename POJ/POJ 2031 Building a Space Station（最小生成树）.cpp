#include<iostream>
#include<math.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e4+5;

struct node{
	double x,y,dis;
	node(){}
	node(double x,double y,double dis){
		this->x=x;
		this->y=y;
		this->dis=dis;
	}
	bool operator <(const node &b)const{
		return dis<b.dis;
	}
}edge[N];

struct node2{
	double x,y,z,r;
}a[N];

int root[N];

int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		for(int i=1;i<=n;i++){
			root[i]=i;
		}
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z,&a[i].r);
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				double dis=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)+(a[i].z-a[j].z)*(a[i].z-a[j].z));
				if(dis<=a[i].r+a[j].r){
					int x=find(i);
					int y=find(j);
					if(x!=y){
						root[x]=y;
					}
				}
				else{
					edge[++cnt]=node(i,j,dis-a[i].r-a[j].r);
				}
			}
		}
		sort(edge+1,edge+cnt+1);
		double sum=0;
		for(int i=1;i<=cnt;i++){
			int x=find(edge[i].x);
			int y=find(edge[i].y);
			if(x!=y){
				root[x]=y;
				sum+=edge[i].dis;
			}
		}
		printf("%.3f\n",sum);
	}
	return 0;
}
