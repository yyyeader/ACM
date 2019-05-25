#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+5;

struct node{
	int next[2];
	int val;
	void reset(){
		next[0]=next[1]=val=0;
	}
}T[N*32];//数组大小为数字个数*最大位数 

int cnt;//字典树上的节点个数

void init(){
	cnt=0;
	T[0].reset();
} 

//将x插入到01字典树上 
void insert(int x){
	int cur=0;//从根节点开始
	for(int i=31;i>=0;i--){
		int t=(x>>i)&1;
		if(!T[cur].next[t]){
			//将下一个新节点初始化
			T[++cnt].reset();
			T[cur].next[t]=cnt;
		}
		cur=T[cur].next[t];
	}
	//插入x 
	T[cur].val=x;
}

//查询在字典树中查找和x异或的值最大的元素 
int query(int x){
	int cur=0;
	for(int i=31;i>=0;i--){
		int t=(x>>i)&1;
		//贪心,尽量找不同的使异或值最大 
		if(T[cur].next[t^1])
			cur=T[cur].next[t^1];
		else
			cur=T[cur].next[t];
	}
	return T[cur].val;
}

int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		init();
		int n,m,x;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			insert(x);
		}
		printf("Case #%d:\n",++cas);
		for(int i=1;i<=m;i++){
			scanf("%d",&x);
			printf("%d\n",query(x));
		}
	}
	return 0;
}
