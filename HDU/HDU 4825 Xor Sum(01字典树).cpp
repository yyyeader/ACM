#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const int N=4e6+5;

int idx;
LL id[N],trie[N][2];

int newnode(){
	trie[idx][0]=trie[idx][1]=-1;
	return idx++;
}

void init(){
	idx=0;
	newnode();
}

void insert(LL x){
	int now=0;
	for(int i=31;i>=0;i--){
		int tmp=x&(1<<i);
		if(tmp>0) tmp=1;
		if(trie[now][tmp]==-1)
			trie[now][tmp]=newnode();
		now=trie[now][tmp];
	}
	id[now]=x;
}

int query(LL x){
	int now=0;
	for(int i=31;i>=0;i--){
		int tmp=x&(1<<i);
		if(tmp>0) tmp=1;
		if(trie[now][tmp^1]!=-1)
			now=trie[now][tmp^1];
		else
			now=trie[now][tmp];
	}
	return id[now];
}

int main(){
	int T,cas=0;
	scanf("%d",&T);
	while(T--){
		init();
		int n,m;
		scanf("%d%d",&n,&m);
		LL x;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x);
			insert(x);
		}
		printf("Case #%d:\n",++cas);
		for(int i=1;i<=m;i++){
			scanf("%lld",&x);
			printf("%d\n",query(x));
		}
	}
	return 0;
}
