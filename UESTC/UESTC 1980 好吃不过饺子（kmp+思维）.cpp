#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
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

int len1,len2;
int a[N],b[N],sa[N],sb[N],nxt[N];
vector<int>ans;

void getnxt(int *t,int len){
	int i=0,j;
	j=nxt[0]=-1;
	while(i<len){
		while(j!=-1&&t[i]!=t[j])
			j=nxt[j];
		nxt[++i]=++j;
	}
}

void kmp(int *s,int *t){
	getnxt(t,len2);
	int i=0,j=0;
	while(i<len1){
		while(j!=-1&&s[i]!=t[j])
			j=nxt[j];
		i++,j++;
		if(j==len2){
			ans.push_back(i-len2);
			j=nxt[j];
		}
	}
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<m;i++) scanf("%d",&b[i]);
		for(int i=0;i<n-1;i++) sa[i]=a[i+1]-a[i];
		for(int i=0;i<m-1;i++) sb[i]=b[i]-b[i+1];
		ans.clear();
		len1=n-1,len2=m-1;
		kmp(sa,sb);
		sort(ans.begin(),ans.end());
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++){
			if(i==ans.size()-1)
				printf("%d\n",ans[i]);
			else
				printf("%d ",ans[i]);
		}
	}
	return 0;
}

