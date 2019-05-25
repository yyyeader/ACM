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
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int s[N];

struct suffix_array{
	int wa[N],wb[N],wsf[N],wv[N],rk[N],sa[N],high[N];
	
	bool cmp(int *r,int a,int b,int k){
		return r[a]==r[b]&&r[a+k]==r[b+k];
	}
	
	void build_sa(int *r,int n,int m){
		int i,j,p,*x=wa,*y=wb;
		for(i=0;i<m;i++) wsf[i]=0;
		for(i=0;i<n;i++) wsf[x[i]=r[i]]++;
		for(i=1;i<m;i++) wsf[i]+=wsf[i-1];
		for(i=n-1;i>=0;i--) sa[--wsf[x[i]]]=i;
		for(p=1,j=1;p<n;j*=2,m=p){
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
	void build_high(int *r,int n){
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

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			char ch;
			getchar();
			scanf("%c",&ch);
			s[i]=ch;
			s[2*n-i]=ch;
		}
		s[n]='#';
		s[2*n+1]=0;
		sf.build_sa(s,2*n+2,500);
		sf.build_high(s,2*n+1);
		int l=0,r=n+1;
		for(int i=1;i<=n;i++){
			if(sf.rk[l]<sf.rk[r])
				printf("%c",s[l++]);
			else
				printf("%c",s[r++]);
			if(i%80==0)
				puts("");
		}
	}
	return 0;
}

