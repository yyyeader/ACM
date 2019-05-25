#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#define LL long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=2e5+5;

int a[N],b[N];
vector<LL>v;
map<LL,LL>mp;

LL cal(LL x,LL p){
	int l=0,r=mp[p];
	while(l<=r){
		int mid=(l+r)>>1;
		if(mid*p<=x)
			l=mid+1;
		else
			r=mid-1;
	}
	return min(l,r);
}

int main(){
	FAST_IO;
	LL n,q;
	scanf("%lld%lld",&n,&q);
	rep(i,1,n) scanf("%lld",&a[i]),v.push_back(a[i]),mp[a[i]]++;
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	rep(j,1,q){
		scanf("%lld",&b[j]);
		LL ans=0;
		int en=v.size();
		while(b[j]&&en>=0){
			LL pos=upper_bound(v.begin(),v.begin()+en,b[j])-v.begin();//找第一个大于b[j]的二进制数
			pos--;
			if(pos<0) break;
			while(pos>=0&&b[j]>=v[pos]){
				LL size=cal(b[j],v[pos]);
				b[j]-=size*v[pos];
				ans+=size;
				pos--;
				en=pos+1;
			}
		}
		if(b[j])
			puts("-1");
		else
			printf("%lld\n",ans);
	}
	return 0;
}
