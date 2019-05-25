#include<bits/stdc++.h>
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
const int N=2e5+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int a[N];
vector<int>v;

int main(){
	FAST_IO;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	int ans=1;
	//三元组 
	for(int i=0;i<v.size();i++){
		for(LL j=1;j<=2e9;j*=2){
			bool t1=binary_search(v.begin(),v.end(),v[i]-j);
			bool t2=binary_search(v.begin(),v.end(),v[i]+j);
			if(t1&&t2){
				cout<<3<<endl;
				cout<<v[i]-j<<" "<<v[i]<<" "<<v[i]+j<<endl;
				return 0;
			}
		}
	}
	//二元组 
	for(int i=0;i<v.size();i++){
		for(LL j=1;j<=2e9;j*=2){
			bool t1=binary_search(v.begin(),v.end(),v[i]-j);
			bool t2=binary_search(v.begin(),v.end(),v[i]+j);
			if(t1){
				cout<<2<<endl;
				cout<<v[i]-j<<" "<<v[i]<<endl;
				return 0;
			}
			if(t2){
				cout<<2<<endl;
				cout<<v[i]<<" "<<v[i]+j<<endl;
				return 0;
			}
		}
	}
	cout<<1<<endl;
	cout<<v[0]<<endl;
	return 0;
}

