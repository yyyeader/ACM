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

int pre[N],nxt[N];
bool flag[26];

int main(){
	FAST_IO;
	int n;
	string ans;
	while(cin>>n) {
		for(int i=1;i<=n;i++)
			cin>>pre[i];
		nxt[0]=-1;
		int i=0,j=-1,cnt=0;
		ans="";
		while(i<n){
			memset(flag,false,sizeof(flag));
			while(j!=-1&&j+1!=i+1-pre[i+1]){
				flag[ans[j]-'a']=true;
				j=nxt[j];
			}
			if(j==-1){
				int idx=-1;
				for(int i=0;i<=cnt;i++){
					if(!flag[i]){
						idx=i;
						break;
					}
				}
				if(idx!=-1)
					ans+=char('a'+idx);
				else{
					cnt++;
					ans+=char('a'+cnt);
				}
			}
			else ans+=ans[j];
			i++,j++;
			nxt[i]=j;
		}
		cout<<ans<<endl;
	}
	return 0;
}

