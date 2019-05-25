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
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

struct suffix_array{
	int wa[N],wb[N],wv[N],wsf[N],sa[N],high[N],rk[N];
	
	inline bool cmp(int *r,int a,int b,int k){
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
			for(p=1,i=1;i<n;i++){
				x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
			}
		}
	}
	
	inline void build_high(int *r,int n){
		int i,j,k=0;
		for(i=1;i<=n;i++) rk[sa[i]]=i;
		for(i=0;i<n;i++){
			if(k) k--;
			else k=0;
			j=sa[rk[i]-1];
			while(r[i+k]==r[j+k]) k++;
			high[rk[i]]=k;
		}
	}
}sf;

int n;
int s[N],id[N];
bool vis[4005];
char tmp[305];
string ans;

bool check(int mid,int len){
	int cnt=0;
	memset(vis,false,sizeof(vis));
	for(int i=0;i<len;i++){
		if(sf.high[i]<mid){
			cnt=0;
			memset(vis,false,sizeof(vis));
			continue;
		}
		if(!vis[id[sf.sa[i]]]) vis[id[sf.sa[i]]]=true,cnt++;
		if(!vis[id[sf.sa[i-1]]]) vis[id[sf.sa[i-1]]]=true,cnt++;
		if(cnt==n){
			ans="";
			for(int j=0;j<mid;j++){
				ans+=char(s[sf.sa[i]+j]+'a');
			}
			return true;
		}
	}
	return false;
}

int main(){
	while(~scanf("%d",&n)&&n) {
		int len,sum=0;
		for(int i=1;i<=n;i++){
			scanf("%s",tmp);
			len=strlen(tmp);
			for(int j=0;j<len;j++){
				id[sum]=i;
				s[sum++]=tmp[j]-'a';
			}
			s[sum++]=30+i;
		}
		s[sum]=0;
		sf.build_sa(s,sum+1,5000);
		sf.build_high(s,sum);
		ans="";
		int l=0,r=len;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,sum))
				l=mid+1;
			else
				r=mid-1;
		}
		if(ans.length()==0)
			cout<<"IDENTITY LOST"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}

