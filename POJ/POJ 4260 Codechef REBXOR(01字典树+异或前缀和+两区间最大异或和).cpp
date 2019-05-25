#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=4e5+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int idx;
int a[N],trie[N*32][2],sum[N],id[N*32],dp[N];

int newnode(){
	trie[idx][0]=trie[idx][1]=-1;
	return idx++;
}

void init(){
	idx=0;
	newnode();
}

void insert(int x){
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

int query(int x){
	int now=0;
	for(int i=31;i>=0;i--){
		int tmp=x&(1<<i);
		if(tmp>0) tmp=1;
		if(trie[now][tmp^1]!=-1)
			now=trie[now][tmp^1];
		else
			now=trie[now][tmp];
	}
	return x^id[now];
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		init();
		insert(0);
		sum[0]=sum[n+1]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]^a[i];
			dp[i]=max(dp[i-1],query(sum[i]));
			insert(sum[i]);
		}
		init();
		insert(0);
		int ans=-1;
		for(int i=n;i>=1;i--){
			sum[i]=sum[i+1]^a[i];
			ans=max(ans,query(sum[i])+dp[i-1]);
			insert(sum[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

