#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=3e5+5;//区间范围 
const int MAX=1e6+5;//最大数字 
int unit,cnt[MAX],arr[N],res[N],ans=0;

struct node{
	int l,r,id;
}q[N];

bool cmp(node a,node b){
	if(a.l/unit==b.l/unit) {
		if(a.l/unit%2)
			return a.r<b.r;
		else
			return a.r>b.r;
	}
	return a.l/unit<b.l/unit;
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
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(cnt,0,sizeof(cnt));
		ans=0;
		unit=sqrt(n);
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
			if(cnt[arr[i]]==0) ans++;
			cnt[arr[i]]++;
		}
		int cnt=0;
		for(int i=1;i<=m;i++){
			int l,r;
			scanf("%d%d",&l,&r);
//			if(l>r)
//				swap(l,r);
			if(r-l>1){
				q[++cnt].l=++l;
				q[cnt].r=--r;
				q[cnt].id=i;
			}
			else
				res[i]=ans;
		}
		sort(q+1,q+cnt+1,cmp);
		int L=q[1].l,R=L-1;
		for(int i=1;i<=cnt;i++){
			while(L>q[i].l)
				remove(--L);
			while(L<q[i].l)
				add(L++);
			while(R>q[i].r)
				add(R--);
			while(R<q[i].r)
				remove(++R);
			res[q[i].id]=ans;
		}
		for(int i=1;i<=m;i++){
			printf("%d\n",res[i]);
		}
	}
}




