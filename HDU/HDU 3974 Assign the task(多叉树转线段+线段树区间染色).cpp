#include<iostream>
#include<cstring>
#include<vector>
#define LC(a) ((a<<1))
#define RC(a) ((a<<1)+1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int N=5e4+5;
typedef long long ll;

vector<ll>v[N];
ll Start[N],End[N];//每个员工所有下属的开始和结束节点，包含本身
ll ans,cnt;//cnt用于记录节点的编号
bool used[N];

void dfs(ll rt){
	Start[rt]=++cnt;
	for(int i=0;i<v[rt].size();i++){
		dfs(v[rt][i]);
	}
	End[rt]=cnt;
}

struct node{
	ll l,r;
	ll task;//task=-2表示下属工作不同 
}tree[N*4];

void pushup(ll p){
	tree[p].task=(tree[LC(p)].task==tree[RC(p)].task?tree[LC(p)].task:-2);
}

void pushdown(ll p){
	tree[LC(p)].task=tree[RC(p)].task=tree[p].task;
}

void build(ll p,ll l,ll r){
	tree[p].l=l;
	tree[p].r=r;
	tree[p].task=-1;
	if(l==r){
		return;
	}
	build(LC(p),l,MID(l,r));
	build(RC(p),MID(l,r)+1,r);
}

void update(ll p,ll l,ll r,ll task){
	if(r<tree[p].l||l>tree[p].r)
		return;
	if(l<=tree[p].l&&r>=tree[p].r){
		tree[p].task=task;
		return;
	}
	if(tree[p].task!=-2)
		pushdown(p);
	update(LC(p),l,r,task);
	update(RC(p),l,r,task);
	pushup(p);
}

void query(ll p,ll t){
	if(tree[p].task!=-2){
		ans=tree[p].task;
		return;
	}
	ll mid=MID(tree[p].l,tree[p].r);
	if(t<=mid)
		query(LC(p),t);
	else
		query(RC(p),t);
}

int main(){
	ios::sync_with_stdio(false);
	ll t;
	ll cas=0;
	cin>>t;
	while(t--){
		cas++;
		//初始化 
		cnt=0; 
		memset(used,false,sizeof(used));
		for(int i=1;i<=N;i++){
			v[i].clear();
		}
		
		ll n;
		cin>>n;
		for(int i=1;i<=n-1;i++){
			ll	rt,chd;
			cin>>chd>>rt;
			used[chd]=true;
			v[rt].push_back(chd);
		}
		//将多叉树转化为线段 
		for(int i=1;i<=n;i++){
			//找到根结点 
			if(!used[i]){
				dfs(i);
				break;
			}
		}
		//建树 
		build(1,1,n); 
		ll m;
		cout<<"Case #"<<cas<<":"<<endl;
		cin>>m;	
		for(int i=1;i<=m;i++){
			char op;
			cin>>op;
			if(op=='C'){
				ll x,t;
				cin>>x;
				t=Start[x];
				query(1,t);
				cout<<ans<<endl;
			}
			else{
				ll x,l,r,task;
				cin>>x>>task;
				l=Start[x];
				r=End[x];
				update(1,l,r,task);
			}
		}			
	}
}
