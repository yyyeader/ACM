#include<stdio.h>
#include<algorithm>
#define LC(a) ((a<<1))
#define RC(a) ((a<<1)+1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
typedef long long ll;
const int N = 5e4 + 5;

struct node {
	ll l, r;
	ll sum, Start, End, color;//Start是第一个空花瓶位置，End是最后一个空花瓶位置，color=-1,0,1代表初始化，清空，插花 
}tree[N<<2];

ll leave, Start, sum, End;
void pushup(ll p) {
	//维护区间空花瓶数量 
	tree[p].sum = tree[LC(p)].sum + tree[RC(p)].sum;
	tree[p].color = (tree[LC(p)].color == tree[RC(p)].color ? tree[LC(p)].color : -1);
	//维护空花瓶起点和终点 
	if (tree[LC(p)].Start != 0)
		tree[p].Start = tree[LC(p)].Start;
	else if (tree[LC(p)].End != 0)
		tree[p].Start = tree[LC(p)].End;
	else if (tree[RC(p)].Start != 0)
		tree[p].Start = tree[RC(p)].Start;
	else if (tree[RC(p)].End != 0)
		tree[p].Start = tree[RC(p)].End;
	else
		tree[p].Start = 0;
	tree[p].End = max(max(tree[LC(p)].Start, tree[LC(p)].End), max(tree[RC(p)].Start, tree[RC(p)].End));
}

void pushdown(ll p) {
	if (tree[p].color == 0) {
		tree[LC(p)].sum = tree[LC(p)].r - tree[LC(p)].l + 1;
		tree[LC(p)].Start = tree[LC(p)].l;
		tree[LC(p)].End = tree[LC(p)].r;
		tree[RC(p)].sum = tree[RC(p)].r - tree[RC(p)].l + 1;
		tree[RC(p)].Start = tree[RC(p)].l;
		tree[RC(p)].End = tree[RC(p)].r;
		tree[LC(p)].color = tree[RC(p)].color = 0;
	}
	else if (tree[p].color == 1) {
		tree[LC(p)].sum = tree[LC(p)].Start = tree[LC(p)].End = tree[RC(p)].sum = tree[RC(p)].Start = tree[RC(p)].End = 0;
		tree[LC(p)].color = tree[RC(p)].color = 1;
	}
}
 
void build(ll p, ll l, ll r) {
	tree[p].l = l;
	tree[p].r = r;
	tree[p].Start = tree[p].End = 0;
	tree[p].sum = 0;
	if (l == r) {
		tree[p].Start = tree[p].End = l;
		tree[p].sum = 1;
		tree[p].color = -1;
		return;
	}
	build(LC(p), l, MID(l, r));
	build(RC(p), MID(l, r) + 1, r);
	pushup(p);
}
//清空 
void update(ll p, ll l, ll r) {
	if (r<tree[p].l || l>tree[p].r)
		return;
	if (l <= tree[p].l&&r >= tree[p].r) {
		sum += (tree[p].r - tree[p].l + 1 - tree[p].sum);
		tree[p].Start = tree[p].l;
		tree[p].End = tree[p].r;
		tree[p].sum = tree[p].r - tree[p].l + 1;
		tree[p].color = 0;
		return;
	}
	pushdown(p);
	update(LC(p), l, r);
	update(RC(p), l, r);
	pushup(p);
}
//插花 
void query(ll p, ll l, ll r) {
	if (r<tree[p].l || l>tree[p].r)
		return;
	if (leave == 0 || tree[p].sum == 0)
		return;
	if (l <= tree[p].l&&r >= tree[p].r) {
		if (Start == 0)
			Start = tree[p].Start;
		if (leave >= tree[p].sum) {
			leave -= tree[p].sum;
			End = max(End, tree[p].End);
			tree[p].sum = tree[p].Start = tree[p].End = 0;
			tree[p].color = 1;
			return;
		}
	}
	pushdown(p);
	query(LC(p), l, r);
	query(RC(p), l, r);
	pushup(p);
}
int main() {
	ll q;
	scanf("%I64d",&q);
	while (q--) {
		ll n, m;
		scanf("%I64d %I64d",&n,&m);
		build(1, 1, n);
		while (m--) {
			ll k;
			scanf("%I64d",&k);
			//插花 
			if (k == 1) {
				ll a, f;
				scanf("%I64d %I64d",&a,&f);
				End = Start = 0;
				leave = f;
				query(1, a + 1, n);
				if (Start == 0)
					printf("Can not put any one.\n");
				else
					printf("%I64d %I64d\n",Start-1,End-1);
			}
			//清空 
			else {
				ll a, b;
				scanf("%I64d %I64d",&a,&b);
				sum = 0;
				update(1, a + 1, b + 1);
				printf("%I64d\n",sum);
			}
		}
		printf("\n");
	}
	return 0;
}

