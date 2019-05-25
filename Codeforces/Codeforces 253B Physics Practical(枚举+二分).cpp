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
#define lc(a) (a<<1)
#define rc(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)  
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=5e6+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int a[N];

bool cmp(int a,int b){
	return a<b;
}

int bin_search(int x,int lx,int rx){
	int l=lx,r=rx;
	while(l<=r){
		int mid=(l+r)/2;
		if(x*2>=a[mid])
			l=mid+1;
		else
			r=mid-1;
	}
	return r;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	int ans=INF;
	//Ã¶¾Ù×ó²àÆðµã
	for(int i=1;i<=n;i++){
		int pos=bin_search(a[i],i,n);
		ans=min(ans,i-1+n-pos);
	}
	printf("%d\n",ans);
	return 0;
}
