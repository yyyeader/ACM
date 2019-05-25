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

char str1[N],str2[N]; 
int s[N*2],wa[N],wb[N],wsf[N],wv[N];
int sa[N],rk[N],height[N];
//sa[i]:�ֵ������ŵ�iλ�ĺ�׺�ַ�������ʼλ�� 
//rk[i]:��iΪ��ʼλ�õĺ�׺�ַ������ֵ������� 
//height[i]:�ֵ�������i��i-1�ĺ�׺�������ǰ׺

int cmp(int *r,int a,int b,int k){
	return r[a]==r[b]&&r[a+k]==r[b+k];
}

//��sa����
void build_sa(int *r,int *sa,int n,int m){
	int i,j,p,*x=wa,*y=wb;
	//�Գ���Ϊ1���ַ����������� 
	for(i=0;i<m;i++) wsf[i]=0;
	for(i=0;i<n;i++) wsf[x[i]=r[i]]++;
	for(i=1;i<m;i++) wsf[i]+=wsf[i-1];
	for(i=n-1;i>=0;i--) sa[--wsf[x[i]]]=i;
	//�������Ժ�׺��������
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
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
}

//��height���� 
void build_height(int *r,int *sa,int n){
	int i,j,k=0;
	for(i=1;i<=n;i++) rk[sa[i]]=i;
	for(i=0;i<n;i++){
		if(k) k--;
		else k=0;
		j=sa[rk[i]-1];
		while(r[i+k]==r[j+k]) k++;
		height[rk[i]]=k;
	}
//	for(int i=n;i>=1;i--) sa[i]++,rk[i]=rk[i-1];
}

int main(){
	while(~scanf("%s%s",&str1,&str2)){
		int n=0,len=strlen(str1);
		for(int i=0;i<len;i++) s[n++]=str1[i]-'a'+1;
		s[n++]=28;
		len=strlen(str2);
		for(int i=0;i<len;i++) s[n++]=str2[i]-'a'+1;
		s[n]=0;
		build_sa(s,sa,n+1,30);
		build_height(s,sa,n);
		int mmax=0,pos=0;
		len=strlen(str1);
		for(int i=2;i<n;i++){
			if(height[i]>mmax){
				if(sa[i-1]<len&&sa[i]>len)
					mmax=height[i];
				if(sa[i]<len&&sa[i-1]>len)
					mmax=height[i];
			}
		}
		printf("%d\n",mmax);
	}
	return 0;
}

