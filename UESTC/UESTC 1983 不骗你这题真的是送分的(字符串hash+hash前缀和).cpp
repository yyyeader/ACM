#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
#define bug cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;

ull Hash[N],p[N];
string str;

void pre_cal(){
	p[0]=1;
	p[1]=163;
	rep(i,2,N-1)
		p[i]=p[1]*p[i-1];
}

void cal_hash(){
	pre_cal();
	int len=str.length()-1;
	rep(i,1,len){
		Hash[i]=Hash[i-1]*p[1]+str[i]-'a';
	}
}

int main(){
	cin>>str;
	str=" "+str;
	cal_hash();
	int m;
	cin>>m;
	rep(i,1,m){
		int l,r;
		cin>>l>>r;
		cout<<Hash[r]-Hash[l-1]*p[r-l+1]<<endl;
	}
	return 0;
}

