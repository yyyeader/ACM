#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1e3+5;
const int M=4e5+5;

int idx;
int trie[M][2];
int id[M],a[N],cnt[M];//cnt[i]记录经过节点i的路径数量 

int newnode(){
	trie[idx][0]=trie[idx][1]=-1;
	return idx++;
}

void init(){
	idx=0;
	newnode();
	memset(cnt,0,sizeof(cnt));
}

void insert(int x){
	int now=0;
	for(int i=31;i>=0;i--){
		int tmp=x&(1<<i);
		if(tmp>0) tmp=1;
		if(trie[now][tmp]==-1)
			trie[now][tmp]=newnode();
		now=trie[now][tmp];
		cnt[now]++;
	}
	id[now]=x;
}

void del(int x){
	int now=0;
	for(int i=31;i>=0;i--){
		int tmp=x&(1<<i);
		if(tmp>0) tmp=1;
		now=trie[now][tmp];
		cnt[now]--;
	}
}

int query(int x){
	int now=0;
	for(int i=31;i>=0;i--){
		int tmp=x&(1<<i);
		if(tmp>0) tmp=1;
		if(trie[now][tmp^1]!=-1&&cnt[trie[now][tmp^1]]>0)
			now=trie[now][tmp^1];
		else
			now=trie[now][tmp];
	}
	return x^id[now];
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			insert(a[i]);
		}
		int ans=-1;
		for(int i=1;i<=n;i++){
			del(a[i]);
			for(int j=i+1;j<=n;j++){
				del(a[j]);
				int t=query(a[i]+a[j]);
				ans=max(ans,t);
				insert(a[j]);
			}
			insert(a[i]);
		} 
		printf("%d\n",ans);
	}
	return 0;
}
