#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<cctype>
#include<math.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
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
const LL INF64=1e18;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int n,m;
int step[105][3];
bool flag[105];
string str[105];

int judge(char ch){
	if(isdigit(ch))
		return 0;
	if(isalpha(ch))
		return 1;
	if(ch=='#'||ch=='*'||ch=='&')
		return 2;
}

int find(int type){
	int mmin=INF,idx=0;
	for(int i=0;i<n;i++){
		if(step[i][type]<mmin&&!flag[i]){
			mmin=step[i][type];
			idx=i;
		}
	}
	flag[idx]=true;
	return mmin;
}


int main(){
	FAST_IO;
	memset(step,0x3f,sizeof(step));
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	int lim=(m+1)/2;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char ch=str[i][j];
			int t=judge(ch);
			int st;
			int idx=j+1;
			if(idx<=lim)
				st=idx-1;
			else
				st=m-idx+1;
			step[i][t]=min(step[i][t],st);
		}
	}
	int ans=find(0)+find(1)+find(2);
	cout<<ans<<endl;
	return 0;
}
