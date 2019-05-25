#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1e5+5;
int num;
int unit;
int arr[N],col[N],cnt[N],cnk[N],res[N],Start[N],End[N],vis[N];//cnk[i]��ʾ���ٳ���i�ε���ɫ�� 
vector<int>v[N];

struct node{
	int l,r,kj;
	int id;
}q[N];

//������Ϊ���� 
void dfs(int rt){
	Start[rt]=++num;
	//**����Ӧ��ŵ���ɫӳ�䵽�µ��߶��� 
	arr[num]=col[rt];
	vis[rt]=1;
	for(int i=0;i<v[rt].size();i++){
		if(!vis[v[rt][i]])
			dfs(v[rt][i]);
	}
	End[rt]=num;
} 

bool cmp(node a,node b){
	return a.l/unit==b.l/unit?a.r<b.r:a.l/unit<b.l/unit;
}

void add(int pos){
	cnt[arr[pos]]++;
	cnk[cnt[arr[pos]]]++;
}

void remove(int pos){
	cnk[cnt[arr[pos]]]--;
	cnt[arr[pos]]--;	
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	unit=sqrt(n);
	for(int i=1;i<=n;i++){
		scanf("%d",&col[i]);
	}
	for(int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		//**��Ŀû��ֱ��˵��a,b������ϵ���Խ���˫���ڽӱ� 
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//��1Ϊ�� 
	dfs(1);
	
	for(int i=1;i<=m;i++){
		int vj,kj;
		scanf("%d%d",&vj,&kj);
		q[i].kj=kj;
		q[i].id=i;
		q[i].l=Start[vj];
		q[i].r=End[vj];
	}
	sort(q+1,q+1+m,cmp);
	int L=q[1].l,R=L-1;
	for(int i=1;i<=m;i++){
		while(L>q[i].l)
			add(--L);
		while(L<q[i].l)
			remove(L++);
		while(R<q[i].r)
			add(++R);
		while(R>q[i].r)
			remove(R--);
		res[q[i].id]=cnk[q[i].kj];
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",res[i]);
	}
}
 
