#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define LL long long
using namespace std;
const int N=2e5+5;

int a[N],f[N];

struct node{
	int pos,num;
}b[N];

bool cmp(node a,node b){
	return a.num>b.num;
}

int main(){
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i],b[i].num=a[i],b[i].pos=i;
	sort(b+1,b+1+n,cmp);
	LL sum=0,cnt=0;
	#给前m*k个打上标记 
	for(int i=1;i<=m*k;i++)
		f[b[i].pos]=true,sum+=b[i].num;
	cout<<sum<<endl;
	#只取前m*k个 
	for(int i=1;i<=n;i++){
		if(f[i])
			cnt++;
		if(cnt==m){
			cnt=0;
			k--;
			if(k!=0)
				cout<<i<<" ";
		}
	}
	return 0;
}
