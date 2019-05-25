#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e3+5;

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
}a[N];
int root[N];

int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n==0)
			break;
		for(int i=1;i<=n;i++){
			root[i]=i;
		}
		int cnt=0;
		n--;
		while(n--){
			int m,dis;
			char c1[5],c2[5];		
			scanf("%s%d",&c1,&m);
			for(int i=1;i<=m;i++){
				scanf("%s%d",&c2,&dis);
				a[++cnt]=node(c1[0]-'A'+1,c2[0]-'A'+1,dis);
			}
		}
		sort(a+1,a+1+cnt);
		int sum=0;
		for(int i=1;i<=cnt;i++){
			int x=find(a[i].x);
			int y=find(a[i].y);
			if(x!=y){
				sum+=a[i].dis;
				root[x]=y;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
