#include<iostream>
#include<cstdio>
#include<cstring>
#define lc(p) (p<<1)
#define rc(p) (p<<1|1)
using namespace std;
const int N=1e5+5;
const int INF=0x3f3f3f3f;

int cas;
int s[N];
char str[N];

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

struct segment_tree{
	struct node{
		int l,r,mmin;	
	}tree[N*4];
	
	void pushup(int p){
		tree[p].mmin=min(tree[lc(p)].mmin,tree[rc(p)].mmin);
	}
	
	void build(int p,int l,int r){
		tree[p].l=l;
		tree[p].r=r;
		if(l==r){
			tree[p].mmin=sf.high[l];
			return;
		}
		int mid=(l+r)/2;
		build(lc(p),l,mid);
		build(rc(p),mid+1,r);
		pushup(p);
	}
	
	int query(int p,int l,int r){
		if(tree[p].r<l||tree[p].l>r)
			return INF;
		if(l<=tree[p].l&&tree[p].r<=r)
			return tree[p].mmin;
		return min(query(lc(p),l,r),query(rc(p),l,r));
	}
}sg;

void solve(int n){
	int al=0,ar=0,ans=0;
	for(int L=1;2*L<=n;L++){
		for(int i=0;(i+1)*L<n;i++){
			int x=L*i,y=(i+1)*L;
			if(s[x]!=s[y]) continue;
			int t=sg.query(1,min(sf.rk[x],sf.rk[y])+1,max(sf.rk[x],sf.rk[y])); //找最长公共前缀 
			int r=y+t-1;
			for(int j=0;j<L;j++){
				if(x-j<0||s[x-j]!=s[y-j]) break;
				int l=x-j;
				int now=(r-l+1)/L;
				if(x+t<y-j) continue; //如kabkbakbvkab
                if(now>ans || (now==ans && sf.rk[l]<sf.rk[al])) ans=now,al=l,ar=l+now*L-1;//注意ar=L+now*L-1,否则如acbacbac会输出acbacbac而不是acbacb 
			}
		}
	}
	printf("Case %d: ",++cas);
	if(ans==0){
		int mmin=s[0];
		for(int i=0;i<n;i++)
			mmin=min(mmin,s[i]);
		printf("%c\n",mmin);
		return;
	}
	for(int i=al;i<=ar;i++){
		printf("%c",s[i]);
	}
	puts("");
}

int main(){
	cas=0;
	while(~scanf("%s",str)){
		if(str[0]=='#') break;
		int len=strlen(str);
		for(int i=0;i<len;i++){
			s[i]=str[i];
		}
		s[len]=0;
		sf.build_sa(s,len+1,300);
		sf.build_high(s,len);
		sg.build(1,1,len);
		solve(len);
	}
	return 0;
} 
