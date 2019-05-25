#include<cstdio>
#include<cmath>
#include<cctype>
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
const int N=5e4+5;

int root[N],rec[N];

int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

int main(){
	int a,b,flag,cas=0;
	while(1){
		for(int i=1;i<=N;i++)
			root[i]=i;
		memset(rec,0,sizeof(rec));
		flag=1;
		while(~scanf("%d%d",&a,&b)&&(a||b)){
			if(a==-1&&b==-1)
				return 0;
			rec[a]=rec[b]=1;
			//判断是否成环 
			if(find(a)==find(b))
				flag=0;
			root[find(a)]=find(b);
		}
		int sum=0;
		//判断只有一个并查集 
		for(int i=1;i<=N;i++){
			if(root[i]==i&&rec[i])
				sum++;
		}
		if(sum>1||!flag)
			printf("Case %d is not a tree.\n",++cas);
		else
			printf("Case %d is a tree.\n",++cas);
	}
	return 0;
}
