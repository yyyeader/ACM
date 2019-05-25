#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<cctype>
#include<math.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define lc(a) (a<<1)
#define rc(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)  
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=5e6+5;
const LL INF64=1e18;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

LL sum[N];	  //记录前缀和 
LL maxsum[N]; //maxsum[i]记录i~n最大的长度为k子段的和 
int idx[N];	  //idx[i]记录相应的i~n最大子段的起点 

int main(){
	FAST_IO;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
		sum[i]+=sum[i-1];
	}
	int lim=n-k+1;
	for(int i=lim;i>=1;i--){
		LL now=sum[i+k-1]-sum[i-1]; //now为i~i+k-1之和  
		if(now>=maxsum[i+1]){		//因为要保证答案字典序最小，所以下标往小的取 
			maxsum[i]=now;
			idx[i]=i;
		}
		else{
			maxsum[i]=maxsum[i+1];
			idx[i]=idx[i+1];
		}
	}

	int st1=1,st2=k+1;
	LL mmax=sum[2*k];
	for(int i=1;i<=lim-k;i++){
		LL now=sum[i+k-1]-sum[i-1];
		if(now+maxsum[i+k]>mmax){ //maxsum[i+k]为i+k~n最大的长度为k的子段和
			mmax=now+maxsum[i+k];
			st1=i,st2=idx[i+k];
		}
	}
	cout<<st1<<" "<<st2<<endl;
	return 0;
}
