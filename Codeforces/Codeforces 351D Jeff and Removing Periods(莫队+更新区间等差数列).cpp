#include<iostream>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<cstring>
using namespace std; 
const int N=1e5+5;

int ans,unit,dc;
//fl[i]��¼a[i]�����һ�����ɵȲ��λ�ã�fr[i]��¼a[i]���ҵ�һ�����ɵȲ��λ��
//pre[i]��¼��������ǰһ��a[i]��λ�ã�bak[i]��¼��������ǰһ��a[i]��λ�ã�last[a[i]]��¼a[i]������λ�� 
int a[N],cnt[N],res[N],pre[N],bak[N],last[N],fl[N],fr[N];

struct node{
	int l,r;
	int id;
}q[N];

bool cmp(node a,node b){
	return a.l/unit==b.l/unit?a.r<b.r:a.l/unit<b.l/unit;	
}

void addl(int pos,int r){
	cnt[a[pos]]++;
	if(cnt[a[pos]]==1){
		dc++;
		ans++;
	}
	
	else if(fr[pos]<=r&&fr[bak[pos]]>r) dc--;//����a[pos]֮�󲻳ɵȲ�&&����֮ǰ�ɵȲ�
}

void removel(int pos,int r){
	cnt[a[pos]]--;
	if(cnt[a[pos]]==0){
		dc--;
		ans--;
	}
	else if(fr[pos]<=r&&fr[bak[pos]]>r)	dc++;//ȥ��a[pos]֮ǰ���ɵȲ�&&ȥ��֮��ɵȲ�
}

void addr(int pos,int l){
	cnt[a[pos]]++;
	if(cnt[a[pos]]==1){
		dc++;
		ans++;
	}
	else if(fl[pos]>=l&&fl[pre[pos]]<l)	dc--;//ͬ�� 
}

void remover(int pos,int l){
	cnt[a[pos]]--;
	if(cnt[a[pos]]==0){
		dc--;
		ans--;
	}
	else if(fl[pos]>=l&&fl[pre[pos]]<l)	dc++;
}

int main(){
	int n;
	scanf("%d\n",&n);
	unit=sqrt(n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	//Ԥ����fl,fr 
	for(int i=1;i<=n;i++){
		pre[i]=last[a[i]];
		last[a[i]]=i;
		//�������ң���a[i]����С�ڵ�������ʱ����߽�Ϊ0 
		if(pre[pre[i]]==0)
			fl[i]=0;
		else if(pre[pre[i]]-pre[i]==pre[i]-i)
			fl[i]=fl[pre[i]];
		else
			fl[i]=pre[pre[i]];
	}
	//���last 
	memset(last,0,sizeof(last));
	for(int i=n;i>=1;i--){
		bak[i]=last[a[i]];
		last[a[i]]=i;
		//�������󣬵�a[i]����С�ڵ�������ʱ���ұ߽�Ϊn+1 
		if(bak[bak[i]]==0)
			 fr[i]=n+1;
		else if(bak[bak[i]]-bak[i]==bak[i]-i)
			fr[i]=fr[bak[i]];
		else
			fr[i]=bak[bak[i]];
	}
	
	
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	
	sort(q+1,q+1+m,cmp);
	
	int L=q[1].l,R=L-1;
	for(int i=1;i<=m;i++){
		//ע�⴫��add,remove�����Ҷ˵���L,R������q[i].l,q[i].r 
		while(L>q[i].l)
			addl(--L,R);
		while(L<q[i].l)
			removel(L++,R);
		while(R<q[i].r)
			addr(++R,L);
		while(R>q[i].r)
			remover(R--,L);
		if(dc>0)
			res[q[i].id]=ans;
		else
			res[q[i].id]=ans+1;
	}
	
	for(int i=1;i<=m;i++){
		printf("%d\n",res[i]);
	}
}
