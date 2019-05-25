#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=2e5;

struct node{
	int cnt,id;
	node(){}
	node(int id,int cnt):id(id),cnt(cnt){}
};

int a[N];
int path[N];
map<int,node>mp;

void print(int x){
	if(x!=-1){
		print(path[x]);
		cout<<x<<" ";
	}
}

int main(){
	memset(path,-1,sizeof(path));
	FAST_IO;
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1,idx=1;
	for(int i=1;i<=n;i++){
		int pre=a[i]-1,now=a[i];
		if(mp.find(now)==mp.end()){
			mp[now]=node(i,1);
		}
		if(mp.find(pre)==mp.end()) continue;
		if(mp[now].cnt<mp[pre].cnt+1){
			mp[now]=node(i,mp[pre].cnt+1);
			path[i]=mp[pre].id;
			if(mp[now].cnt>ans){
				ans=mp[now].cnt;
				idx=i;
			}
		}
	}
	cout<<ans<<endl;
	print(idx);
	cout<<endl;
	return 0;
}
