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
	int wa[N],wb[N],wsf[N],wv[N],sa[N],high[N],rk[N];
//sa[i]:�ֵ������ŵ�iλ�ĺ�׺�ַ�������ʼλ�� 
//rk[i]:��iΪ��ʼλ�õĺ�׺�ַ������ֵ������� 
//high[i]:�ֵ�������i��i-1�ĺ�׺�������ǰ׺
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

struct node{
	LL num,cnt;//num����ֵ��cnt�ظ�����
}sk[N];

int k,len;
char tmp[N];
int s[N];

LL solve(int n){
	LL top=0,ans=0,sum,num,cnt;
	//����A��B�Ĺ��� 
	for(int i=1;i<=n;i++){
		if(sf.high[i]<k){
			top=sum=0;
			continue;
		}
		num=sf.high[i]-k+1,cnt=0;
		if(sf.sa[i-1]<len)
			sum+=num,cnt++;
		//ά��ջ�ĵ����ԣ���֤�������� 
		while(top&&sk[top].num>=num){
			node t=sk[top--];
			sum-=(t.num-num)*t.cnt;
			cnt+=t.cnt;
		}
		sk[++top]=node{num,cnt};
		if(sf.sa[i]>len) ans+=sum;
	}
	//����B��A�Ĺ��� 
	sum=0,top=0;
	for(int i=1;i<=n;i++){
		if(sf.high[i]<k){
			top=sum=0;
			continue;
		}
		num=sf.high[i]-k+1,cnt=0; 
		if(sf.sa[i-1]>len)
			sum+=num,cnt++;
		while(top&&sk[top].num>=num){
			node t=sk[top--];
			sum-=(t.num-num)*t.cnt;
			cnt+=t.cnt;
		}
		sk[++top]=node{num,cnt};
		if(sf.sa[i]<len) ans+=sum;
	}
	return ans;
}

int main(){
	while(~scanf("%d",&k)){
		if(k==0) break;
		int sum=0;
		for(int i=1;i<=2;i++){
			scanf("%s",tmp);	
			for(int j=0;tmp[j]!='\0';j++){
				s[sum++]=tmp[j];
			}
			//С�������len��A����len����Ū��B������ 
			if(i==1){
				s[sum++]=280;
				len=strlen(tmp);
			}
		}
		s[sum]=0;		
		sf.build_sa(s,sum+1,300);
		sf.build_high(s,sum);
		printf("%lld\n",solve(sum));
	}
	return 0;
}

