#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct suffix_array{
	int wa[N],wb[N],wsf[N],wv[N],sa[N],high[N],rk[N];
	//sa[i]:字典序中排第i位的后缀字符串的起始位置 
	//rk[i]:以i为起始位置的后缀字符串的字典序排名 
	//high[i]:字典序排在i和i-1的后缀的最长公共前缀
	inline bool cmp(int *r,int a,int b,int l){
		return r[a]==r[b]&&r[a+l]==r[b+l];
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

int s[N],f1[N][25];
char tmp[N];

void initst(int n){
    for(int i=1;i<=n;i++)  f1[i][0]=sf.high[i];
    for(int j=1;j<=22;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f1[i][j]=min(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
}

int st(int l, int r){
    int x = 0;
    while(1<<(x+1)<=(r-l+1)) x++;
    return min(f1[l][x],f1[r-(1<<x)+1][x]);   //找最大值改成max
}

int query(int l,int r,int n){
	if(l>r) return n-sf.sa[r];
	return st(l,r);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int k;
		scanf("%d",&k);
		scanf("%s",tmp);
		int len=strlen(tmp);
		for(int i=0;i<len;i++){
			s[i]=tmp[i];
		}
		s[len]=0;
		sf.build_sa(s,len+1,300);
		sf.build_high(s,len);
		initst(len);
		LL ans=0;
		for(int i=1;i+k-1<=len;i++){
			ans+=query(i+1,i+k-1,len);
			if(i+k<=len){
				int t1,t2;
				t1=query(i,i+k-1,len);
				t2=query(i+1,i+k,len);
				ans=ans-t1-t2+min(t1,t2);
			}
			else ans-=query(i,i+k-1,len);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

