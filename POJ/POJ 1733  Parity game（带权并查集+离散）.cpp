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
const int N=2e4+5;

int root[N],val[N];

struct node{
	int l,r,cla;
}arr[N];
int X[N];

int find(int x){
	if(root[x]==x)
		return x;
	int tmp=find(root[x]);
	val[x]=(val[x]+val[root[x]])%2;
	return root[x]=tmp;
}

int bin_search(int l,int r,int x){
	while(l<=r){
		int mid=(l+r)/2;
		if(X[mid]==x)
			return mid;
		else if(X[mid]<x)
			l=mid+1;
		else
			r=mid-1;
	}
	return -1;
}

int main(){
	int n,m;
	while(~scanf("%d",&n)){
		scanf("%d",&m);
		int m1=0,m2=1,ans=0;
		memset(val,0,sizeof(val));
		for(int i=1;i<=m;i++){
			char s[6];
			scanf("%d%d%s",&arr[i].l,&arr[i].r,s);
			if(s[0]=='e')
				arr[i].cla=0;
			else
				arr[i].cla=1;
			X[++m1]=arr[i].l;
			X[++m1]=arr[i].r;
		}
		//ШЅжи
		sort(X+1,X+1+m1);
		for(int i=2;i<=m1;i++){
			if(X[i]!=X[i-1])
				X[++m2]=X[i];
		}
		for(int i=0;i<=m2;i++){
			root[i]=i;
		}
		for(int i=1;i<=m;i++){
			int l=bin_search(1,m2,arr[i].l)-1;
			int r=bin_search(1,m2,arr[i].r);
			int c=arr[i].cla;
			int t1=find(l);
			int t2=find(r);
			if(t1==t2){
				if((val[l]+c)%2!=val[r]){
					ans=i-1;
					break;
				}
			}
			else{
				root[t2]=t1;
				val[t2]=(val[l]-val[r]+c+2)%2;
			}
		}
		if(!ans)
			ans=m;
		printf("%d\n",ans);
	}
	return 0;
}
