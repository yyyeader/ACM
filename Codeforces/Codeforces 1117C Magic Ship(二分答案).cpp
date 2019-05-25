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

string s;
int d[4][2]={0,1,0,-1,-1,0,1,0};
int dir[256],fp[4];

bool check(LL x1,LL y1,LL x2,LL y2,LL mid){
	int len=s.length();
	LL t=mid/len;
	for(int i=0;i<4;i++) x1+=fp[i]*t*d[i][0],y1+=fp[i]*t*d[i][1];
	t=mid-len*(mid/len);
	for(int i=0;i<t;i++){
		int p=dir[s[i]];
		x1+=d[p][0];
		y1+=d[p][1];
	}
	LL left=abs(x1-x2)+abs(y1-y2);
	if(left>mid) return false;
	return true;
}

int main(){
	dir['U']=0,dir['D']=1,dir['L']=2,dir['R']=3;
	LL x1,y1,x2,y2,n;
	cin>>x1>>y1>>x2>>y2>>n>>s;
	for(int i=0;i<n;i++){
		int p=dir[s[i]];
		fp[p]++;
	}
	LL l=0,r=1e18,ans=-1;
	while(l<=r){
		LL mid=(l+r)/2;
		if(check(x1,y1,x2,y2,mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}

