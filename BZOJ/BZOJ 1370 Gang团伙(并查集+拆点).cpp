/*
不能使用带权并查集因为敌人的朋友跟自己没有关系，
反例：
	4 3 
	E 1 2
	F 2 3
	E 3 4
	ans:3 
*/ 
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
const int N=1e3+5;
const int M=1e6+5;
const int MOD=2;
const int INF=0x3f3f3f3f;

int root[N*2];

void init(int n){
	for(int i=0;i<=2*n;i++) root[i]=i;
}

int find(int x){
	return x==root[x]?x:root[x]=find(root[x]);
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		init(n);
		for(int i=1;i<=m;i++){
			char op[5];
			int x,y;
			scanf("%s%d%d",op,&x,&y);
			if(op[0]=='F') root[find(x)]=find(y);
			else{
				root[find(x+n)]=find(y);
				root[find(y+n)]=find(x);
			}
		}
		vector<int>ans;
		for(int i=1;i<=n;i++){
			ans.push_back(find(i));
		}
		sort(ans.begin(),ans.end());
		ans.erase(unique(ans.begin(),ans.end()),ans.end());
		printf("%d\n",ans.size());
	}
	return 0;
}

