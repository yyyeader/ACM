#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

int sum[N],a[N];
map<int,LL>mp[2];

int main(){
	FAST_IO;
	int n,mid;
	while(cin>>n>>mid){
		mp[0].clear();
		mp[1].clear();
		int pos;
		rep(i,1,n){
			cin>>a[i];
			if(a[i]==mid) pos=i;
			if(a[i]<=mid) sum[i]=sum[i-1]+1;
			else sum[i]=sum[i-1];
		}
		rep(l,1,pos){
			if(l%2==0)
				mp[0][l-2*sum[l-1]]++;
			else
				mp[1][l-2*sum[l-1]]++;
		}
		LL ans=0;
		rep(r,pos,n){
			int res=r-2*sum[r]+2;
			if(r%2==0){
				ans+=mp[0][res];
				res--;
				ans+=mp[1][res];
			}
			else{
				ans+=mp[1][res];
				res--;
				ans+=mp[0][res];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

