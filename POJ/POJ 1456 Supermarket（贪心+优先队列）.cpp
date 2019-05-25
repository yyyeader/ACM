#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
#define LC(a) (a<<1)
#define RC(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N=5e4+5;

struct node{
	int dx,val;
	bool operator <(const node &b) const{
		return dx>b.dx;
	}
}arr[N];

int main(){
	int n;
	while(~scanf("%d",&n)){
		int lim=0;
		priority_queue<int,vector<int>,less<int> >q;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&arr[i].val,&arr[i].dx);
			lim=max(arr[i].dx,lim);
		}
		sort(arr+1,arr+1+n); 
		int pos=1,ans=0;
		for(int i=lim;i>=1;i--){
			while(arr[pos].dx>=i&&pos<=n){
				q.push(arr[pos].val);
				pos++;
			}
			//保证每个单位时间获得的都是最大利润 
			if(!q.empty()){
				ans+=q.top();
				q.pop();
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
