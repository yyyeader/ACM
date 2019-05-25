#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<string>
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
const int N=5e6+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

char str[N];

map<string,int>mp;

int main(){
	while(gets(str)){
		if(str[0]=='#') break;
		mp.clear();
		string tmp;
		int len=strlen(str);
		str[len]=' ';
		int ans=0;
		for(int i=0;i<=len;i++){
			if(str[i]==' '){
				if(tmp!=""&&mp.find(tmp)==mp.end()){
					mp[tmp]=++ans;
				}
				tmp="";
			}
			else
				tmp+=str[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

