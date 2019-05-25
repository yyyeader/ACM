#include<iostream>
#include<math.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e3+5;

struct node{
	int x,y,dis;
	node(){}
	node(int x,int y,int dis){
		this->x=x;
		this->y=y;
		this->dis=dis;
	}
	bool operator <(const node &b)const{
		return dis<b.dis;
	}
}a[N*N];
int root[N];
char str[N][10];
int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n==0)
			break;
		int cnt=0;
		for(int i=1;i<=n;i++){
			root[i]=i;
			scanf("%s",str[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int dis=0;
				for(int k=0;k<7;k++){
					if(str[i][k]!=str[j][k]){
						dis++;
					}
				}
				a[++cnt]=node(i,j,dis);
			}
		}
		sort(a+1,a+1+cnt);
		int sum=0;
		for(int i=1;i<=cnt;i++){
			int x=find(a[i].x);
			int y=find(a[i].y);
			if(x!=y){
				root[x]=y;
				sum+=a[i].dis;
			}
		}
		printf("The highest possible quality is 1/%d.\n",sum);
	}
	return 0;
}
