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
const int INF=0x3f3f3f3f;

int cnt[N];
vector<int>v;
map<int,int>mp;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		v.clear();mp.clear();
		int n;
		scanf("%d",&n);
		int flag=-1;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			mp[x]++;
			if(mp[x]==4)
				flag=x;
			if(mp[x]==2) v.push_back(x);
		}
		if(flag!=-1){
			for(int i=1;i<=3;i++) printf("%d ",flag);
			printf("%d\n",flag);
			continue;
		}
		sort(v.begin(),v.end());
		double min=1e18;
		int ma,mb;
		for(int i=0;i<v.size()-1;i++){
			int a=v[i],b=v[i+1];
			double res=1.0*(2*a+2*b)*(2*a+2*b)/(a*b);
			if(res<min){
				min=res;
				ma=a,mb=b;
			}
		}
		printf("%d %d %d %d\n",ma,ma,mb,mb);
	}
	return 0;
}

