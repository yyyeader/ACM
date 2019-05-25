#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N=1e3+5;

int root[N],dis[N][N];//dis[i][j]Îªi~jµÄ¾àÀë 
struct node{
	int x,y;
	bool rp;//falseÎ´ÐÞ¸´£¬trueÐÞ¸´ 
}a[N];

int find(int x){
	int tmp=x;
	while(root[x]!=x){
		x=root[x];
	}
	root[tmp]=x;
	return x;
}

int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].rp=false;
	}
	for(int i=1;i<=n;i++){
		root[i]=i;
		dis[i][i]=INF;
		for(int j=i;j<=n;j++)
			dis[j][i]=dis[i][j]=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
	}
	char op[10];
	int p,q;
	while(~scanf("%s",op)){
		if(op[0]=='O'){
			scanf("%d",&p);
			a[p].rp=true;
			for(int i=1;i<=n;i++){
				if(a[i].rp){
					int x=find(i);
					int y=find(p);
					if(x!=y&&dis[i][p]<=d*d)
						root[x]=y;
				}
			}
		}
		else{
			scanf("%d%d",&p,&q);
			int x=find(p);
			int y=find(q);
			if(a[p].rp&&a[q].rp&&x==y)
				puts("SUCCESS");
			else
				puts("FAIL");
		}
	}
	return 0;
} 
