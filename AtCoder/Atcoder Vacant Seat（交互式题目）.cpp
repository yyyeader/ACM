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
#define INF 0x3f3f3f3f
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define CLR(arr,val) memset(arr,val,sizeof(arr))
#define FOR(i,start,end) for(int i=start;i<=end;i++)  
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=5e6+5;
bool flag[N];

int send(int x){
	cout<<x<<endl;
	fflush(stdout);
	string res;
	cin>>res;
	if(res=="Vacant")
		return 0;
	if(res=="Male")
		return 1;
	return 2;
}

int main(){
	int n;
	cin>>n;
	int vl=send(0),vr=send(n-1);//注意vr这句一定不能丢掉 
	int l=0,r=n-1;
	while(true){
		int mid=(l+r)/2;
		int vx=send(mid);
		if(vx==0)
			return 0;
		if((vx+vl)%2!=(r+l)%2)
			r=mid;
		else{
			l=mid;
			vl=vx;
		}
	}
	return 0;
}
