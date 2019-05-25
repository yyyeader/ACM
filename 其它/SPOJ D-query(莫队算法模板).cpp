#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=3e5+5;//区间范围 
const int MAX=1e6+5;//最大数字 
int unit,cnt[MAX],arr[N],res[N],ans=0;

struct node{
	int l,r,id;
}q[N];

bool cmp(node a,node b){
	return a.l/unit!=b.l/unit?a.l/unit<b.l/unit:a.r<b.r;
}

void add(int pos){
	cnt[arr[pos]]++;
	if(cnt[arr[pos]]==1){
		ans++;
	}
}

void remove(int pos){
	cnt[arr[pos]]--;
	if(cnt[arr[pos]]==0){
		ans--;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	unit=sqrt(n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}	
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	
	sort(q+1,q+m+1,cmp);
	
	int L=q[1].l,R=L-1;
	for(int i=1;i<=m;i++){
		while(L>q[i].l)
			add(--L);
		while(L<q[i].l)
			remove(L++);
		while(R>q[i].r)
			remove(R--);
		while(R<q[i].r)
			add(++R);
		res[q[i].id]=ans;
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",res[i]);
	}
}




