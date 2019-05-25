#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
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
const int N=1e7+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int sum[N],num[N];//num[i]记录i出现次数,sum[i]记录能被0~i的素数整除的数的个数之和 
bool prime[N];

void init(){
	//利用类似素数筛法的方式，求出能被每个素数的整除的数的个数 
	for(int i=2;i<N;i++){
		prime[i]=true;
	}
	for(int i=2;i<N;i++){
		if(prime[i]){
			sum[i]=num[i];
			for(int j=i*2;j<N;j+=i){
				prime[j]=false;
				sum[i]+=num[j];
			}
		}
	}
	for(int i=1;i<N;i++){
		sum[i]=sum[i]+sum[i-1];
	}
}

int main(){
	FAST_IO;
	int n;
	while(cin>>n){
		memset(num,0,sizeof(num));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			num[x]++;
		}
		init();
		int m;
		cin>>m;
		for(int i=1;i<=m;i++){
			int l,r;
			cin>>l>>r;
			if(l>1e7){
				cout<<"0"<<endl;
				continue;
			}
			if(r>=1e7) r=1e7;
			cout<<sum[r]-sum[l-1]<<endl;
		}
	}
	return 0;
}

