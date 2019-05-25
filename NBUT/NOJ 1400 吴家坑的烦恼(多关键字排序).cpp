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

struct node{
	string name;
	int year,cost;
}a[105];

bool cmp(node a,node b){
	if(a.name==b.name){
		if(a.year==b.year){
			return a.cost>b.cost;
		}
		else return a.year<b.year;
	}
	else return a.name<b.name;
}

int main(){
	int n,cas=0;
	while(cin>>n){
		if(n==0) break;
		for(int i=1;i<=n;i++) cin>>a[i].name>>a[i].year>>a[i].cost;
		sort(a+1,a+1+n,cmp);
		printf("Case %d:\n",++cas);
		for(int i=1;i<=n;i++){
			cout<<a[i].name<<" "<<a[i].year<<" "<<a[i].cost<<endl;
		}
		cout<<endl;
	}
	return 0;
}

