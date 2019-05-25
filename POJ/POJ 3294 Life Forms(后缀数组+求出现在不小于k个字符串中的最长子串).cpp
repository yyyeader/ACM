#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#include<queue>
#include<string>
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

int s[N],wa[N],wb[N],wsf[N],wv[N],sa[N],high[N],rk[N],id[N];
char str[N];
bool vis[105];
set<string>ans;

bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}

void build_sa(int *r,int *sa,int n,int m){
	int i,j,p,*x=wa,*y=wb;
	for(i=0;i<m;i++) wsf[i]=0;
	for(i=0;i<n;i++) wsf[x[i]=r[i]]++;
	for(i=1;i<m;i++) wsf[i]+=wsf[i-1];
	for(i=n-1;i>=0;i--) sa[--wsf[x[i]]]=i;
	for(j=1,p=1;p<n;j*=2,m=p){
		for(p=0,i=n-j;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0;i<n;i++) wv[i]=x[y[i]];
		for(i=0;i<m;i++) wsf[i]=0;
		for(i=0;i<n;i++) wsf[wv[i]]++;
		for(i=1;i<m;i++) wsf[i]+=wsf[i-1];
		for(i=n-1;i>=0;i--) sa[--wsf[wv[i]]]=y[i];
		swap(x,y);x[sa[0]]=0;
		for(p=1,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
}

void build_high(int *r,int *sa,int n){
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

bool check(int n,int mid,int k){
	memset(vis,false,sizeof(vis));
	int cnt=0;
	bool flag=false,sign=false;
	for(int i=2;i<=n;i++){
		if(high[i]<mid){
			cnt=0;
			sign=false;
			memset(vis,false,sizeof(vis));
			continue;
		}
		if(!vis[id[sa[i-1]]]) cnt++,vis[id[sa[i-1]]]=true;
		if(!vis[id[sa[i]]]) cnt++,vis[id[sa[i]]]=true;
		if(cnt>k){
			if(sign) continue;//避免多次计算同一个字符串等价于cnt==k+1 
			sign=true;
			if(!flag){
				ans.clear();
				flag=true;
			}
			string t="";
			for(int j=sa[i];j<=sa[i]+mid-1;j++)
				t+=char(s[j]);
			ans.insert(t);
		}
	}
	return flag;
}

int main(){
	FAST_IO;
	int n;
	while(cin>>n){
		if(n==0) break;
		ans.clear();
		int len,sum=0;
		for(int i=1;i<=n;i++){
			cin>>str;
			len=strlen(str);
			for(int j=0;j<len;j++){
				id[sum]=i;
				s[sum++]=str[j];
			}
			s[sum++]=300+i;
		}
		s[sum]=0;
		build_sa(s,sa,sum+1,1000);
		build_high(s,sa,sum);
		int l=1,r=len;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(sum,mid,n/2))
				l=mid+1;
			else
				r=mid-1;
		}
		if(ans.size()>0){
			set<string>::iterator it=ans.begin();
			while(it!=ans.end()){
				cout<<*it<<endl;
				it++;
			}
			cout<<endl;
		}
		else cout<<"?"<<endl<<endl;
	}
	return 0;
}
