#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<vector>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
#define bugc(_) cout << (#_) << " = " << (_) << endl;
using namespace std;
const double eps=1e-8;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int n,m,l,sum;
int root[N];
LL a[N];

int find(int x){
	return root[x]==x?x:root[x]=find(root[x]);
}

void combine(int x,int y){
	if(a[x]<=l||a[y]<=l) return;
	int t1=find(x),t2=find(y);
	root[t2]=t1;
	sum--;
}

int main(){
	scanf("%d%d%d",&n,&m,&l);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>l){
			sum++;
			root[i]=i;
		}
	}
	for(int i=1;i<=n;i++) combine(i-1,i);
	for(int i=1;i<=m;i++){
		int op;
		scanf("%d",&op);
		if(op==0)
			printf("%d\n",sum);
		else{
			int pos;
			LL len;
			scanf("%d%lld",&pos,&len);
			a[pos]+=len;
			if(a[pos]>l&&a[pos]-len<=l){
				sum++;
				root[pos]=pos;
				combine(pos-1,pos);
				combine(pos,pos+1);
			}
		}
	}
	return 0;
}

