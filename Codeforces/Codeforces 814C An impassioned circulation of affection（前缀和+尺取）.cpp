#include<bits/stdc++.h>
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
const int N=1e6+5;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

int n;
int sum[30][N],len[30];//sum[i][j]表示字符串str中前j个字母i之间非i的字母数量，即前j个字母i间的间隔之和 

//尺取,求出满足sum[ch-'a'][en]-sum[ch-'a'][st]<=m的情况下最大的en-st+1再+m 
int cal(char ch,int m){
	int t=ch-'a';
	if(m+len[t]>=n)
		return n;
	if(len[t]<=1)
		return len[t]+m;
	int st=1,en=1,ans=1;
	while(en<len[t]){
		en++;
		int tmp=sum[t][en]-sum[t][st];
		while(tmp>m){
			st++;
			tmp=sum[t][en]-sum[t][st];
		}
		ans=max(ans,en-st+1+m);
	}
	return ans;
}

int main(){
	FAST_IO;
	string str;
	cin>>n;
	cin>>str;
	for(int i=0;i<26;i++){
		char ch=i+'a';
		int cnt=-1;
		for(int j=0;j<str.length();j++){
			if(str[j]==ch){
				if(cnt!=-1)
					sum[i][len[i]+1]=sum[i][len[i]]+cnt;
				len[i]++;
				cnt=0;
			}
			else{
				if(cnt!=-1)
					cnt++;
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		char ch;
		int m;
		cin>>m>>ch;
		cout<<cal(ch,m)<<endl;
	}
	return 0;
}

