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
const int N=1e4+5;

int root[N];

int find(int x){
	return x==root[x]?x:root[x]=find(root[x]);
}

struct node{
	int dx,val;
	bool operator <(const node &b)const{
		return val>b.val;
	}
}arr[N];

int main(){
	int n,ans;
	while(~scanf("%d",&n)){
		ans=0;
		for(int i=1;i<N;i++){
			root[i]=i;
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d",&arr[i].val,&arr[i].dx);
		}
		sort(arr+1,arr+1+n);
		for(int i=1;i<=n;i++){
			int t=find(arr[i].dx);
			if(t>0){
				ans+=arr[i].val;
				root[t]=t-1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
