#include<cstring>
#include<stdio.h>
#include<iostream>
#define LC(a) ((a<<1))
#define RC(a) ((a<<1)+1)
#define MID(a,b) ((a+b)>>1) 
using namespace std;
typedef long long ll;
const int N=8e3*4;

struct node{
	ll l,r;
	ll color;//��ɫΪ-2��ʾ���ɫ 
}tree[N];

ll ans[N];
ll vis[N]; 
//���� 
void pushdown(ll p){
	tree[RC(p)].color=tree[LC(p)].color=tree[p].color;
}
//���� 
void pushup(ll p){
	tree[p].color=(tree[LC(p)].color==tree[RC(p)].color?tree[LC(p)].color:-2);
}

void build(ll p,ll l,ll r){
	tree[p].l=l;
	tree[p].r=r;
	tree[p].color=-1;//��ʼ����ɫ��������� 
	if(l==r){
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
}

void update(ll p,ll l,ll r,ll color){
	if(r<tree[p].l||l>tree[p].r)
		return;
	if(tree[p].color==color)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		tree[p].color=color;		
		return;
	}
	//**�ͷ�lazy��� 
	if(tree[p].color!=-2){
		pushdown(p);
	}
	update(LC(p),l,r,color);
	update(RC(p),l,r,color);
	pushup(p);
}

void query(ll p,ll l,ll r){
	if(r<tree[p].l||l>tree[p].r)
		return;
	
	//��ɫ������������ȥ 
	if(tree[p].color!=-2){
		//**ʹ��vis�����¼������ɫ 
		for(int i=tree[p].l;i<=tree[p].r;i++){
			vis[i]=tree[p].color;
		}
		return;
	}		
	query(LC(p),l,r);
	query(RC(p),l,r);
}

int main(){
	ios::sync_with_stdio(false);
	ll n;
	//ע���Ǵ�0~n 
	while(cin>>n){
		build(1,1,8000);
		ll maxc=0;
		for(int i=1;i<=n;i++){
			ll l,r,color;
			cin>>l>>r>>color;
			maxc=max(maxc,color);
			update(1,l+1,r,color);
		}
		memset(ans,0,sizeof(ans));
		memset(vis,-1,sizeof(vis));
		query(1,1,8000);
		//����vis���飬ͳ�Ƹ���ɫ������ 
		for(int i=1;i<=8000;i++){
			if(vis[i]!=vis[i-1]&&vis[i]!=-1)
				ans[vis[i]]++;
		}
		for(int i=0;i<=maxc;i++){
			if(ans[i])
				cout<<i<<" "<<ans[i]<<endl;
		}
		cout<<endl;
	}
}
