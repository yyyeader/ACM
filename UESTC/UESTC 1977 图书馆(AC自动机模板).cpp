#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int N=1e6+5;

int idx;
int trie[N][26],fail[N],cnt[N];
char str[N],t[N];

int newnode(){
	for(int i=0;i<26;i++)	
		trie[idx][i]=-1;
	cnt[idx++]=0;
	return idx-1;
}

void init(){
	idx=0;
	newnode();
}

void insert(char *s){
	int len=strlen(s);
	int now=0;
	for(int i=0;i<len;i++){
		int ch=s[i]-'a';
		if(trie[now][ch]==-1)
			trie[now][ch]=newnode();
		now=trie[now][ch];
	}
	cnt[now]++;
}

void getfail(){
	queue<int>q;
	for(int i=0;i<26;i++){
		if(trie[0][i]!=-1){
			fail[trie[0][i]]=0;
			q.push(trie[0][i]);
		}
		else
			trie[0][i]=0;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<26;i++){
			if(trie[u][i]!=-1){
				fail[trie[u][i]]=trie[fail[u]][i];
				q.push(trie[u][i]);
			}
			else
				trie[u][i]=trie[fail[u]][i];
		}
	}
}

int get(int u){
	int res=0;
	while(u){
		res+=cnt[u];
		//cnt[u]=0;
		u=fail[u];
	}
	return res;
}

int match(char *s){
	int len=strlen(s);
	int ans=0,now=0;
	for(int i=0;i<len;i++){
		int ch=s[i]-'a';
		now=trie[now][ch];
		ans+=get(now);
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%s",str);
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",t);
			insert(t);
		}
		getfail();
		printf("%d\n",match(str));
	}
	return 0;
}
