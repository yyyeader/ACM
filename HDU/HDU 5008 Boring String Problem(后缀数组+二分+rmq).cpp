#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>
#define lc(p) (p<<1)
#define rc(p) (p<<1|1)
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
const int N=2e5+5;
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

int s[N];
LL sum[N];
char tmp[N];
int f1[N][25],f2[N][25];

void initst1(int n){
    for(int i=1;i<=n;i++)  f1[i][0]=sf.sa[i];
    for(int j=1;j<=22;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f1[i][j]=min(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
}

int st1(int l, int r){
    int x = 0;
    while(1<<(x+1)<=(r-l+1)) x++;
    return min(f1[l][x], f1[r-(1<<x)+1][x]);   //找最大值改成max
}


void initst2(int n){
    for(int i=1;i<=n;i++)  f2[i][0]=sf.high[i];
    for(int j=1;j<=22;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f2[i][j]=min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
}

int st2(int l, int r){
    int k=0;
    while(1<<(k+1)<=(r-l+1)) k++;
    return min(f2[l][k],f2[r-(1<<k)+1][k]);
}

int bin(int l,int r,int val){
	int ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(st2(l,mid)>=val)
			l=mid+1,ans=mid;
		else
			r=mid-1;
	}
	return ans;
}

int main(){
	while(~scanf("%s",tmp)){
		int len=strlen(tmp);
		for(int i=0;i<len;i++){
			s[i]=tmp[i];
		}
		s[len]=0;
		sf.build_sa(s,len+1,500);
		sf.build_high(s,len);
		initst1(len);
		initst2(len);
		for(int i=1;i<=len;i++){
			sum[i]=sum[i-1]+len-sf.sa[i]-sf.high[i];
		}
		int q;
		scanf("%d",&q);
		LL l=0,r=0;
		for(int i=1;i<=q;i++){
			LL k;
			scanf("%lld",&k);
			k=(l^r^k)+1;
			if(k>sum[len])
				l=0,r=0;
			else{
				LL pos=lower_bound(sum+1,sum+1+len,k)-sum;
				k-=sum[pos-1];
				l=sf.sa[pos]+1;
				r=sf.sa[pos]+k+sf.high[pos];
				LL lenn=r-l+1;
				//查找最小位置 
				LL res=bin(pos+1,len,lenn);
				if(res!=-1){
					l=st1(pos,res)+1;
					r=l+lenn-1;
				}
			}
			printf("%lld %lld\n",l,r);
		}
	}
	return 0;
}
