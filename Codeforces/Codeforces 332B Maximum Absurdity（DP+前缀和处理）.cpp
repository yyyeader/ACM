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

LL sum[N];	  //��¼ǰ׺�� 
LL maxsum[N]; //maxsum[i]��¼i~n���ĳ���Ϊk�Ӷεĺ� 
int idx[N];	  //idx[i]��¼��Ӧ��i~n����Ӷε���� 

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
		LL now=sum[i+k-1]-sum[i-1]; //nowΪi~i+k-1֮��  
		if(now>=maxsum[i+1]){		//��ΪҪ��֤���ֵ�����С�������±���С��ȡ 
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
		if(now+maxsum[i+k]>mmax){ //maxsum[i+k]Ϊi+k~n���ĳ���Ϊk���Ӷκ�
			mmax=now+maxsum[i+k];
			st1=i,st2=idx[i+k];
		}
	}
	cout<<st1<<" "<<st2<<endl;
	return 0;
}
