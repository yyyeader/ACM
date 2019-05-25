#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define N 100005
using namespace std;

int n,m;
LL arr[N],c1[N],c2[N];

void init(){
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
}

void add(int p,LL val,LL a[]){
	for(int i=p;i<=n;i+=i&-i) a[i]+=val;
}

LL query(int p,LL a[]){
	LL sum=0;
	for(int i=p;i>0;i-=i&-i) sum+=a[i];
	return sum;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=n;i++){
			scanf("%lld",&arr[i]);
			add(i,arr[i]-arr[i-1],c1);
			add(i,(arr[i]-arr[i-1])*(i-1),c2);
		}
		for(int i=1;i<=m;i++){
			char s[5];
			int l,r,c;
			scanf("%s",s);
			if(s[0]=='Q'){
				scanf("%d%d",&l,&r);
				LL ans=r*query(r,c1)-query(r,c2)-(l-1)*query(l-1,c1)+query(l-1,c2);
				printf("%lld\n",ans);
			}
			else{
				scanf("%d%d%d",&l,&r,&c);
				add(l,c,c1);
				add(r+1,-c,c1);
				add(l,c*(l-1),c2);
				add(r+1,-c*r,c2);
			}
		}
	}
	return 0;
}
 
