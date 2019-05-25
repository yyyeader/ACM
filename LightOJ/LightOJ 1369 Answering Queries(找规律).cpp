#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
const int N=1e5+5;
int a[N];

int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		printf("Case %d:\n",++cas);
		LL sum=0;
		for(int i=0;i<n;i++){
			sum+=(LL)(n-1-2*i)*a[i];
		}
		while(q--){
			int op;
			scanf("%d",&op);
			if(op==1){
				printf("%lld\n",sum);
			}
			else{
				int pos,v;
				scanf("%d%d",&pos,&v);
				//改变数组元素时，把sum也改变 
				sum-=(LL)(n-2*pos-1)*a[pos];
				sum+=(LL)(n-2*pos-1)*v;
				a[pos]=v;
			}
		}
	}
}
