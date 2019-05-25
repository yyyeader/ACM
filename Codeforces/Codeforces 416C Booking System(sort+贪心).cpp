#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<cctype>
#include<math.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
#define lc(a) (a<<1)
#define rc(a) (a<<1|1)
#define MID(a,b) ((a+b)>>1)
#define fin(name)  freopen(name,"r",stdin)
#define fout(name) freopen(name,"w",stdout)
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define _for(i,start,end) for(int i=start;i<=end;i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long LL;
const int N=1e3+5;
const LL INF64=1e18;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

struct node{
	int c,p,id;
}a[N];

struct rnode{
	int id,x;
	rnode(int id,int x):id(id),x(x){}
};

struct qnode{
	int id,tab;
	qnode(int id,int tab):id(id),tab(tab){}
};

vector<rnode>v;
vector<qnode>ans;

bool cmp(node a,node b){
	return a.p>b.p;
}

bool cmp1(rnode a,rnode b){
	return a.x<b.x;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].p;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		v.push_back(rnode(i,x));
	}
	sort(v.begin(),v.end(),cmp1);
	int sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		int idx=-1;
		for(int j=0;j<v.size();j++){
			if(v[j].x>=a[i].c){
				idx=j;
				break;
			}
		}	
		if(idx!=-1){
			sum+=a[i].p;
			cnt++;
			ans.push_back(qnode(a[i].id,v[idx].id));
			v.erase(v.begin()+idx);
		}
	}
	cout<<cnt<<" "<<sum<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].id<<" "<<ans[i].tab<<endl;
	}
	return 0;
}

