#include<stdio.h>
#include<string.h>
#define LL long long
#define MAX 100005
LL ans=0;
struct Tree
{
	LL l,r;
	LL sum,add;
};
Tree tree[MAX*4];

void pushup(LL x)
{
	LL tmp=2*x;
	tree[x].sum=tree[tmp].sum+tree[tmp+1].sum;
}

void pushdown(LL x)
{
	LL tmp=2*x;
	tree[tmp].add+=tree[x].add;
	tree[tmp+1].add+=tree[x].add;
	tree[tmp].sum+=tree[x].add*(tree[tmp].r-tree[tmp].l+1);
	tree[tmp+1].sum+=tree[x].add*(tree[tmp+1].r-tree[tmp+1].l+1);
	tree[x].add=0;
}

void build(int l,int r,int x)
{
	tree[x].l=l;
	tree[x].r=r;
	tree[x].add=0;
	tree[x].sum=0;
	if(l==r)
	{
		return ;
	}
	int tmp=x<<1;
	int mid=(l+r)>>1;
	build(l,mid,tmp);
	build(mid+1,r,tmp+1);
	pushup(x);	 //����ڽ����Ĺ����и�sum��ֵ���ǵú���Ҫpushup
}

void update(LL l,LL r,LL c,LL x)
{
	if(r<tree[x].l||l>tree[x].r)
		return ;
	if(l<=tree[x].l&&r>=tree[x].r)
	{
		tree[x].add+=c;
		tree[x].sum+=c*(tree[x].r-tree[x].l+1);
		return ;
	}
	if(tree[x].add)
		pushdown(x);
	LL tmp=x<<1;
	update(l,r,c,tmp);
	update(l,r,c,tmp+1);
	pushup(x);
}


void query(LL l,LL r,LL x)
{
	if(r<tree[x].l||l>tree[x].r)	//Ҫ���µ����䲻�ڸ�������
		return ;
	if(l<=tree[x].l&&r>=tree[x].r)	  //Ҫ������������˸�����
	{
		ans+=tree[x].sum;
		return ;
	}
	if(tree[x].add)
		pushdown(x);
	LL tmp=x<<1;
	LL mid=(tree[x].l+tree[x].r)>>1;
	if(r<=mid)
		query(l,r,tmp);
	else if(l>mid)
		query(l,r,tmp+1);
	else
	{
		query(l,mid,tmp);
		query(mid+1,r,tmp+1);
	}
}

int main(){
	int n,l,r,i;
	while(~scanf("%d",&n)&&n){
		build(1,n,1);
		for(i=1;i<=n;i++){
			scanf("%d %d",&l,&r);
			update(l,r,1,1);
		}	
		for(i=1;i<=n;i++){
			if(i!=n){
				query(i,i,1);
				printf("%d ",ans);
				ans=0;
			}
			else{
				query(i,i,1);
				printf("%lld\n",ans);
				ans=0;
			}	
		}
	}
}

