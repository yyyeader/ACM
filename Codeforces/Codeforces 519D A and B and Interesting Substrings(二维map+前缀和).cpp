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
const int N=1e5+5;
const LL INF64=1e18;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int val[30];
map<LL,int>mp[30];

int main(){
	for(int i=0;i<26;i++){
		cin>>val[i];
	}
	string str;
	cin>>str;
	LL sum=0,ans=0;
	for(int i=0;i<str.length();i++){
		int ch=str[i]-'a';
		//注意先计算ans, 再sum+=val[ch]
		//因为sum[i-1]-sum[x]==0才能说明sum(i-1~x+1)这一段为0 
		ans+=mp[ch][sum];
		sum+=val[ch];
		mp[ch][sum]++;
	}
	cout<<ans<<endl;
	return 0;
}
