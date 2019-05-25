#include<iostream>
#include<math.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;

struct node{
	int x,y;
}a[N];

struct node2{
	int x,y;
	double dis;
	node2(){}
	node2(int x,int y,double dis){
		this->x=x;
		this->y=y;
		this->dis=dis;
	}
	bool operator <(const node2 &b)const{
		return dis<b.dis;
	}
}edge[N*N];

int root[N];

int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			int n;
			scanf("%d",&n);
			for(int i=1;i<=n;i++){
				root[i]=i;
			}	
			for(int i=1;i<=n;i++){
				scanf("%d%d",&a[i].x,&a[i].y);
			}	
			int cnt=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					double dis=sqrt(1.0*(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
					if(dis<10||dis>1000)
						continue;
					edge[++cnt]=node2(i,j,dis);
				}
			}
			sort(edge+1,edge+1+cnt);
			double sum=0;
			for(int i=1;i<=cnt;i++){
				int x=find(edge[i].x);
				int y=find(edge[i].y);
				if(x!=y){
					sum+=edge[i].dis*100;
					root[x]=y;
				}
			}
			int num=0;
			for(int i=1;i<=n;i++){
				if(find(i)==i){
					num++;
				}
			}
			if(num>1)
				puts("oh!");
			else
				printf("%.1f\n",sum);
		}
	}
	return 0;
}
