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
const int N=3e4+5;
const int INF=0x3f3f3f3f;

int s[N];

struct suffix_array{
	int wa[N],wb[N],wsf[N],wv[N],high[N],rk[N],sa[N];
	bool cmp(int *r,int a,int b,int k){
		return r[a]==r[b]&&r[a+k]==r[b+k];
	}
	inline void build_sa(int *r,int n,int m){
		int i,j,p,*x=wa,*y=wb;
		for(i=0;i<m;i++) wsf[i]=0;
		for(i=0;i<n;i++) wsf[x[i]=r[i]]++;
		for(i=1;i<m;i++) wsf[i]+=wsf[i-1];
		for(i=n-1;i>=0;i--) sa[--wsf[x[i]]]=i;
		for(p=1,j=1;p<n;m=p,j*=2){
			for(p=0,i=n-j;i<n;i++) y[p++]=i;
			for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
			for(i=0;i<n;i++) wv[i]=x[y[i]];
			for(i=0;i<m;i++) wsf[i]=0;
			for(i=0;i<n;i++) wsf[wv[i]]++;
			for(i=1;i<m;i++) wsf[i]+=wsf[i-1];
			for(i=n-1;i>=0;i--) sa[--wsf[wv[i]]]=y[i];
			swap(x,y);x[sa[0]]=0;
			for(p=1,i=1;i<n;i++)
				x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
		}
	}
	inline void build_high(int *r,int n){
		int i,j,k=0;
		for(i=1;i<=n;i++) rk[sa[i]]=i;
		for(i=0;i<n;i++){
			if(k) k--;
			j=sa[rk[i]-1];
			while(r[i+k]==r[j+k]) k++;
			high[rk[i]]=k;
		}
	}
}sf; 

bool check(int n,int mid){
	int mmax=-INF,mmin=INF;
	for(int i=2;i<=n;i++){
		if(sf.high[i]<mid){
			mmax=-INF;
			mmin=INF;
			continue;
		}
		mmax=max(mmax,max(sf.sa[i],sf.sa[i-1]));
		mmin=min(mmin,min(sf.sa[i],sf.sa[i-1]));
		if(mmax-mmin>mid)//注意这里是>mid而不是>=mid，如9 1 2 3 4 5 6 7 8 9这组数据，>=mid会导致5这个点重叠 
			return true;
	}
	return false;
}

int main(){
	int n;
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;i++)
			scanf("%d",&s[i]);
		for(int i=0;i<n-1;i++)
			s[i]=s[i+1]-s[i]+100;
		s[--n]=0;
		sf.build_sa(s,n+1,300);
		sf.build_high(s,n);
		int ans=0;
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(n,mid))
				l=mid+1,ans=mid;
			else
				r=mid-1;
		}
		ans++;
		if(ans<5)
			ans=0;
		printf("%d\n",ans);
	}
	return 0;
}

