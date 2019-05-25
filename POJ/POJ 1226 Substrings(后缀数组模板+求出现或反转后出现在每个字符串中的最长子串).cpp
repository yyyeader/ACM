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

int n,ans;
int s[N],id[N];
bool vis[N];
char str[105][105];

struct suffix_array{
	int wa[N],wb[N],wsf[N],wv[N],sa[N],high[N],rk[N];
	//rk[i]表示以i为初始位置的后缀的排名
	//sa[i]表示排名第i的后缀的起始位置
	//high[i]表示sa[i]和sa[i-1]的最长公共前缀 
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

bool check(int mid,int len){
	memset(vis,false,sizeof(vis));
	int cnt=0;
	for(int i=2;i<=len;i++){
		if(sf.high[i]<mid){
			cnt=0;
			memset(vis,false,sizeof(vis));
			continue;
		}
		if(!vis[id[sf.sa[i-1]]]) cnt++,vis[id[sf.sa[i-1]]]=true;
		if(!vis[id[sf.sa[i]]]) cnt++,vis[id[sf.sa[i]]]=true;
		if(cnt==n)
			return true;
	}
	return false;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int len,sum=0;
		for(int i=1;i<=n;i++){
			scanf("%s",str[i]);
			len=strlen(str[i]);
			for(int j=0;j<len;j++){
				id[sum]=i;
				s[sum++]=str[i][j];
			}
			s[sum++]=300+i;
		}
		for(int i=1;i<=n;i++){
			len=strlen(str[i]);
			for(int j=len-1;j>=0;j--){
				id[sum]=i;
				s[sum++]=str[i][j];
			}
			s[sum++]=300+i+n;
		}
		s[sum]=0;
		sf.build_sa(s,sum+1,1000);
		sf.build_high(s,sum);
		int l=1,r=len,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,sum))
				l=mid+1,ans=mid;
			else 
				r=mid-1;
		}
		if(n==1)
			printf("%d\n",len);
		else
			printf("%d\n",ans);
	}
	return 0;
}
