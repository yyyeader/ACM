#include<cstdio>
#include<vector>
#include<algorithm>
#include<set> 
using namespace std;
const int N=3e5+5;
typedef long long LL;
int res[N];
int n,k;
set<int>st;

struct node{
	int num;
	LL val;
}c[N];


bool cmp(node a,node b){
	return a.val>b.val;
}

int main(){
	scanf("%d%d",&n,&k);
	LL sum=0;
	for(int i=1;i<=n;i++){
		st.insert(i+k);
		scanf("%lld",&c[i].val);
		c[i].num=i;
		sum-=c[i].val*i;
	}
	sort(c+1,c+1+n,cmp);
	
	set<int>::iterator it;
	for(int i=1;i<=n;i++){
		int t=c[i].num;
		it=st.lower_bound(t);
		res[t]=*it;
		sum+=*it*c[i].val;
		st.erase(*it);
	}
	
	printf("%lld\n",sum);
	for(int i=1;i<=n;i++){
		if(i==n)
			printf("%d\n",res[i]);
		else
			printf("%d ",res[i]);
	}
} 
