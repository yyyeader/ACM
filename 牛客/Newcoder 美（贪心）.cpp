/*������С����žͿ�����
��Ŀ���ӣ�https://www.nowcoder.com/acm/contest/86/J 
*/ 
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
const int N=1e6+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

LL a[N],res[N];

int main(){
	FAST_IO;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int i=1,j=n,idx=1;
	while(i<=j){
		if(idx%2){
			res[idx]=a[i];
			i++;
		}
		else{
			res[idx]=a[j];
			j--;
		}
		idx++;
	}
	LL ans=0;
	for(int i=1;i<=n;i++){
		if(i==1)
			ans+=abs(res[i]-res[n]);
		else
			ans+=abs(res[i]-res[i-1]);
	}
	cout<<ans<<endl;
	return 0;
}
